from matrix import *
from vector import *
from rational import *

def tests():
    r1 = Rational(1, 3)
    r2 = Rational(4, 3)
    r3 = Rational(5, 6)
    r4 = Rational(1, 2)

    m1 = Matrix(Rational(1, 2), Rational(1, 3), Rational(-2, 7), Rational(2, 8))
    m2 = Matrix(Rational(-1, 3), Rational(2, 7), Rational(2, 5), Rational(-1, 7))
    m3 = Matrix(Rational(1, 5), Rational(2, 3), Rational(2, 9), Rational(4, 7))
    v1 = Vector(Rational(4, 5), Rational(-1, 2))

    print("___________________________________________________________________")
    print("Matrix multiplication:")
    print('\n')
    print(m1 @ m2)
    print("___________________________________________________________________")
    print("Matrix inverse:")
    print('\n')
    print(m1.inverse())
    print("___________________________________________________________________")
    print("Matrix multiplication is associative:")
    print('\n')
    print((m1@m2)@m3 - m1@(m2@m3))
    print("___________________________________________________________________")
    print("Matrix multiplication with addition is distributive:")
    print('\n')
    print(m1@(m2+m3) - (m1@m2 + m1@m3))
    print((m1+m2)@m3 - (m1@m3 + m2@m3))
    print("___________________________________________________________________")
    print("Matrix multiplication corresponds to composition:")
    print('\n')
    print(m1(m2(v1)) - (m1@m2)(v1))
    print('\n')
    print("___________________________________________________________________")
    print("Determinants commute over multiplication:")
    print('\n')
    print(m1.determinant()*m2.determinant() - (m1@m2).determinant())
    print("___________________________________________________________________")
    print("Inverse of a matrix:")
    print('\n')
    print(m1@m1.inverse())
    print(m1.inverse()@m1)
    print("___________________________________________________________________")
