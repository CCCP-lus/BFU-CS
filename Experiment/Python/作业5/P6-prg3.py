def is_prime(x):
    if x <= 1:
        return False
    for i in range(2, x):
        if x % i == 0:
            return False
    return True

def add_prime(l, r):
    for i in range(l, r + 1):
        if is_prime(i):
            List.append(i)

List = []
L = int(input("Please input your left border: "))
R = int(input("Please input your right border: "))
add_prime(L, R)
Sum = sum(List)
print("The sum of these number is: ", Sum)