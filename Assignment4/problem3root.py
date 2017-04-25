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




print(" tangent search")
x0 = float ( input(" Enter guess x_0 : ") )
#x1 = float ( input(" Enter bracketing guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_tangent(f, h, x0, acc,1000,True)
print str ( answer ) + "\n\n"


print(" ------------------------------------------------")

print(" Algorithms for root of tanh(x)")
print(" ------------------------------------------------")



print(" tangent search")
x0 = float ( input(" Enter guess x_0 : ") )
#x1 = float ( input(" Enter bracketing guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_tangent(g, i, x0, acc,1000,True)
print str ( answer ) + "\n\n"
