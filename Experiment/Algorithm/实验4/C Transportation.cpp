#include<bits/stdc++.h>
using namespace std;

int weight[1005];
int price[1005];
int take[1005][1005];

int bag(int num, int cap);

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int num, cap;
		cin >> num >> cap;
		for(int i = 1; i <= num; i++)
			cin >> price[i];
		for(int i = 1; i <= num; i++)
			cin >> weight[i];
			
		cout << bag(num, cap) << endl;	
	}
	return 0;
}

int bag(int num, int cap)
{
	for(int i = 1; i <= num; i++)
	{
		for(int j = 1; j <= cap; j++)
		{
			if(weight[i] > j)
				take[i][j] = take[i - 1][j];
			else
				take[i][j] = max(take[i - 1][j], take[i][j - weight[i]] + price[i]);
		}
	}
	return take[num][cap];
}
