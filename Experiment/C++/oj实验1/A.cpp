#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
int main()
{
	int a[5];
	int i,sum=0;
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	printf("%d",sum);
	return 0;
}
