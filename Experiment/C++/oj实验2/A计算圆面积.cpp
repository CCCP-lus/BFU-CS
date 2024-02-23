#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

const double PI = acos(-1.0);//定义PI 

class Circle
{
private:
	double r;
public:
	Circle(double);//输入半径
	double area();//计算面积
	void outarea();//输出面积
};

Circle::Circle(double R)//输入半径
{
	this ->r = R;//对R赋值
}

double Circle::area()//计算面积
{
	return r * r * PI;//圆的面积公式
}

void Circle::outarea()//输出面积
{
	cout << setiosflags(ios::fixed) << setprecision(2) << area();//按格式输出
}

int main()
{
	double r; cin >> r;
	Circle c1(r);
	c1.outarea();
	return 0;
}
