#include<iostream>
#include<string>
using namespace std;

template<typename T>
T Max(const T & t1, const T & t2){
	return t1>t2 ? t1 : t2;
}

int main(){
	cout<<Max(3,5)<<endl;
	
	string s1("abc"),s2("def");
	cout<<Max(s1,s2)<<endl;
	
//	cout<<Max(3,5.0)<<endl;   //error 不支持隐式类型转换
		
	return 0;
}

+++++++++++++++++

// function templates
#include <iostream>
using namespace std;

template <class T, class U>
bool are_equal (T a, U b)
{
  return (a==b);
}

int main ()
{
  if (are_equal(10,10.0))
    cout << "x and y are equal\n";
  else
    cout << "x and y are not equal\n";
  return 0;
}