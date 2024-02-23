#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str; 
	string nstr;
	while(cin >> str)
	{
		nstr = str[0];
		for(int i = 1; i < (int)str.length(); i++)
		{
			if(str[i] != str[i - 1])
				nstr += str[i];
		}
		cout << nstr << endl;
	}
	return 0;
}
