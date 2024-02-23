n = int(input("请输入n："))
tol = int(0)
for i in range(1, n):
   s = str("2" * int(i))
   tol += int(s)
# 上面的代码会由于i的类型问题，不允许转换成int从而报错，只能换用while循环
i = int(1)
while n != 0:
    s = str('2' * i)
    tol += int(s)
    i += 1
    n -= 1
print(tol)