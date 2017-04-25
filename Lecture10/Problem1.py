from trapezoid import *
from simpson import *
from math import *
import matplotlib.pyplot as plt

x = []
y = []
a = 0.0
b = 1.0

for i in xrange(2,10,2):
    print 'For n = ' + str(i)
    ans1 = trapezoid(exp,a,b,i)
    print 'Trapezoidal rule = ' + str(ans1)

    ans2 = simpson(exp, a, b, i)
    print 'Simpson = ' + str(ans2)

#ans2 = adaptive_trapezoid(sin, a, b, 0.0001)
#print 'Adaptive trapezoidal rule = ' + str(ans2)




