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
{//栈的初始化
	S.base = new int[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, int e)
{//入栈
	if(S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack& S)
{//出栈
	if(S.top == S.base) return ERROR;
	int e;
	e = *--S.top;
	return OK;
}
Status GetTop(SqStack S)
{//取栈顶元素
	if(S.top != S.base)
		return *(S.top - 1);
	return ERROR;
}
void InOutS(SqStack& S, int a[], int n)
{//入栈和出栈的基本操作
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
		for(int i=0;i<n;i++) cin>>a[i];  //整数序列
		InOutS(S,a,n);
	}
	return 0;
}
