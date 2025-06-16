#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1);

class Shape 
{
public:
	Shape() {}
	virtual double area() = 0;
	virtual void input() = 0;
	virtual double volume() = 0;
	virtual ~Shape() {}
};
//虚 
class Cylinder : public Shape//圆柱体类 
{
private:
	double r;
	double h;
public:
	Cylinder();
	double area();
	void input();
	double volume();
	~Cylinder();
};

class Cuboid : public Shape//长方体类 
{
private:
	double a;
	double b;
	double c;
public:
	Cuboid();
	double area();
	void input();
	double volume();
	~Cuboid();
};

class Ball : public Shape//球类 
{
private:
	double R;
public:
	Ball();	
	double area();
	void input();
	double volume();
	~Ball();	
};

Cylinder::Cylinder() : Shape()
{
	
}

double Cylinder::area()
{
	return (2 * PI * pow(r, 2) + 2 * PI * r * h);
}

void Cylinder::input()
{
	cin >> r >> h;
}

double Cylinder::volume()
{
	return(PI * pow(r, 2) *h);
}

Cylinder::~Cylinder()
{
	
}

Cuboid::Cuboid() : Shape()
{
	
}

double Cuboid::area()
{
	return 2 * (a * b + b * c + c*a);
}

void Cuboid::input()
{
	cin >> a >> b >> c;
}

double Cuboid::volume()
{
	return a * b * c;
}

Cuboid::~Cuboid()
{
	
}

Ball::Ball() : Shape()
{
	
}

double Ball::area()
{
	return 4 * PI *pow(R, 2);
}

void Ball::input()
{
	cin >> R;
}

double Ball::volume()
{
	return (4.0/3) * PI * pow(R, 3);
}

Ball::~Ball()
{
	
}

void work(Shape *s) 
{
	s->input();
	cout << s->area() << " " << s->volume() << endl;
	delete s;
}

int main() 
{
	char c;
	while (cin >> c) 
	{
		switch (c) 
		{
			case 'y':
				work(new Cylinder());
				break;
			case 'c':
				work(new Cuboid());
				break;
			case 'q':
				work(new Ball());
				break;
			default:
				break;
		}
	}
	return 0;
}
