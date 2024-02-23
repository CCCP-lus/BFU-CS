#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
long long num[N];
long long a[N];
long long s[N];
bool mark[N];
long long n, k;

long long P(long long v);
long long divide(long long l, long long r);
void dividing(long long ans);

int main()
{
	while(cin >> n >> k)
	{
		memset(a, 0, sizeof(a));
		memset(num, 0, sizeof(num));
		for(long long i = 0; i < n; i++)
			cin >> num[i];
		a[0] = num[0];
		long long maxn = a[0];
		long long sum = a[0];
		for(long long i = 1; i < n; i++)
		{
			a[i] = num[i] - num[i - 1];
			maxn = max(maxn, a[i]);		//二分找最大值左侧 
			sum += a[i];				//二分找最大值右侧 
		}
		dividing(divide(maxn, sum));
	}
	return 0;
}

long long P(long long v)
{
	long long cnt = 1;
	long long sum = 0;
	for(long long i = 0; i < n; i++)
	{
		if(sum + a[i] < v)
			sum += a[i];	//向右 
		else
		{
			sum = a[i];		//更新起点 
			cnt++;
		}
	}
	return cnt;
}

long long divide(long long l, long long r)
{
	while(l < r)
	{
		long long pos = (r - l) / 2 + l;
		if(P(pos) <= k)
			r = pos;
		else
			l = pos + 1;	
	}
	return l;
}

void dividing(long long ans)
{
	memset(mark, 0, sizeof(mark));
	memset(s, 0, sizeof(s));
	long long sum = 0;
	long long cnt = k;
	for(long long i = n - 1; i >= 0; i--)
	{
		//大于最大值或者剩余次数小于划分次数 
		if(sum + a[i] > ans || i + 1 < cnt)
		{
			sum = a[i];
			mark[i] = true;
			cnt--;
		}
		else
			sum += a[i];
	}
	long long k = 1;
	for(long long i = 0; i < n; i++)
	{
		s[k - 1] += a[i];
		if(mark[i])
			k++;
	}
	sort(s, s + k);
	cout << s[k - 1] << endl;
}
