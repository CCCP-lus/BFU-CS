#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
struct program
{
	int start;
	int end;
};

program a[1005];

bool cmp(program x, program y)
{
	if(x.start != y.start)
		return x.start > y.start;
	else
		return x.end < y.end;
}

int main()
{
	int n;
	while(cin >> n)
	{
		for(int i = 0; i < n; i++)
			cin >> a[i].start >> a[i].end;
		sort(a, a + n, cmp);
		int cnt = 1;
		int last = a[0].start;
		for(int i = 1; i < n; i++)
		{
			if(a[i].end <= last)
			{
				cnt++;
				last = a[i].start;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
