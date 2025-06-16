#include<bits/stdc++.h>
using namespace std;

class Vehicle//车类 
{
private:
protected:
	string Name;
	string Color;
public:
	Vehicle(const string&, const string&);
	virtual void display();
};

class Car : public Vehicle//汽车类 
{
private:
	double Num;
public:	
	Car(const string&, const string&, double);
	void display();
	
};

class Truck : public Vehicle//卡车类 
{
private:
	double Wei;
public:	
	Truck(const string&, const string&, double);
	void display();
	
};

Vehicle::Vehicle(const string& name, const string& color)
{
	this ->Name = name;
	this ->Color = color;
}

void Vehicle::display()
{
	cout << "Car name:" << this ->Name << " Car color:" << this ->Color << endl;
}

Car::Car(const string& name, const string& color, double number) : Vehicle(name, color)
{
	this ->Num = number;
}

void Car::display()
{
	cout << "Car name:" << this ->Name << " Car color:" << this ->Color << " Car passager:" << this ->Num << endl;
}

Truck::Truck(const string& name, const string& color, double weight) : Vehicle(name, color)
{
	this ->Wei = weight;
}

void Truck::display()
{
	cout << "Truck name:" << this ->Name << " Truck color:" << this ->Color << " Truck capacity:" << this ->Wei << endl;
}

int main()
{
	Vehicle *p;
	char type;
	char name[110],color[110];
	int pas;
	double cap;
	while(cin>>type)
	{
		cin>>name>>color;
		if(type == 'C')
		{
			cin>>pas;
			Car car(name,color,pas);
			p = &car;
			p->display();
		}
		else if(type == 'T')
		{
			cin>>cap;
			Truck truck(name,color,cap);
			p = &truck;
			p->display();
		}
	}
	return 0;
}
