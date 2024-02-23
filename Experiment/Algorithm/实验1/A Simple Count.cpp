#include<bits/stdc++.h>
using namespace std;

//ÅÐ¶¨²»º¬4ºÍ7 
bool no47(int x);

int main()
{
	int n;
	while (cin >> n)
	{
		int total = 0;
		for (int i = 1; i <= n; i++)
		{
			if (no47(i))
				total++;
		}
		cout << total << endl;
	}
	return 0;
}

bool no47(int x)
{
	bool flag = true;
	while (x)
	{
		if (x % 10 == 7 || x % 10 == 4)
			flag = false;
		x /= 10;
	}
	return flag;
}
