#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num = 1;
	string s, s1, s2, s3, s4, s5, s6;
	while(cin >> s)
	{
		//Insert
		string a;
		int a1;
		cin >> a >> a1;
		if(a1 > 0)
		{
			string sa, sb;
			sa = s.substr(0, a1);
			sb = s.substr(a1, s.size());
			s = sa + a + sb;			
		}
		else
			s = a + s;
		s1 = s;	
		
		//Erase
		char b; cin >> b;	
		for(string::iterator it = s.begin(); it < s.end(); it++)
		{
			if(*it == b)
			{
				s.erase(it);
				it--;
			}
		}
		s2 = s;
		
		//Replace
		char x, y;
		cin >> x >> y;
		replace(s.begin(), s.end(), x, y);
		s3 = s;
		
		//Reverse
		string ss = s;
		reverse(ss.begin(), ss.end());
		s4 = ss;		
		
		//Sub
		int n, m;
		cin >> n >> m;
		s5 = s.substr(n, m - n + 1);		
		
		//Find
		int flag = 0;
		string str; cin >> str;
		if(s.find(str) != s.npos)
			flag = 0;
		else
			flag = 1;
		
		//cout
		cout << "Case " << num << ":" << endl;
		cout << "Insert->" << s1 << endl;
		cout << "Erase->" << s2 << endl;
		cout << "Replace->" << s3 << endl;
		cout << "Size->" << s3.length() << endl;
		cout << "Reverse->" << s4 << endl;
		cout << "Sub->" << s5 << endl;
		if(!flag)
			cout << "Find->" << s.find(str) << endl;
		else 
			cout << "Find->" << "-1" << endl;
		cout << endl;				
		num++;
	}
	
	return 0;
}
