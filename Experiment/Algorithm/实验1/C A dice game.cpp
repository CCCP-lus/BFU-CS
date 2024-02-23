#include<bits/stdc++.h>
using namespace std;

//½á¹ûÅÐ¶Ïº¯Êý 
int result(int a, int b, int x);

int main()
{
	int a, b;
	while(cin >> a >> b)
	{
		int win = 0, draw = 0, lose = 0;
		for(int i = 1; i <= 6; i++)
		{
			switch (result(a, b, i)) 
			{
				case -1:
					lose++;
					break;
				case 0:
					draw++;
					break;
				case 1:
					win++;
					break;
			}
		}
		cout << win << " " << draw << " " << lose << endl;
	}
	return 0;
}

int result(int a, int b, int x)
{
	if(abs(a - x) < abs(b - x))
		return 1;
	else if(abs(a - x) == abs(b - x))
		return 0;
	else
		return -1;
}
