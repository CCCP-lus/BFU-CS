#include<bits/stdc++.h>
using namespace std;

long long a[100005];
long long n;

bool judge(long long x, long long size);

int main()
{
	while(cin >> n)
	{
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++)
			cin >> a[i];
			
		int l = 0;	
		int r = 100004;	
		while(l < r)
		{
			//防止越界 
			int m = (r - l) / 2 + l;
			
			if(judge(m, n))
				r = m;
			else
				l = m + 1;
		}
		cout << l << endl;		
	}
	
	return 0;
}

bool judge(long long x, long long size)
{
	//让第一个数字尽可能的小 
	long long cnt = a[1] - x;
	for(long long i = 2; i <= size; i++)
	{
		//让当前元素尽可能小 
		long long t = a[i] - x;
		
		if(t <= cnt)
		{
			t = cnt + 1;
			//当前元素最小的情况 
			if(abs(t - a[i]) > x)
				return false;
		}
		
		cnt = t;
	}
	return true;		
}
