#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for(;n!=1;)
	{
		if(n%2==1)
		{
			n = 3*n+1;
			cnt++;
		}
		else
		{
			n = n/2;
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
 }
