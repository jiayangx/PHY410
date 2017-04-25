from trapezoid import *
from simpson import *
from math import exp



n1 = 1
n2 = 0

while n1 % 2 != 0 :
    n1 = int(raw_input( "Enter number of intervals desired for trapezoidal rule (must be even)" ))

a = 0
b = 1.0
ans1 = trapezoid(exp, a, b, n1)
print 'Trapezoidal rule = ' + str(ans1)

ans2 = adaptive_trapezoid(exp, a, b, 0.0001)
print 'Adaptive trapezoidal rule = ' + str(ans2)

ans3 = simpson(exp, a, b, n1)
print "Simpson's rule = " + str(ans3)
