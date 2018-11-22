from numbers import *

def gcd(n1, n2):
    if n1 == 0:
        return n2
    elif n2 == 0:
        return n1
    elif n1 == 0 and n2 == 0:
        raise ArithmeticError("gcd(0,0) does not exist.")
    else:
        return gcd(n2 % n1, n1)

class Rational(Number):
    def __init__(self, num, denum = 1):
        self.num = num
        self.denum = denum
        self.normalize()

    def __repr__(self):
        if self.denum == 1:
            return '{}'.format(self.num)
        else:
            return '{}/{}'.format(self.num, self.denum)

    def normalize(self):
        gc = gcd(self.num, self.denum)
        if gc < 0:
            gc *= -1
        if self.denum < 0:
            self.denum *= -1
            self.num *= -1
        if gc != 1:
            self.denum //= gc
            self.num //= gc

    def __neg__(self):
        return Rational(self.num * (-1), self.denum)

    def __add__(self, other):
        if not isinstance(other, Rational):
            return Rational(self.num + self.denum * other, self.denum)
        else:
            return Rational(self.num * other.denum + other.num * self.denum, self.denum * other.denum)

    def __sub__(self, other):
        if not isinstance(other, Rational):
            return Rational(self.num - self.denum * other, self.denum)
        else:
            return Rational(self.num * other.denum - other.num * self.denum, self.denum * other.denum)

    def __radd_(self, other):
        return self + other;

    def __rsub_(self, other):
        return -(self-other)

    def __mul__(self, other):
        if not isinstance(other, Rational):
            return Rational(self.num * other, self.denum)
        else:
            return Rational(self.num * other.num, self.denum * other.denum)

    def __truediv__(self, other):
        if not isinstance(other, Rational):
            return Rational(self.num, self.denum * other)
        else:
            return Rational(self.num * other.denum, self.denum * other.num)

    def __rmul__(self, other):
        return self * other

    def __rtruediv__(self, other):
        if not isinstance(other, Rational):
            return Rational(self.denum * other, self.num)
