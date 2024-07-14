#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
 
void mystrcat(char *s1, char *s2, char *new_s)
{
	int i, b, t;
	b = strlen(s2);
	for(i = 0; i < b / 2; i++)
	{
		t = *(s2 + i);
		*(s2 + i) = *(s2 + b - i - 1);
		*(s2 + b - i - 1) = t;
	}//调换s2中非空字符顺序 
	for(i = 0; i < 18; i++)
	{
		if(i % 2 == 0)
		{
			new_s[i] = *s1;
			s1++;
		}
		else
		{
			new_s[i] = *s2;
			s2++;
		}
	}//交叉连接 
	for(i = 0; i < 18; i++)//<18防越界 
		if(*(new_s + i) != 0)
			printf("%c", *(new_s + i));//输出 
}

int main()
{
	int i;
	char s1[10] = {'\0'}, s2[10] = {'\0'}, s3[20] = {'\0'};
	//Key Step:提前初始化可以免去后续追加'\0' 
	gets(s1); gets(s2);//输入 
	if(strlen(s1)>9 || strlen(s2) >9)
	{
		printf("cin again:\n");
		for(i = 0; i < 10; i++)
		{
			s1[i] = '\0'; s2[i] = '\0';
		}
		gets(s1); gets(s2);
	}//防止越界 
	char *p1 = s1, *p2 = s2, *p3 = s3;
	mystrcat(p1, p2, p3);
	return 0;
}
