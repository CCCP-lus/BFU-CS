#include<bits/stdc++.h>
using namespace std;
 
class TestConstClass 
{
private:
	string str;//�ַ��� 
public:
	string get() const;//��ȡ�ַ��� 
	void set(string &a);//���ַ�����ֵ 
};
 
string TestConstClass::get() const//��ȡ�ַ���
{
	return str;
}
 
void TestConstClass::set(string &a)//���ַ�����ֵ 
{
	str = a;//��ֵ 
}
 
void print (const TestConstClass &tcs) 
{
	cout << tcs.get() << '\n';
}
 
int main() 
{
 
	string tmp;
 
	TestConstClass tcs;
	
	while(cin>>tmp)
	{
 
		tcs.set(tmp);
 
		print(tcs);
 
	}
 
return 0;
 
}
