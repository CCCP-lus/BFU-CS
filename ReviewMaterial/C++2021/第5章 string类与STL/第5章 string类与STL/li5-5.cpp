#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec1(5);
	vector<int>::iterator it1;  //定义整型向量容器的迭代器对象it1
	cout<<"输入5个整数：";
	for(it1 = vec1.begin();it1!=vec1.end();it1++)
		cin>>*it1;
	cout<<"vec1中的元素个数："<<vec1.size()<<endl;
	cout<<"vec1中的元素值分别为：";
	for(it1 = vec1.begin();it1!=vec1.end();it1++)
		cout<<*it1<<" ";
	cout<<"\n\n";

	vector<char> vec2(5);
	vector<char>::iterator it2;  //定义整型向量容器的迭代器对象it1
	cout<<"输入5个字符：";
	for(it2 = vec2.begin();it2!=vec2.end();it2++)
		cin>>*it2;
	cout<<"vec2中的元素个数："<<vec2.size()<<endl;
	cout<<"vec2中的元素值分别为：";
	for(it2 = vec2.begin();it2!=vec2.end();it2++)
		cout<<*it2<<" ";
	cout<<endl;

	return 0;
}