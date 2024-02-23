#include<bits/stdc++.h>
using namespace std;

int a[1005];
int dp[1005];

int main()
{
	int n;	
	while(cin >> n)
	{
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int sum;
		dp[1] = a[1];
		for(int i = 2; i <= n; i++)
		{
			sum = 0;
			for(int j = 1; j <= n; j++)
			{
				if(a[i] > a[j])
					sum = max(sum, dp[j]);
			}
			dp[i] = a[i] + sum;
		}
		sort(dp + 1, dp + n + 1);
		cout << dp[n] << endl;
	}
	return 0;
}
