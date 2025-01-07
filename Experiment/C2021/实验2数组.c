#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
int main()
{
	int a[101], b[205][2] = {0};//a存数据b排序 
	int i, j, t;
	for(i = 0; i < 101; i++)
	{
		scanf("%d", &a[i]);//输入 
		if(a[i] == -1)
		{
			a[i] = 0;
			i--;
			break;
		}
		if(a[i] >= 0) b[a[i]][0]++;//桶排 
		else b[-a[i] + 100][0]++;//Key Step: 从b[101]开始存储负数个数 
		 
	}
	for(i = 0; i <= 100; i++)
		b[i][1] = i;
	for(i = 101; i <=200; i++)
		b[i][1] = 100 - i;
	for(i = 0; i < 201; i++)//冒泡排序 
		for(j = 0; j < 200 - i; j++)
		{
			if(b[j][0] < b[j + 1][0])
			{
				t = b[j][0];
				b[j][0] = b[j + 1][0];
				b[j + 1][0] = t;
				t = b[j][1];
				b[j][1] = b[j + 1][1];
				b[j + 1][1] = t;
			}
		}
	for(i = 0; i < 202; i++)
		if(b[i][0] != 0)
			printf("The num of %d is %d\n", b[i][1], b[i][0]);//输出 
	return 0;
}
