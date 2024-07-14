#include <iostream>
#include <cstring>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
using namespace std;
typedef struct
{
    char* base;
    char* top;
    int stacksize;
}SqStack;
Status InitStack(SqStack& S)
{//初始化栈
	S.base = new char[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
    return OK;
}
Status Push(SqStack& S)
{//入栈
	if(S.top - S.base == S.stacksize)
		return ERROR;
	S.top++;
	return OK;
}
Status Pop(SqStack& S)
{//出栈
	if(S.top == S.base) return ERROR;
	S.top--;
	return OK;
}
Status IsEmpty(SqStack S)
{//判断栈是否为空，空返回1，否则返回0
    if(S.top == S.base)	return 1;
    return 0;
}
bool Judge(char a[], SqStack& S)
{//栈的可操作判断
    for(int i = 0; a[i] != '\0'; i++)
    {
		if(a[i] == 'I')
		{
			if(!Push(S)) 
				return false;
		}
		if(a[i] == 'O')
		{
			if(!Pop(S))
				return false;
		}
	}
	if(S.top != S.base)
		return false;
	return true;
}

int main()
{
    char a[100];
    while(cin>>a)
    {
        if(a[0]=='0') break;
        SqStack op;
        InitStack(op);
        if(Judge(a,op)) cout<<"TRUE"<<endl;
        else cout<<"FALSE"<<endl;
    }
    return 0;
}
