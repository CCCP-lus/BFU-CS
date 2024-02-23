#include<bits/stdc++.h>
using namespace std;

//十进制回文数判断 
bool palindrome10(int x);
//十进制转二进制后回文数判断 
bool palindrome2(int x); 

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		for(int i = n; i <= m; i++)
		{
			bool flag = false;
			if(palindrome10(i) && palindrome2(i))
				flag = true;
			if(flag)
				cout << i << endl;
		}
		cout << endl;
	}
	return 0;
}

bool palindrome10(int x)
{
	int a = x;
	int b = 0;
	while(a > 0)
	{
		b = b * 10 + a % 10;
		a /= 10;
	}
	if(b == x)
		return true;
	else	
		return false;
}

bool palindrome2(int x)
{
	int i, temp = x, j = 0, sum = 0;
	int a[50];
	while(x)
	{
		i = x % 2;
		a[j] = i;
		j++;
		x /= 2;
	} 
	j--;	//j归位 
	
	for(int k = 0; k <= j; k++)
		sum += a[k] * pow(2, j - k);
	if(sum - temp == 0)
		return true;
	else
		return false;
}
