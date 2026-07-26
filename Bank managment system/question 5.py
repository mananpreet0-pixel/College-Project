class Rational():
    def __init__(self,a,b):
        if b == 0:
           raise ZeroDivisionError("Denominator cannot be zero")
           return
        self.a=a
        self.b=b
    def __add__(self,other):
        num=self.a * other.b + self.b * other.a
        den=self.b * other.b
        return Rational(num, den)
    def __eq__(self,other):
        return self.a * other.b == self.b * other.a
    def display(self):
        print(f"{self.a}/{self.b}")
r1 = Rational(1, 2)
r2 = Rational(2, 4)
r3 = r1 + r2
print("Addition:")
r3.display()
print("Comparison:")
print(r1 == r2)

