#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Point2
{
private:
	T x;
	T y;
public:
	Point2();
	Point2(T, T);
	Point2(const Point2& p);
	Point2<T> & operator=(const Point2& a);
	T getx();
	T gety();
	~Point2();
};

template<typename T>
Point2<T>::Point2()
{
	
}

template<typename T>
Point2<T>::Point2(T a, T b)
{
	x = a;
	y = b;
}

template<typename T>
Point2<T>::Point2(const Point2& p)
{
	x = p.x;
	y = p.y;
}

template<typename T>
Point2<T> & Point2<T>::operator=(const Point2<T>& a)
{
	x = a.x;
	y = a.y;
	return *this;	
}

template<typename T>
T Point2<T>::getx()
{
	return x;
}

template<typename T>
T Point2<T>::gety()
{
	return y;
}

template<typename T>
Point2<T>::~Point2()
{
	
}

template<typename T>
class Line2
{
private:
	Point2<T> p1;
	Point2<T> p2;
public:
	Line2<T>(Point2<T> a, Point2<T> b);
	T Length();
	~Line2();
};

template<typename T>
Line2<T>::Line2(Point2<T> a, Point2<T> b)
{
	p1 = a;
	p2 = b;
}

template<typename T>
T Line2<T>::Length()
{
	T length = 0;
	length += pow(p2.getx() - p1.getx(), 2) + pow(p2.gety() - p1.gety(), 2);
	length = sqrt(length);
	return length;
}

template<typename T>
Line2<T>::~Line2()
{
	
}

int main() 
{
    Point2<double> pt1(1.0, 1.0);
    Point2<double> pt2(3.0, 4.0);
    Line2<double> line(pt1, pt2);
    cout << line.Length() << endl;

    int x1,y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Line2<int> nLine(Point2<int>(x1, y1), Point2<int>(x2, y2));
    cout << nLine.Length()<< endl;

    return 0;
}
