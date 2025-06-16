#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str("He world.");
	string ins;
	cout<<"原字符串是："<<str<<endl;
	cout<<"输入要插入的字符串：";
	cin>>ins;
	str.insert(2,ins,0,ins.size());
	cout<<"新字符串是："<<str<<endl;

	return 0;
}