import timeit
from scipy import *
from scipy.linalg import *

'''
 ____________________________________________________________________________________________________
|Errors table    |        h = 10^(-3)        |       h = 2 * 10^(-3)     |      h = 4 * 10^(-3)      |
|________________|___________________________|___________________________|___________________________|
|1.Euler's method|                           |                           |                           |
|                |[-0.00304834 -0.00497444]  |[-0.00608604 -0.00992802]  |[-0.01212979 -0.01977312]  |
|________________|___________________________|___________________________|___________________________|
|2.Heun's method |[-1.03556852e-06           |[-4.13730925e-06           |[-1.65094891e-05           |
|                |-1.38790976e-06]           |-5.54565811e-06]           |-2.21345750e-05]           |
|________________|___________________________|___________________________|___________________________|
|3.Standard RK   |[-1.67421632e-13           |[-2.66120459e-12           |[-4.24467128e-11           |
|                |-2.38031816e-13]           |-3.72901710e-12]           |-5.95541394e-11]           |
|________________|___________________________|___________________________|___________________________|

Speed comparison(C++ vs Python):
______________________________________________________

  1. h = 10^(-3) and usage of Euler's method
    C++ speed: 0.001s
    Python speed: 0.0157s

  2. h = 2 * 10^(-3) and usage of Heun's method
    C++ speed: 0.004s
    Python speed: 0.0167s

  3. h = 4 * 10^(-3) and usage of Standard Runge-Kutta
    C++ speed: 0.004s
    Python speed: 0.0182s
______________________________________________________
'''


# runge_kutta1 is Euler's method:
def runge_kutta1(F, x, h):
   k1 = F(x)
   return x + h * k1

# runge_kutta21 is Heun's method:
def runge_kutta21(F, x, h):
    k1 = F(x)
    k2 = F(x + h * k1)
    return x + h * (0.5 * k1 + 0.5 * k2)

def runge_kutta22(F, x, h):
    k1 = F(x)
    k2 = F(x + 0.5 * h * k1)
    return x + h * k2

def runge_kutta31(F, x, h):
    k1 = F(x)
    k2 = F(x + h * (2.0/3.0) * k1)
    k3 = F(x + h * ((1.0/3.0) * k1 + (1.0/3.0) * k2 ))
    return x + h * ((1.0/4.0) * k1 + (3.0/4.0) * k3 )

# runge_kutta41 is Standard Runge-Kutta
def runge_kutta41(F, x, h):
    k1 = F(x)
    k2 = F(x + 0.5 * h * k1)
    k3 = F(x + 0.5 * h * k2)
    k4 = F(x + h * k3)
    return x + (1.0/6.0) * h * (k1 + 2.0 * k2 + 2.0 * k3 + k4)

def runge_kutta4_kuntzmann(F, x, h):
    k1 = F(x);
    k2 = F(x + h * (2.0/5.0) * k1)
    k3 = F(x + h * ((-3.0/20.0) * k1 + (3.0/4.0) * k2 ))
    k4 = F(x + h * ((19.0/44.0) * k1 + (-15.0/44.0) * k2 + (40.0/44.0) * k3));
    return x + h * ((55.0/360.0) * k1 + (125.0/360.0) * k2 + (125.0/360.0) * k3 + (55.0/360.0) * k4)


def approx( h = 1.0E-3 ) :
   print( "testing Runge-Kutta methods on the catenary" )

   x0 = 0.0
   x1 = 1.0

   mu = 2.0

   s0 = array( [ 1.0 / mu, 0.0 ] )

   p = s0
   x = x0

   def cat( p ) :
      return array( [ p[1], mu * sqrt( 1.0 + p[1] * p[1] ) ] )

   while x + h < x1 :
      p = runge_kutta1( cat, p, h )
      x += h

   p = runge_kutta1( cat, p, x1 - x )
   x = x1

   print( "h = ", h )
   print( "final value = ", p )

   expected = array( [ cosh( mu * x1 ) / mu, sinh( mu * x1 ) ] )
   error = p - expected

   print( "error = ", error )

def approx_time():
    SETUP_CODE = "from alinur import approx"
    TEST_CODE = "approx()"
    NUMBER = 20
    times = timeit.timeit(stmt = TEST_CODE, setup = SETUP_CODE, number = NUMBER)/NUMBER
    print(times)
