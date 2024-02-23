#include<bits/stdc++.h>
using namespace std;

//np重新初始化并完成子集的排序 
void Ini_np(int p[], int np[], int n, int l, int r);

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		int *p = new int[1001];
		int *np = new int[1001];
		for(int i = 1; i <= n; i++)
		{
			cin >> p[i];
//			np[i] = p[i];
		}
			
		while(m--)
		{
			int l, r, x;
			cin >> l >> r >> x;
			
			//因为每次排序相互独立，所以必须在小循环中刷新一次
			Ini_np(p, np, n, l, r);
			
			if(p[x] == np[x])
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		delete[] p;
		delete[] np;
	}
	return 0;
}

void Ini_np(int p[], int np[], int n, int l, int r)
{
	for(int i = 1; i <= n; i++)
		np[i] = p[i];
	sort(np + l, np + r + 1);
} 
