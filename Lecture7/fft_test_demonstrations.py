import matplotlib.pyplot as plt

from fft import fft
from fft import fft_power

from scipy.optimize import leastsq
import numpy as np

import math
import time

plotfirst = True

if plotfirst == False : 
    # make some fake data as a single-frequency sinusoid

    N = 1024      # number of samples
    f = 10.0      # frequency / N
    m = 0.00      # linear slope, if desired

    # For demonstrations : 
    clip = 0      # "clip" so we can pad with zeros
    window = False # window or not? 
    
    
    x = array([ float(i) for i in xrange(N) ] )
    if window : 
        y = array([ math.sin(-2*math.pi*f* xi / float(N)) *(0.5 - 0.5 * math.cos(2*math.pi*xi/float(N-1)))  + m*xi  for xi in x ])
    else :
        y = array([ math.sin(-2*math.pi*f* xi / float(N)) + m*xi  for xi in x ])

    for i in range(N-clip, N) :
        y[i] = 0.0

    start_time = time.time()
    Y = fft(y)
    print time.time() - start_time, " seconds" 

    powery = fft_power(Y)
    powerx = array([ float(i) for i in xrange(len(powery)) ] )


    Yre = [math.sqrt(Y[i].real**2 + Y[i].imag**2) for i in xrange(N)]

    s1 = plt.subplot(2, 1, 1)
    plt.plot( x, y )

    s2 = plt.subplot(2, 1, 2)
    s2.set_autoscalex_on(False)
    p1, = plt.plot( powerx, powery )
    p2, = plt.plot( x, Yre )
    s2.legend( [p1, p2], ["Power", "Magnitude"] )
    plt.xlim([0,N/4])
    plt.yscale('log')
    plt.show()

# LOOK HERE
else : 
    # data downloaded from ftp://ftp.cmdl.noaa.gov/ccg/co2/trends/co2_mm_mlo.txt
    print ' C02 Data from Mauna Loa'
    data_file_name = 'co2_mm_mlo.txt'
    file = open(data_file_name, 'r')
    lines = file.readlines()
    file.close()
    print ' read', len(lines), 'lines from', data_file_name

    window = False

    yinput = []
    xinput = []

    for line in lines :
        if line[0] != '#' :
            try:
                words = line.split()
                xval = float(words[2])
#MESSED AROUND HERE           
                yval = float( words[5] )
                yinput.append( yval )
                xinput.append( xval )
            except ValueError :
                print 'bad data:',line


    N = len(yinput)
    log2N = math.log(N, 2)
    if log2N - int(log2N) > 0.0 :
        print 'Padding with zeros!'
        pads = [300.0] * (pow(2, int(log2N)+1) - N)
        yinput = yinput + pads
        N = len(yinput)
        print 'Padded : '
        print len(yinput)
        # Apply a window to reduce ringing from the 2^n cutoff
        if window : 
            for iy in xrange(len(yinput)) :
                yinput[iy] = yinput[iy] * (0.5 - 0.5 * math.cos(2*math.pi*iy/float(N-1)))

    y = np.array( yinput ) 
    x = np.array([ float(i) for i in xrange(len(y)) ] )
    Y = fft(y)

    powery = fft_power(Y)
    powerx = np.array([ float(i) for i in xrange(len(powery)) ] )

    Yre = [math.sqrt(Y[i].real**2+Y[i].imag**2) for i in xrange(len(Y))]

#WHAT DID I DO

logx = float( math.log10(xval) )
logy = float ( math.log10(yval))

# define our (line) fitting function
fitfunc = lambda p, x: p[0] + p[1] * x + p[2] * x * x  
errfunc = lambda p, x, y, err: (y - fitfunc(p, x)) / err

pinit = [1.0, -1.0]
out = leastsq(errfunc, pinit,
                       args=(logx, logy), full_output=1)

pfinal = out[0]
covar = out[1]
print pfinal
print covar

index = pfinal[1]
amp = 10.0**pfinal[0]

indexErr = sqrt( covar[0][0] ) 
ampErr = sqrt( covar[1][1] ) * amp

##########
# Plotting data
##########

#clf()
#subplot(2, 1, 1)
#plot(xdata, powerlaw(xdata, amp, index))     # Fit
#errorbar(xdata, ydata, yerr=yerr, fmt='k.')  # Data
#text(5, 6.5, 'Ampli = %5.2f +/- %5.2f' % (amp, ampErr))
#text(5, 5.5, 'Index = %5.2f +/- %5.2f' % (index, indexErr))
#title('Best Fit Power Law')
#xlabel('X')
#ylabel('Y')
#xlim(1, 11)

#subplot(2, 1, 2)
#loglog(xdata, powerlaw(xdata, amp, index))
#errorbar(xdata, ydata, yerr=yerr, fmt='k.')  # Data
#xlabel('X (log scale)')
#ylabel('Y (log scale)')
#xlim(1.0, 11)

#savefig('power_law_fit.png')

#WHEW OVER WITH

plt.subplot(2, 1, 1)
plt.plot( x, y )
ax = plt.subplot(2, 1, 2)
p1, = plt.plot( powerx, powery )
p2, = plt.plot( x, Yre )
ax.legend( [p1, p2], ["Power", "Magnitude"] )
plt.yscale('log')


plt.show()
