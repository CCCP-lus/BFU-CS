#include<bits/stdc++.h>
using namespace std;

int num = 0;
int queen[11] = {0};

void Queen(int d, int n)
{
	if(d == n + 1)
		num++;
	else
	{
		for(int i = 1; i <= n; i++)
		{
			queen[d] = i;
			bool flag = true;
			for(int j = 1; j < d; j++)
			{
				if(queen[d] == queen[j] || abs(d - j) == abs(queen[d] - queen[j]))
				{
					flag = false;
					break;
				}
			}
			if(flag)
				Queen(d + 1, n);
		}
	}
}

int main()
{
	int n;
	while(cin >> n)
	{
		num = 0;
		Queen(1, n);
		cout << num << endl;
	}
	
	return 0;
}
