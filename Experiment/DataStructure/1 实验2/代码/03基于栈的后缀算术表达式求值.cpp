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
{//������ջ
	double* base;
	double* top;
	int  stacksize;
}SqStack;
Status InitStack(SqStack& S)
{//������ջ��ʼ��
	S.base = new double[MAXSIZE];
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack& S, double e)
{//������ջ��ջ
	if(S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack& S)
{//������ջ��ջ
	if(S.top == S.base)
		return ERROR;
	S.top--;
	return OK;
}
double GetTop(SqStack S)
{//������ջȡջ��Ԫ��

	if(S.top == S.base)
		return ERROR;	//��������ջ��Ԫ���򷵻�ERROR
	double e = *(S.top - 1);
	return e;
}
double Calculate(double a, char op, double b)
{//������ʽ��a op b����ֵ
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
{//��׺�������ʽ��ֵ
 //��OPNDΪ������ջ
 //���ʽ��ֵ�㷨����Calculate���� 
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
	//���ַ�����洢���ʽ��ÿ������Ԫ�ؽ���һ���ַ�
	while(1)
	{
		cin.getline(s,100);		//����һ�к��ո�ĺ�׺���ʽ
		if(s[0]=='=') 
			break;				//�����ʽֻ��һ��"="ʱ���������
		SqStack OPND;
		InitStack(OPND);		//��ʼ������ջ
		cout<<fixed<<setprecision(2)<<EvaluateExpression(OPND,s)<<fixed<<setprecision(2)<<endl;
	}
	return 0;
}
