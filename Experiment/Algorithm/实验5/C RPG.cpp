#include<bits/stdc++.h>
using namespace std;

const int N = 30;
struct boss
{
	int dps;
	int hp;
};

boss a[N];
bool cmp(boss x, boss y)
{
	return x.dps * y.hp > y.dps * x.hp;
}

int main()
{
	int n;
	while(cin >> n)
	{
		int attack = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i].dps >> a[i].hp;
			attack += a[i].dps;
		}
		sort(a, a + n, cmp);
		int last = 0;
		for(int i = 0; i < n; i++)
		{
			last += attack * a[i].hp;
			attack -= a[i].dps; 
		}
		cout << last << endl;
	}
	return 0;
}
