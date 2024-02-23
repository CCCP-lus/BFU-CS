import random

a = random.randint(0, 100)
b = random.randint(0, 100)

if a > b:
    a, b = b, a

gcd = 1
for i in range(1, a + 1):
    if (a % i == 0) and (b % i == 0):
        gcd = i
lcm = a * b / gcd
print("a is %d, b is %d" %(a, b))
print("Greatest common divisor is %d" %gcd)
print("Least common multiple is %d" %lcm)
