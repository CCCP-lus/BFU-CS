import pandas

drinks = pandas.read_csv('drinks.csv', keep_default_na = False)

dis = drinks.groupby('continent')['wine_servings'].describe()

print(dis)