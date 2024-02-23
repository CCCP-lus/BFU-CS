#include<bits/stdc++.h>
using namespace std;
 
class TestConstClass 
{
private:
	string str;//×Ö·û´® 
public:
	string get() const;//ÌáÈ¡×Ö·û´® 
	void set(string &a);//¸ø×Ö·û´®¸³Öµ 
};
 
string TestConstClass::get() const//ÌáÈ¡×Ö·û´®
{
	return str;
}
 
void TestConstClass::set(string &a)//¸ø×Ö·û´®¸³Öµ 
{
	str = a;//¸³Öµ 
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
