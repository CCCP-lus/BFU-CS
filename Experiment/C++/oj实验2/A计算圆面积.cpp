#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

const double PI = acos(-1.0);//����PI 

class Circle
{
private:
	double r;
public:
	Circle(double);//����뾶
	double area();//�������
	void outarea();//������
};

Circle::Circle(double R)//����뾶
{
	this ->r = R;//��R��ֵ
}

double Circle::area()//�������
{
	return r * r * PI;//Բ�������ʽ
}

void Circle::outarea()//������
{
	cout << setiosflags(ios::fixed) << setprecision(2) << area();//����ʽ���
}

int main()
{
	double r; cin >> r;
	Circle c1(r);
	c1.outarea();
	return 0;
}
