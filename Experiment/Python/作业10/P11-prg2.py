import pandas

drinks = pandas.read_csv('drinks.csv', keep_default_na = False)

print(drinks.head(5))