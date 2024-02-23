#include<bits/stdc++.h>
using namespace std;

long long a[2000005];

int median(int l, int r, int cnt);
int index(int l, int r);

int main()
{
	int times;
	scanf("%d", &times);
	while(times--)
	{
		memset(a, 0, sizeof(a));
		long long n;
		scanf("%lld", &n);
		for(long long i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		printf("%d\n", median(0, n - 1, n / 2));
	}
	return 0;
}

int median(int l, int r, int cnt)
{
	while(true)
	{
		int pos = index(l, r);
		if(pos == cnt) 
			return a[pos];
		else if(pos > cnt)
			r = pos - 1;
		else
			l = pos + 1;
	}
}

int index(int l, int r)
{
	int i = l;
//	int j = r;
	int axis = a[r];
//	while(i < j)
//	{
		for(int k = l; k < r; k++)
			if(a[k] < axis)
			{
				swap(a[k], a[i]);
				i++;
			}
		swap(a[i], a[r]);
//		//从右向左找第一个小于axis的数 
//		while(i < j && a[j] >= axis)
//			j--;
//		//从左向右找第一个大于axis的数 
//		while(i < j && a[i] <= axis)
//			i++;
//		//交换 
//		if(i < j)
//		{
////			swap(a[i], a[j]);
//			long long t = a[i];
//			a[i] = a[j];
//			a[j] = t;
//		}
//	}
//	a[l] = a[i];
//	a[i] = axis;
	return i;
}
