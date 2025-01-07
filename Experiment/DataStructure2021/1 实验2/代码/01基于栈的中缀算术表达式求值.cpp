#include <iostream>
#include<iomanip>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
using namespace std;
typedef struct
{//运算符栈
    char *base;
	char *top;
	int stacksize;
}SqStack1;
Status InitStack1(SqStack1 &S)
{//运算符栈初始化
	S.base = new char[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push1(SqStack1 &S, char e)
{//运算符栈入栈
	if(S.top - S.base == S.stacksize) return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop1(SqStack1 &S)
{//运算符栈出栈
	if(S.top == S.base) return ERROR;
	--S.top;
	return OK;
}
char GetTop1(SqStack1 S)
{//运算符栈取栈顶元素
	if(S.top != S.base)
		return *(S.top - 1);
	return ERROR;	
}
typedef struct
{//操作数栈
	double *base;
	double *top;
	int  stacksize;
}SqStack2;
Status InitStack2(SqStack2 &S)
{//操作数栈初始化
	S.base = new double[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push2(SqStack2 &S,double e)
{//操作数栈入栈
	if(S.top - S.base == S.stacksize) return ERROR;
	*S.top++ = e;
	return OK;	
}
Status Pop2(SqStack2 &S)
{//操作数栈出栈
	if(S.top == S.base) return ERROR;
	--S.top;
	return OK;	
}
double GetTop2(SqStack2 S)
{//操作数栈取栈顶元素
	if(S.top != S.base)
		return *(S.top - 1);
	return ERROR;
}
double Calculate(double a,char op,double b)
{//计算表达式“a op b”的值
    switch (op) 
	{
		case '+':
			return a + b;
			break;
		case '-':
			return a - b;
			break;
		case '*':
			return a * b;
			break;
		case '/':
			if(b == 0) return ERROR;
			return a / b;
			break;			
		default:
			return ERROR;
			break;
	}   
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

double EvaluateExpression(SqStack1 OPTR,SqStack2 OPND,char s[])
{//算术表达式求值的算符优先算法
 //设OPTR和OPND分别为运算符栈和操作数栈
 //表达式求值算法调用Precede函数和Calculate函数 
	char c, o; double a, b;
	for(int i = 0; s[i] != '\0'; )
	{
		c = s[i];
		if(!isdigit(c))
		{
			switch (Precede(GetTop1(OPTR), c)) 
			{
				case '<':
					Push1(OPTR, c);
					i++;
					break;
				case '>':
					o = GetTop1(OPTR);
					Pop1(OPTR);
					b = GetTop2(OPND);
					Pop2(OPND);
					a = GetTop2(OPND);
					Pop2(OPND);
					Push2(OPND, Calculate(a, o, b));
					break;
				case '=':
					Pop1(OPTR);
					i++;
					break;
				default:
					return ERROR;
					break;
			}
		}
		else
		{
			int j = 0;
			char num[5] = {'\0'};
			do{
				num[j] = c;
				j++; i++;
				c = s[i];
			}while(isdigit(c) || c == '.');
			num[j] = 0;
			double t = atof(num);
			Push2(OPND, t);
		}
	}
	double n = GetTop2(OPND);
	return n;
}

int main()
{//设OPTR和OPND分别为运算符栈和操作数栈
	SqStack1 OPTR;
	InitStack1(OPTR);    //初始化OPND栈
	SqStack2 OPND;
	InitStack2(OPND);    //初始化OPTR栈
	Push1(OPTR,'=');     //提前在OPTR栈中放入'='，便于以后比较符号优先级        
    char s[100];
	while(cin>>s)
	{//循环读入多组数据	
		if(s[0]=='=') 
		   break;    //当表达式只有一个“=”时，输入结束 
		//输出中缀算术表达式的值
		cout<<fixed<<setprecision(2)<<EvaluateExpression(OPTR,OPND,s)<<endl;	
	}
	return 0;
}
