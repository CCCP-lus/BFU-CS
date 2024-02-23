import math

a = float(input("Please input your triangle's first edge: "))
b = float(input("Please input your triangle's second edge: "))
c = float(input("Please input your triangle's third edge: "))
li = [a, b, c]
li.sort()
if a * a + b * b < c * c:
    print("These edges cannot compose a triangle!")
else:
    ci = a + b + c
    p = ci / 2
    s = math.sqrt(p * (p - a) * (p - b) * (p - c))
    print("your triangle's circumference is:", ci)
    print("Your triangle's area is:", s)