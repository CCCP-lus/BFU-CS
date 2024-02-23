#include<bits/stdc++.h>
using namespace std;

const int Value[7] = {100, 50, 20, 10, 5, 2, 1};

int main()
{
	int times; cin >> times;
	while(times--)
	{
		int money; cin >> money;
		int ans[7] = {0};
		int cnt = 0;
		for(int i = 0; i < 7; i++)
		{
			ans[i] = money / Value[i];
			money -= ans[i] * Value[i];
		}
		
		for(int i = 0; i < 7; i++)
			cnt += ans[i];
		cout << cnt << endl;
	}
	return 0;
}
