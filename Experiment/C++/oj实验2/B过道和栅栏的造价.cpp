#include<bits/stdc++.h>
using namespace std;

//��ʵʹ��һ���Ϳ��Ը㶨 

class Rectangle
{
private:
	double length;//�� 
	double width;//�� 
public:
	Rectangle(double Length = 10., double Width = 5.);
	double Area();//��ȡ��� 
	double Perimeter();//��ȡ�ܳ� 
};

Rectangle::Rectangle(double Length, double Width)//�вι��캯�� 
{
	this ->length = Length;//�Գ���ֵ 
	this ->width = Width; //�Կ�ֵ 
}

double Rectangle::Area()//��ȡ��� 
{
	return this ->length * this ->width;//������㹫ʽ 
}

double Rectangle::Perimeter()//�����ܳ� 
{
	return (2 * (this ->width + this ->length) );//�ܳ����㹫ʽ 
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
