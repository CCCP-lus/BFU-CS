#include<bits/stdc++.h>
using namespace std;

int psum[100005];

//根据补码计算最后一位1 
int lowbit(int x)
{
	return -x & x;
}

//x到n加k 
void add(int x, int k, int n)
{
	while(x <= n)
	{
		psum[x] += k;
		x += lowbit(x);
	}
}

//树状数组求和 
int query(int x)
{
	int s = 0;
	while(x > 0)
	{
		s += psum[x];
		x -= lowbit(x);
	}
	return s;
}

//通过树状数组实现 
int main()
{
    int t;
    int num = 1;
    cin >> t;
    while (t--)
    {
        memset(psum, 0, sizeof(psum));
        int n;
        cin >> n;
        string s;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            add(i, x, n);
        }
        cout << "Case " << num << ":" << endl;
        while (cin >> s && s != "End")
        {
            if (s == "Add")
            {
                int x, y;
                cin >> y >> x;
                add(x, y, n);
            }
            else if (s == "Sub")
            {
                int x, y;
                cin >> y >> x;
                add(x, -y, n);
            }
            else//Query 
            {
                int x, y;
                cin >> x >> y;
                cout << query(y) - query(x - 1) << endl;
            }
        }
        num++;
    }	
	
	return 0;
}
