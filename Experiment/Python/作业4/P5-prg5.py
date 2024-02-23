s = [9, 7, 8, 3, 2, 1, 5, 6]
ns = [v**2 if v % 2 == 0 else v for v in s]
print(ns)