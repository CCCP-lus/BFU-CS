#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

void Alpha(char a)//�Զ��庯���ж���ĸ 
{
	int flag = 0;
	if(a >= 'A' && a <= 'Z') flag = 2;
	if(a >= 'a' && a <= 'z') flag = 1;
	//������� 
	if(flag == 1)
		printf("%c����ĸ���е�λ�ã�%d\n", a, a - 96);
	if(flag == 2)
		printf("%c����ĸ���е�λ�ã�%d\n", a, a - 64);
	if(flag == 0 && a != 26)
		printf("%c������ĸ��\n", a);
}

int main()
{
	char a;
	while((a = getchar() )!= EOF)//���� 
	{
		Alpha(a);//���ú��� 
	}
	return 0;
}
