#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
//�⻹����ʵ�޻��ҿ���ĺ��� 
//����һ�ְ취��int i��200~300ѭ�������Ǵ�Ҷ������ͺ����ģ���������һ����· 
int main()
{
	int i, j, k;
	printf("Here are the answers:\n");
	for(i = 2; i <= 2; i++)//��λ 
		for(j = 0; j < 10; j++)//ʮλ 
			for(k = 0; k < 10; k++)//��λ 
			{
				if(i + j + k == 12 && i * j * k == 42)
				printf("%d%d%d\n", i, j, k);//��ϳɴ𰸣�������ʵ�޻��ҿ�������  
			}
	return 0;
}
