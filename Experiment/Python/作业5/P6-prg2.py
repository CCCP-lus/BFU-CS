def my_max(x, y, z):
    if x >= y and x >= z:
        return x
    if y >= x and y >= z:
        return y
    if z >= x and z >= y:
        return z

a = int(input("Please input your A: "))
b = int(input("Please input your B: "))
c = int(input("Please input your C: "))
Max = my_max(a, b, c)
print("The max of ABC is: ", Max)