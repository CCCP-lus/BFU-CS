#include<iostream>
#include<cstring>
#define MAXSIZE 100
using namespace std;
void Reverse(char *a,int n)
{//�ݹ�ʵ���ַ���������洢
	if((int)strlen(a) / 2 == n)
		return ;
	else
	{
		char t;
		t = a[n - 1];
		a[n - 1] = a[(int)strlen(a) - n];
		a[(int)strlen(a) - n] = t;
		Reverse(a, --n);
	}
}

int main()
{
	char a[MAXSIZE];
	while(cin>>a)
	{
		if(strcmp(a,"0")==0) break;
		int i=0;
		while(a[i]!='\0') i++;  //ͳ���ַ���
		Reverse(a,i);
		cout<<a<<endl;  //����ַ�����
	}
	return 0;
}
