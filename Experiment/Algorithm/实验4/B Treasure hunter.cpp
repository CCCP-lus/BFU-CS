#include<bits/stdc++.h>
using namespace std;

int ilands[1005][1005];
int max_value[1005][1005];

void calculate(int n);

int main()
{
	int t; cin >> t;
	while(t--)
	{
		memset(ilands, 0, sizeof(ilands));
		memset(max_value, 0, sizeof(max_value));
		int n; cin >> n;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(j <= i)
					cin >> ilands[i][j];
			}
		}
		calculate(n);
		int result = *max_element(max_value[n - 1], max_value[n - 1] + n);
		cout << result << endl;
	}
	
	return 0;
}

void calculate(int n)
{
	max_value[0][0] = ilands[0][0];
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			//特判最左 
			if(!j)
				max_value[i][j] = max_value[i - 1][j] + ilands[i][j];
			//特判最右 
			else if(j == n - 1)
				max_value[i][j] = max_value[i - 1][j - 1] + ilands[i][j];
			else
				max_value[i][j] = max(max_value[i - 1][j] + ilands[i][j], max_value[i - 1][j - 1] + ilands[i][j]);
		}
	}
}
