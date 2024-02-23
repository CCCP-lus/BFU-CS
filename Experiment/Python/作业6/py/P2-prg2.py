import math

p = float(input("Please input your principal: "))
r = float(input("Please input your annual interest rate: "))
y = int(input("Please input your number of years: "))

sum = p * math.pow((1 + r), y)

print(str.format("本金利率和为：{0:2.2f}", sum))
