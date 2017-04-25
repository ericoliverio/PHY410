from root_finding import *
from math import *

def f1 ( x ) :
    return tan(x)
def f2 (x) :
    return tanh(x)

print(" Algorithms for root of tan(x)")
print(" ------------------------------------------------")

print(" 1. Bisection")
x0 = float ( input(" Enter root lower limit : ") )
x1 = float ( input(" Enter root upper limit : ") )
acc = float ( input(" Enter accuracy : ") )
answer1 = root_bisection(f1,x0, x1,acc,1000,True)
print  str ( answer1 ) + "\n\n"

print(" 2. Secant search")
x0 = float ( input(" Enter bracketing guess x_0 : ") )
x1 = float ( input(" Enter bracketing guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_secant(f1, x0, x1, acc,1000,True)
print  str ( answer ) + "\n\n"

print(" Algorithms for root of tanh(x)")
print(" ------------------------------------------------")

print(" 1. Bisection")
x0 = float ( input(" Enter root lower limit : ") )
x1 = float ( input(" Enter root upper limit: ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_bisection(f2,x0, x1, acc,1000,True)
print  str ( answer ) + "\n\n"

print(" 2. Secant search")
x0 = float ( input(" Enter bracketing guess x_0 : ") )
x1 = float ( input(" Enter bracketing guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_secant(f2, x0, x1, acc,1000,True)
print  str ( answer ) + "\n\n"






