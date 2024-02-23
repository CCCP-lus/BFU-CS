#include<bits/stdc++.h>
using namespace std;

long long a[100005];
long long mcsum[100005];

int main()
{
	int times;
	cin >> times;
	while(times--)
	{
		memset(a, 0, sizeof(a));
		memset(mcsum, 0, sizeof(mcsum));
		long long n;
		cin >> n;
		for(long long int i = 0; i < n; i++)
		{
			cin >> a[i];
//			mcsum[i - 1] = a[i] + mcsum[i - 1];
		}
		mcsum[0] = a[0];
		//暂存最大前缀和 
		long long n_max = mcsum[0];
		for(long long int i = 1; i < n; i++)
		{
			//若前缀和大于0则继续 
			if(mcsum[i - 1] >= 0)
				mcsum[i] = mcsum[i - 1] + a[i];
			//否则重新开始记起 
			else
				mcsum[i] = a[i];
			if(mcsum[i] > n_max)
				n_max = mcsum[i];
		}
		cout << n_max << endl;
	}
	return 0;
}
