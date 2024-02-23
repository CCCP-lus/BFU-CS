import math
import numpy

a = int(input("Please input your a: "))
b = int(input("Please input your b: "))
c = int(input("Please input your c: "))
delta = b * b - 4 * a * c

if a == 0 and b == 0:
    print("It has no solution")
elif a == 0 and b != 0:
    print(str.format("It has one real solution: x1 = {0:2.2f}", -c / b))
elif delta == 0:
    print(str.format("It has two equal real solutions: x1 = x2 = {0:2.2f}", -b / (2 * a)))
elif delta > 0:
    print(str.format("It has two unequal real solutions: x1 = {0:2.2f}, x2 = {1:2.2f}", (-b + math.sqrt(delta)) / (2 * a), (-b - math.sqrt(delta)) / (2 * a)))
else:
    x1 = (-b + complex(0, 1) * numpy.sqrt((-1) * delta)) / (2 * a)
    x2 = (-b - complex(0, 1) * numpy.sqrt((-1) * delta)) / (2 * a)
    print(str.format("It has two imaginary roots: x1 = {0:2.2f}, x2 = {1:2.2f}", x1, x2))