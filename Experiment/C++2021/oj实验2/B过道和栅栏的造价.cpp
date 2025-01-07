#include<bits/stdc++.h>
using namespace std;

//其实使用一个就可以搞定 

class Rectangle
{
private:
	double length;//长 
	double width;//宽 
public:
	Rectangle(double Length = 10., double Width = 5.);
	double Area();//获取面积 
	double Perimeter();//获取周长 
};

Rectangle::Rectangle(double Length, double Width)//有参构造函数 
{
	this ->length = Length;//对长赋值 
	this ->width = Width; //对宽赋值 
}

double Rectangle::Area()//获取面积 
{
	return this ->length * this ->width;//面积计算公式 
}

double Rectangle::Perimeter()//计算周长 
{
	return (2 * (this ->width + this ->length) );//周长计算公式 
}

int main()
{
	double l, w;
	cin >> l >> w;
	Rectangle s1(l, w);
	Rectangle s2(l + 3, w + 3);
	cout << 50 * s2.Perimeter() << endl << 240 * (s2.Area() - s1.Area());
	return 0;
}
