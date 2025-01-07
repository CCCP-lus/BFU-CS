#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
//这是朴实无华且枯燥的红题 
int main()
{
	double i, flag = 1, sum = 0.0;//flag标记符号，记得用double防炸 
	for(i = 1; i <= 100; i++)
	{
		sum += (1 / i) * flag;//算ai并加入sum中 
		flag *= -1;//Key Step：改变下一个数的符号 
	}
	printf("The answer is %lf",sum);//朴实无华且枯燥的输出 
	return 0;
}
