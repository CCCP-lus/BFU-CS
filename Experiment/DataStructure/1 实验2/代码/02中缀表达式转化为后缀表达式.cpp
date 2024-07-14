#include<iostream>
using namespace std;
#define  MAXSIZE  100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct
{
	char *base;
	char *top;
	int stacksize;
}SqStack;
Status InitStack(SqStack &S)
{//初始化栈
	S.base = new char[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack &S, char e)
{//入栈
	if(S.top - S.base == S.stacksize) return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack &S)
{//出栈
	if(S.top == S.base) return ERROR;
	--S.top;
	return OK;
}
char GetTop(SqStack S)
{//取栈顶元素
	if(S.top != S.base)
		return *(S.top - 1);
	else return ERROR;
}
char Precede(char a,char b)
{//比较运算符a和b的优先级
	switch (a) 
	{
		case '+':
		case '-':
			switch (b) 
			{
				case '+':
				case '-':
				case ')':
				case '=':
					return '>';
					break;
				case '*':
				case '/':
				case '(':
					return '<';
					break;
			}
			break;
		case '*':
		case '/':
			switch (b) 
			{
				case '+':
				case '-':
				case '*':
				case '/':
				case ')':
				case '=':
					return '>';
					break;
				case '(':
					return '<';
					break;
			}
			break;		
		case '(':
			switch (b) 
			{
				case '+':
				case '-':
				case '*':
				case '/':
				case '(':
					return '<';
					break;
				case ')':
					return '=';
					break;
			}
			break;
		case ')':
			switch (b) 
			{
				case '+':
				case '-':
				case '*':
				case '/':
				case ')':
				case '=':
					return '>';
					break;
			}
			break;	
		case '=':
			switch (b) 
			{
				case '+':
				case '-':
				case '*':
				case '/':
				case '(':
					return '<';
					break;
				case '=':
					return '=';
					break;
			}
			break;
	}
	return ERROR;
}
void InfixToSuffix(SqStack OPTR,char s[])
{//将中缀表达式转化为后缀表达式并输出 
	char t;
	for(int i = 0; s[i] != '\0'; )
	{
		while(isdigit(s[i]))
		{
			cout << s[i];
			i++;
		}
		switch (Precede(GetTop(OPTR), s[i])) 
		{
			case '<':
				Push(OPTR, s[i]);
				i++;
				break;
			case '>':
				t = GetTop(OPTR);
				Pop(OPTR);
				cout << t;		
				break;
			case '=':
				t = GetTop(OPTR);
				Pop(OPTR);
				i++;
				break;
		}
	} 
	cout << endl;
}

int main()
{
	SqStack OPTR;
	InitStack(OPTR);      //初始化操作符栈OPTR
	Push(OPTR,'=');		//先在栈底放入'='便于以后比较符号优先级	
	char s[100];
	while(cin>>s)
	{
		if(s[0]=='=')
			break;    	//当表达式只有一个“=”时，输入结束 
		else
			InfixToSuffix(OPTR,s); 	//将中缀表达式转化为后缀表达式并输出	
	}
	return 0;
}
