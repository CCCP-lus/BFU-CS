import datetime

n = int(datetime.date.today().year)
sName = str(input("Please input your name: "))
year = int(input("Please input your birth year: "))
age = n - year
print("您好！{0}。您{1}岁。" .format(sName, age))