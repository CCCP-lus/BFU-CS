#include<iostream>
#include<string.h>
using namespace std;
int strstr(string s1,string s2)
{//查找子串第一次出现的位置
	int i = 0, j = 0;
	while(i < (int)s1.length() && j < (int)s2.length())
	{
		if(s1[i] == s2[j])
		{
			i++;
			j++;   	
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
   	}
   	if(j >= (int)s2.length()) 
		return i - s2.length();
   	else return -1;
}

using namespace std;

int main()
{
	string s1, s2;
	while(cin>>s1>>s2)
	{
	    if (s1=="0"&&s2=="0") break;
        int pos=strstr(s1,s2);
        cout<<pos<<endl;
	}
	return 0;
}
