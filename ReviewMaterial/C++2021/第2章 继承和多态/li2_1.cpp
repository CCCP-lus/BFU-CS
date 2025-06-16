#include <iostream>
using namespace std;

class Rectangle
{
protected:
	int lenghth;
	int width;
public:
	void set1(int l, int w)
	{
		lenghth = l;
		width = w;
	}
};

class Cuboid : public Rectangle
{
private:
	int height;
public:
	void set2(int h)
	{
		height = h;
	}

	void show()
	{
		cout<<"长度："<<lenghth<<endl;
		cout<<"宽度："<<width<<endl;
		cout<<"高度："<<height<<endl;
	}
};

int main()
{
	Cuboid obj;
	obj.set1(20,10);
	obj.set2(5);
	obj.show();
	return 0;
}

++++++++++++

#include<iostream>
using namespace std;

class rectangle{
	private:
		double length;
		double width;
	public:
		rectangle(double l=0.0, double w=0.0);
		void set_length(double);
		void set_width(double);
		double get_length();
		double get_width();
}; 

rectangle::rectangle(double l, double w):length(l),width(w){
}

void rectangle::set_length(double l){
	length = l;
}

void rectangle::set_width(double w){
	width = w;
}

double rectangle::get_length(){
	return length;
}

double rectangle::get_width(){
	return width;
}

class cuboid : public rectangle{
	private:
		double height;
	public:
		cuboid(double l=0.0, double w=0.0, double h=0.0);
		void set_height(double h);
		double get_height();
};

cuboid::cuboid(double l, double w, double h) : rectangle(l,w), height(h){
}

void cuboid::set_height(double h){
	height = h;
}

double cuboid::get_height(){
	return height;
}

int main(){
	cuboid c1;
	c1.set_length(5);
	c1.set_width(4);
	c1.set_height(3);
	cout<<c1.get_length()<<" "<<c1.get_width()<<" "<<c1.get_height()<<"\n";
	
	cuboid c2(10,8,6);
	cout<<c2.get_length()<<" "<<c2.get_width()<<" "<<c2.get_height()<<endl;
	
	return 0;
}
