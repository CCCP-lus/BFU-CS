#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[1005];
	int n, q;
	while(cin >> n, cin >>q)
	{
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		while(q--)
		{
			int f; cin >> f;
			int p = lower_bound(arr, arr + n, f) - arr;
			if(arr[p] == f)
				cout << f << " found at " << p + 1 << endl;
			else
				cout << f << " not found !" << endl;
		}
	}
	return 0;
}
