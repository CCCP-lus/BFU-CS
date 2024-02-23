import math

def getvalue(b, r, n):
    return b * math.pow((1 + r), n)

bb = float(input("Please input your principal: "))
rr = float(input("Please input your annual interest rate: "))
nn = int(input("Please input your number of years: "))

print(str.format("本金利率和为：{0:2.2f}", getvalue(bb, rr, nn)))