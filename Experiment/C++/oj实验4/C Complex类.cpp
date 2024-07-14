#include<bits/stdc++.h>
using namespace std;

class Complex
{
private:
	double a;
	double b;
public:
	Complex();
	friend istream & operator>>(istream&, Complex&);
	friend ostream & operator<<(ostream&, const Complex&);
	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);
	Complex & operator+=(const Complex&);
	Complex & operator-=(const Complex&);
	Complex & operator*=(const Complex&);
	Complex & operator/=(const Complex&);
	friend bool operator==(const Complex&, const Complex&);
	friend bool operator!=(const Complex&, const Complex&); 
};

Complex::Complex()
{
	
}

istream & operator>>(istream& in, Complex& c)
{
	cin >> c.a >> c.b;
	return in;
}

ostream & operator<<(ostream& out, const Complex& c)
{
	cout << c.a << " + " << c.b << "i";
	return out;
}

Complex operator+(const Complex& x, const Complex& y)
{
	Complex temp;
	temp.a = x.a + y.a;
	temp.b = x.b + y.b;
	return temp;
}

Complex operator-(const Complex& x, const Complex& y)
{
	Complex temp;
	temp.a = x.a - y.a;
	temp.b = x.b - y.b;
	return temp;
}

Complex operator*(const Complex& x, const Complex& y)
{
	Complex temp;
	temp.a = x.a * y.a - x.b * y.b;
	temp.b = x.a * y.b + x.b * y.a;
	return temp;
}

Complex operator/(const Complex& x, const Complex& y)
{
	Complex temp;
	temp.a = (x.a * y.a + x.b * y.b) / (y.a * y.a + y.b * y.b);
	temp.b = (x.b * y.a - x.a * y.b) / (y.a * y.a + y.b * y.b);
	return temp;
}

Complex & Complex::operator+=(const Complex& c)
{
	a += c.a;
	b += c.b;	
	return *this;
}

Complex & Complex::operator-=(const Complex& c)
{
	a -= c.a;
	b -= c.b;	
	return *this;
}

Complex & Complex::operator*=(const Complex& c)
{
	double aa = a, bb = b;
	a = aa * c.a - bb * c.b;
	b = aa * c.b + bb * c.a;	
	return *this;
}

Complex & Complex::operator/=(const Complex& c)
{
	double aa = a, bb = b;
	a = (aa * c.a + bb * c.b) / (c.a * c.a + c.b * c.b);
	b = (bb * c.a - aa * c.b) / (c.a * c.a + c.b * c.b);	
	return *this;
}

bool operator==(const Complex& x, const Complex& y)
{
	return (x.a == y.a && x.b == y.b)? 1: 0;
}

bool operator!=(const Complex& x, const Complex& y)
{
	return (x.a == y.a && x.b == y.b)? 0: 1;
}

int main()
{
    Complex c1, c2;
    cin >> c1 >> c2;
    cout << "c1 = " << c1 << "\n" << "c2 = " << c2 << endl;
    cout << "c1+c2 = " << c1 + c2 << endl;
    cout << "c1-c2 = " << c1 - c2 << endl;
    cout << "c1*c2 = " << c1 * c2 << endl;
    cout << "c1/c2 = " << c1 / c2 << endl;
    cout << (c1 += c2) << endl;
    cout << (c1 -= c2) << endl;
    cout << (c1 *= c2) << endl;
    cout << (c1 /= c2) << endl;
    cout << (c1 == c2) << " " << (c1 != c2) << endl;

    return 0;
}
