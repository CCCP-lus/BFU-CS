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
			//��ֹԽ�� 
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
	//�õ�һ�����־����ܵ�С 
	long long cnt = a[1] - x;
	for(long long i = 2; i <= size; i++)
	{
		//�õ�ǰԪ�ؾ�����С 
		long long t = a[i] - x;
		
		if(t <= cnt)
		{
			t = cnt + 1;
			//��ǰԪ����С����� 
			if(abs(t - a[i]) > x)
				return false;
		}
		
		cnt = t;
	}
	return true;		
}
