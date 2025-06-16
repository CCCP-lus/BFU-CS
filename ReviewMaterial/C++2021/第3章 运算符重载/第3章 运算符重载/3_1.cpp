#include <iostream>
#include <cstdlib>
using namespace std;

class Complex{
private:
	double x;
	double y;
public:
	Complex(double x = 0.0, double y = 0.0);
	friend Complex operator+(const Complex &, const Complex &);
	friend Complex operator-(const Complex &, const Complex &);
	friend ostream & operator<<(ostream &, const Complex &);
	friend istream & operator>>(istream &, Complex &);
};

Complex::Complex(double x, double y) : x(x), y(y){}

Complex operator+(const Complex & c1, const Complex & c2){
	Complex temp;
	temp.x = c1.x + c2.x;
	temp.y = c1.y + c2.y;
	return temp;
}

Complex operator-(const Complex & c1, const Complex & c2){
	Complex temp;
	temp.x = c1.x - c2.x;
	temp.y = c1.y - c2.y;
	return temp;
}

ostream & operator<<(ostream & os, const Complex & c){
	os << c.x << " + " << c.y << "i";
	return os;
}

istream & operator>>(istream & is, Complex & c){
	is >> c.x >> c.y;
	return is;
}


int main(){
	Complex c1(3, 4), c2(5, -6);
	cout << c1 << "\n" << c2 << endl;
	cout << c1 + c2 << endl;
	cout << c1 - c2 << endl;
	Complex c3;
	cin >> c3;
	cout << c3 << endl;

	return 0;
}


+++++++++++++++++++++++++++

#include <iostream>
using namespace std;

class Complex{
private:
	double x, y;
public:
	Complex(double x = 0.0, double y = 0.0) : x(x), y(y){
	}
	
	friend Complex operator+(const Complex &, const Complex &);
	friend Complex operator-(const Complex &, const Complex &);
	friend istream & operator>>(istream &, Complex &);
	friend ostream & operator<<(ostream &, const Complex &);
};

Complex operator+(const Complex & a, const Complex & b){
	return Complex(a.x+b.x, a.y+b.y);
}

Complex operator-(const Complex & a, const Complex & b){
	return Complex(a.x-b.x, a.y-b.y);
}

istream & operator>>(istream & in, Complex & c){
	in>>c.x>>c.y;
	return in;
}

ostream & operator<<(ostream & out, const Complex & c){
	out<<c.x<<" + "<<c.y<<'i';
	return out;
}

int main(){
	Complex a,b;
	cin>>a>>b;
	cout<<(a+b)<<'\n'<<(a-b)<<endl;
		
	return 0;
}
