#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
	return a > b;
}

int main()
{
	int n; cin >> n;
	string s;
	vector<string> v;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		sort(s.begin(), s.end());
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	for(vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << endl;
	}
	return 0;
}
