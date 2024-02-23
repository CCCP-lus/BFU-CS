s = str(input("请输入表达式，操作符和操作数之间用空格隔开："))
l = s.split()
a = float(l[0])
x = l[1]
b = float(l[2])
if x == "+":
    print(a + b)
elif x == "-":
    print(a - b)
elif x == "*":
    print(a * b)
elif x == "/":
    if b == 0:
        print("错误，0不能作为除数")
    else:
        print(a / b)
elif x == "%":
    if b == 0:
        print("错误，0不能作为除数")
    else:
        print(a % b)
else:
    print("输入错误")