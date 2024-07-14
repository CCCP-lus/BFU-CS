#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Vector;

template<typename T>
Vector<T>& operator*(const T& a, const Vector<T>& v);

template<typename T>
Vector<T>& operator+(const Vector<T>& a, const Vector<T>& v);

template<typename T>
bool operator ==(const Vector<T>&, const Vector<T>&);

template<typename T>
istream & operator >>(istream&, Vector<T>&);

template<typename T>
ostream & operator <<(ostream&, Vector<T>&);

template<typename T>
class Vector
{
private:
    T x, y, z;
public:
    Vector<T>(T a = 0, T b = 0, T c = 0);
    Vector<T>(const Vector<T>& v);
    friend Vector<T>& operator *<>(const T& a, const Vector<T>& v);
    friend Vector<T>& operator +<>(const Vector<T>& a, const Vector<T>& v);
	Vector<T>& operator =(const Vector<T>& a);
    friend bool operator ==<>(const Vector<T>&, const Vector<T>&);
    friend istream & operator >> <>(istream&, Vector<T>&);
    friend ostream & operator << <>(ostream&, Vector<T>&);
};

template<typename T>
Vector<T>::Vector(T a, T b, T c)
{
	x = a;
	y = b;
	z = c;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& v)
{
	this ->x = v.x;
	this ->y = v.y;
	this ->z = v.z;
}

template<typename T>
Vector<T>& operator*(const T& a, const Vector<T>& v)
{
	static Vector<T> temp;
	temp.x = a * v.x;
	temp.y = a * v.y;
	temp.z = a * v.z;
	return temp;
}

template<typename T>
Vector<T>& operator+(const Vector<T>& a, const Vector<T>& v)
{
	static Vector<T> temp;
	temp.x = a.x + v.x;
	temp.y = a.y + v.y;
	temp.z = a.z + v.z;
	return temp;
}

template<typename T>
Vector<T>& Vector<T>::operator =(const Vector<T>& a)
{
	this ->x = a.x;
	this ->y = a.y;
	this ->z = a.z;
	return *this;
}

template<typename T>
bool operator==(const Vector<T>& a, const Vector<T>& b)
{
	return (abs(a.x - b.x) < 1e-8 && abs(a.y - b.y) < 1e-8 && abs(a.z - b.z) < 1e-8)? true: false;
}

template<typename T>
istream & operator >>(istream& in, Vector<T>& v)
{
	cin >> v.x >> v.y >> v.z;
	return in;
}

template<typename T>
ostream & operator <<(ostream& out, Vector<T>& a)
{
	cout << a.x << " " << a.y << " " << a.z;
	return out;
}



int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;
    Vector<double> v1(a, b, c), v2(v1), v3, v4;
    double d;
    std::cin >> d;
    v4 = d * v1 + v2;

    std::cout << v4 <<std::endl;

    Vector<double>  v;
    std::cin >> v;

    int flag = (v4 == v);
    std::cout << flag << std::endl; 

    return 0;
}
