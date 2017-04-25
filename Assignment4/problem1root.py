from root_finding import *
from math import *

def f ( x ) :
    return tan(x)
def g ( x ) :
    return tanh(x)
def h ( x ) :
    return pow( cos(x), -2)
def i ( x ) :
    return 1 - pow( g(x), 2)


print(" Algorithms for root of tan(x)")
print(" ------------------------------------------------")

print(" 1. Simple search")
x0 = float ( input(" Enter initial guess x_0 : ") )
dx = float ( input(" Enter step dx : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_simple(f, x0, dx, acc,1000,True)
print  str ( answer ) + "\n\n"

print(" 2. Bisection search")
x0 = float ( input(" Enter bracketing guess x_0 : ") )
x1 = float ( input(" Enter bracketing guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_bisection(f, x0, x1, acc,1000,True)
print str ( answer ) + "\n\n"

print(" 3. secant search")
x0 = float ( input(" Enter bracketing guess x_0 : ") )
x1 = float ( input(" Enter bracketing guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_secant(f, x0, x1, acc,1000,True)
print str ( answer ) + "\n\n"

print(" 4. tangent search")
x0 = float ( input(" Enter guess x_0 : ") )
#x1 = float ( input(" Enter bracketing guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_tangent(f, h, x0, acc,1000,True)
print str ( answer ) + "\n\n"


print(" ------------------------------------------------")

print(" Algorithms for root of tanh(x)")
print(" ------------------------------------------------")

print(" 1. Simple search")
x0 = float ( input(" Enter initial guess x_0 : ") )
dx = float ( input(" Enter step dx : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_simple(g, x0, dx, acc,1000,True)
print  str ( answer ) + "\n\n"

print(" 2. Bisection search")
x0 = float ( input(" Enter bracketing guess x_0 : ") )
x1 = float ( input(" Enter bracketing guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_bisection(g, x0, x1, acc,1000,True)
print str ( answer ) + "\n\n"

print(" 3. secant search")
x0 = float ( input(" Enter bracketing guess x_0 : ") )
x1 = float ( input(" Enter bracketing guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_secant(g, x0, x1, acc,1000,True)
print str ( answer ) + "\n\n"

print(" 4. tangent search")
x0 = float ( input(" Enter guess x_0 : ") )
#x1 = float ( input(" Enter bracketing guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_tangent(g, i, x0, acc,1000,True)
print str ( answer ) + "\n\n"
