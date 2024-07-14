#include <iostream>
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
{//栈初始化
	S.base = new char[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, char e)
{//入栈
	if(S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack& S)
{//出栈返回栈顶元素
	if(S.top == S.base)
		return ERROR;
	char e = *--S.top;
	return e;
}
Status IsPalindrome(SqStack& S, char* t)
{//判断栈的回文字符序列，不等则返回零, 相等则返回1
	char *p = new char[sizeof(t)];
	for(int i = 0; t[i]!= '\0'; i++)
		Push(S, t[i]);
	for(int i = 0; t[i]!= '\0'; i++)
		p[i] = Pop(S);
	bool flag = true;
	for(int i = 0; t[i]!= '\0'; i++)
	{
		if(p[i] != t[i])
		{
			flag = false;
			break;
		}
	}
	p[sizeof(t)] = '\0';
	delete p;
	if(flag) return 1;
	else return 0;
}

int main()
{
  	char t[100];
	while(cin>>t&&t[0]!='0')
	{
		SqStack S;
		InitStack(S);
		if(IsPalindrome(S,t)==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
