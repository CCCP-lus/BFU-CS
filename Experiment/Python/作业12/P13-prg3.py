class Coordinate(object):

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def __str__(self):
        return '<' + str(self.getX()) + ',' + str(self.getY()) + '>'

    def eq(self, other):
        flag = False
        if self.x == other.x and self.y == self.y:
            flag = True
        return flag

    def repr(self):
        print("Coordinate(" + str(self.getX()) + "," + str(self.getY()) + ")")


p1 = Coordinate(1, 8)
print(str(p1))
p1.repr()
p2 = Coordinate(1, 8)

if p1.eq(p2):
    print("p1 == p2")
else:
    print("p1 != p2")