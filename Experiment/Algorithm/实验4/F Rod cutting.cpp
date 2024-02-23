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
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				if(dp[i] < a[j] + dp[i - j])
					dp[i] = a[j] + dp[i - j];
			}
		}
		cout << dp[n] << endl;	
	}
	return 0;
}
