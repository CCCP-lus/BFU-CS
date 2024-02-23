#include<bits/stdc++.h>
using namespace std;

struct point
{
	double x;
	double y;
};
point p[100005];

int num[100005];

double divide(int l, int r, int size);
double distance(point p1, point p2);
bool cmpx(point p1, point p2);
bool cmpy(int p1, int p2);

int main()
{
	int n;
	while(cin >> n)
	{
		memset(num, 0, sizeof(num));
		for(int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		double cnt = divide(0, n - 1, n);
		cout << (int)cnt << endl;	
	}
	return 0;
}

double divide(int l, int r, int size)
{
	//最大距离 
	double n_max = DBL_MAX;
	//终止条件 
	if(l == r)
		return n_max;
	//两个点的特判 
	else if(l + 1 == r)
		return distance(p[l], p[r]);
	//三个点的特判 
	else if(l + 2 == r)
	{
//		double d1 = distance(p[l], p[l + 1]);
//		double d2 = distance(p[l + 1], p[l + 2]);
//		double d3 = distance(p[l + 2], p[l]);
//		return min(min(d1, d2), d3);
		return(min(min(distance(p[l], p[l + 1]), distance(p[l + 1], p[l + 2])), distance(p[l], p[l + 2])));
	}
	else
	{
		//对点按x大小排序 
		sort(p, p + size, cmpx);
		int m = (r - l) / 2 + l;
		int mm = m + 1;
		//二分求解 
		double lm = divide(l, m, size);
		double rm = divide(m + 1, r, size);
		double smaller = min(lm, rm);  
		if(p[mm].x - p[m].x >= smaller)
			return smaller;
		
		int cnt = 0;
		for(int i = l; i <= r; i++)
		{
			if(fabs(p[m].x - p[i].x) < smaller)
				num[cnt++] = i;
		}
		
		sort(num, num + cnt, cmpy);
		for(int i = 0; i < cnt; i++)
		{
			for(int j = i + 1; j <= i + 7 && j < cnt; j++)
			{
				if(p[num[j]].y - p[num[i]].y > smaller)
					break;
				smaller = min(smaller, distance(p[num[i]], p[num[j]]));
			}
		}
		return smaller;
	}	
}

double distance(point p1, point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool cmpx(point p1, point p2)
{
	return p1.x < p2.x;
}

bool cmpy(int a, int b)
{
	return p[a].y < p[b].y;
}
