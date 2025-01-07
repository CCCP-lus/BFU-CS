#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

void Alpha(char a)//自定义函数判断字母 
{
	int flag = 0;
	if(a >= 'A' && a <= 'Z') flag = 2;
	if(a >= 'a' && a <= 'z') flag = 1;
	//按类输出 
	if(flag == 1)
		printf("%c在字母表中的位置：%d\n", a, a - 96);
	if(flag == 2)
		printf("%c在字母表中的位置：%d\n", a, a - 64);
	if(flag == 0 && a != 26)
		printf("%c不是字母！\n", a);
}

int main()
{
	char a;
	while((a = getchar() )!= EOF)//输入 
	{
		Alpha(a);//调用函数 
	}
	return 0;
}
