#include<bits/stdc++.h>
using namespace std;

string ss[105];

int main()
{
	int k = 0;
	string s;
	while(getline(cin, s))
	{
		if(s.empty())
			break;
		ss[k] = s;
		k++;
	}
	
	string str;
	bool flag = false;
	while(cin >> str)
	{
		int j;
		flag = false;
		for(int i = 0; i < k; i++)
		{
			for(j = 0; j < (int)str.length(); j++)
			{
				if(j >= (int)str.length() || str[j] != ss[i][j])
				break;
			}
			if(j >= (int)str.length())
				flag = true;
			if(flag) break;
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
