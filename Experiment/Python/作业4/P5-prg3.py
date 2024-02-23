Str = str(input("Please enter list elements separated by Spaces: "))
List = Str.split()
# nList = range(len(List))
# result = []
# Dict = zip(List, nList)
# print("The result after removing the duplicate result is: ")
# for i in dict(Dict).keys():
#     result.append(i)
# print(result)

List = list(set(List))
print(List)