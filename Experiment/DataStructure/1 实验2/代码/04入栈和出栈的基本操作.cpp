#include<iostream>
using namespace std;
#define  MAXSIZE  100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct
{
	int* base;
	int* top;
	int stacksize;
}SqStack;
Status InitSqStack(SqStack& S)
{//ջ�ĳ�ʼ��
	S.base = new int[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, int e)
{//��ջ
	if(S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack& S)
{//��ջ
	if(S.top == S.base) return ERROR;
	int e;
	e = *--S.top;
	return OK;
}
Status GetTop(SqStack S)
{//ȡջ��Ԫ��
	if(S.top != S.base)
		return *(S.top - 1);
	return ERROR;
}
void InOutS(SqStack& S, int a[], int n)
{//��ջ�ͳ�ջ�Ļ�������
	for(int i = 0; i < n; i++)
	{
		if(a[i] == -1)
		{
			int t = GetTop(S);
			if(S.top == S.base)
			{
				cout << "POP ERROR" << endl;
				break;
			}
			else
			{
				cout << t << endl;
				Pop(S);
			}
		}
		else
		{
			Push(S, a[i]);
		}
	} 
}

int main()
{
	int n;
	while(cin>>n)
	{
      	if(n==0) break;
      	SqStack S;
		InitSqStack(S);
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];  //��������
		InOutS(S,a,n);
	}
	return 0;
}
