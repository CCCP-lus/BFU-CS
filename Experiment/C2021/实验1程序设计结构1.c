#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
//������ʵ�޻��ҿ���ĺ��� 
int main()
{
	double i, flag = 1, sum = 0.0;//flag��Ƿ��ţ��ǵ���double��ը 
	for(i = 1; i <= 100; i++)
	{
		sum += (1 / i) * flag;//��ai������sum�� 
		flag *= -1;//Key Step���ı���һ�����ķ��� 
	}
	printf("The answer is %lf",sum);//��ʵ�޻��ҿ������� 
	return 0;
}
