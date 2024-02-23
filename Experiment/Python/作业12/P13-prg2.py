class Circle:
    PI = 3.14159
    def __init__(self, x, y, l, r, g, b):
        self.x = x
        self.y = y
        self.l = l
        self.r = r
        self.g = g
        self.b = b

    def get_area(self):
        return self.PI * self.l ** 2

    def get_circumference(self):
        return 2 * self.PI * self.l

    def get_color(self):
        if self.r < 0:
            self.r = 0
        if self.g < 0:
            self.g = 0
        if self.b < 0:
            self.b = 0
        if self.r > 255:
            self.r = 255
        if self.g > 255:
            self.g = 255
        if self.b > 255:
            self.b = 255
        return '(' + str(self.r) + ', ' + str(self.g) + ', ' + str(self.b) + ')'

    def get_location(self):
        return '(x: ' + str(self.x) + ', y: ' + str(self.y) + ')'

c1 = Circle(0, 0, 1, 255, 255, 255)
print("c1's location is: "+ str(c1.get_location()))
print("c1's area is: "+ str(c1.get_area()))
print("c1's circumference is: "+ str(c1.get_circumference()))
print("c1's color is: "+ str(c1.get_color()))