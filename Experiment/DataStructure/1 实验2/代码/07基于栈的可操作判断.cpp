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
{//��ʼ��ջ
	S.base = new char[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
    return OK;
}
Status Push(SqStack& S)
{//��ջ
	if(S.top - S.base == S.stacksize)
		return ERROR;
	S.top++;
	return OK;
}
Status Pop(SqStack& S)
{//��ջ
	if(S.top == S.base) return ERROR;
	S.top--;
	return OK;
}
Status IsEmpty(SqStack S)
{//�ж�ջ�Ƿ�Ϊ�գ��շ���1�����򷵻�0
    if(S.top == S.base)	return 1;
    return 0;
}
bool Judge(char a[], SqStack& S)
{//ջ�Ŀɲ����ж�
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
