import math

r = float(input("Please input radius: "))

s = 4 * math.pi * r * r
v = 4 * math.pi * r * r * r / 3

print(str.format("球的表面积为:{0:2.2f}, 体积为:{1:2.2f}", s, v))