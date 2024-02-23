n = int(input("Please input your N: "))
sum = 0
for i in range(1, n + 1):
    sum += 1 / i
print("The sum of 1+1/2+1/3...+1/n is", sum)
