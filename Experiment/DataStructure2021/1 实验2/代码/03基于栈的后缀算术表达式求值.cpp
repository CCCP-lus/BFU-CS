#include <iostream>
#include<iomanip>
#include <string>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
using namespace std;
typedef struct
{//操作数栈
	double* base;
	double* top;
	int  stacksize;
}SqStack;
Status InitStack(SqStack& S)
{//操作数栈初始化
	S.base = new double[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, double e)
{//操作数栈入栈
	if(S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack& S)
{//操作数栈出栈
	if(S.top == S.base)
		return ERROR;
	S.top--;
	return OK;
}
double GetTop(SqStack S)
{//操作数栈取栈顶元素

	if(S.top == S.base)
		return ERROR;	//若不存在栈顶元素则返回ERROR
	double e = *(S.top - 1);
	return e;
}
double Calculate(double a, char op, double b)
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
		case '/':
			return a / b;
		default:
			return ERROR;
			break;
	}
}
double EvaluateExpression(SqStack OPND,char s[])
{//后缀算术表达式求值
 //设OPND为操作数栈
 //表达式求值算法调用Calculate函数 
	for(int i = 0; s[i] != '\0'; i++)
	{
		if(isdigit(s[i]))
		{
//			char c = s[i];
//			int j = 0;
//			char num[5] = {'\0'};
//			do
//			{
//				num[j] = c;
//				j++; i++;
//				c = s[i];
//			}while(isdigit(c) || c == '.');
//			num[j] = 0;
//			double t = atof(num);
//			Push(OPND, t);
			Push(OPND, s[i] - '0');
		}
		else if(s[i] == ' ') continue;
		else
		{
			if(s[i] == '=') break;
			double a, b;
			b = GetTop(OPND); Pop(OPND);
			a = GetTop(OPND); Pop(OPND);
			Push(OPND, Calculate(a, s[i], b));
		}
	}
	double n = GetTop(OPND);
	return n;
}

int main()
{
	char s[100];
	//用字符数组存储表达式，每个数组元素仅存一个字符
	while(1)
	{
		cin.getline(s,100);		//输入一行含空格的后缀表达式
		if(s[0]=='=') 
			break;				//当表达式只有一个"="时，输入结束
		SqStack OPND;
		InitStack(OPND);		//初始化数字栈
		cout<<fixed<<setprecision(2)<<EvaluateExpression(OPND,s)<<fixed<<setprecision(2)<<endl;
	}
	return 0;
}
