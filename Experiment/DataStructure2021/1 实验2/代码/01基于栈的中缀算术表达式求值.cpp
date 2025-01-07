#include <iostream>
#include<iomanip>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
using namespace std;
typedef struct
{//�����ջ
    char *base;
	char *top;
	int stacksize;
}SqStack1;
Status InitStack1(SqStack1 &S)
{//�����ջ��ʼ��
	S.base = new char[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push1(SqStack1 &S, char e)
{//�����ջ��ջ
	if(S.top - S.base == S.stacksize) return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop1(SqStack1 &S)
{//�����ջ��ջ
	if(S.top == S.base) return ERROR;
	--S.top;
	return OK;
}
char GetTop1(SqStack1 S)
{//�����ջȡջ��Ԫ��
	if(S.top != S.base)
		return *(S.top - 1);
	return ERROR;	
}
typedef struct
{//������ջ
	double *base;
	double *top;
	int  stacksize;
}SqStack2;
Status InitStack2(SqStack2 &S)
{//������ջ��ʼ��
	S.base = new double[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push2(SqStack2 &S,double e)
{//������ջ��ջ
	if(S.top - S.base == S.stacksize) return ERROR;
	*S.top++ = e;
	return OK;	
}
Status Pop2(SqStack2 &S)
{//������ջ��ջ
	if(S.top == S.base) return ERROR;
	--S.top;
	return OK;	
}
double GetTop2(SqStack2 S)
{//������ջȡջ��Ԫ��
	if(S.top != S.base)
		return *(S.top - 1);
	return ERROR;
}
double Calculate(double a,char op,double b)
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
{//�Ƚ������a��b�����ȼ�
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
{//�������ʽ��ֵ����������㷨
 //��OPTR��OPND�ֱ�Ϊ�����ջ�Ͳ�����ջ
 //���ʽ��ֵ�㷨����Precede������Calculate���� 
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
{//��OPTR��OPND�ֱ�Ϊ�����ջ�Ͳ�����ջ
	SqStack1 OPTR;
	InitStack1(OPTR);    //��ʼ��OPNDջ
	SqStack2 OPND;
	InitStack2(OPND);    //��ʼ��OPTRջ
	Push1(OPTR,'=');     //��ǰ��OPTRջ�з���'='�������Ժ�ȽϷ������ȼ�        
    char s[100];
	while(cin>>s)
	{//ѭ�������������	
		if(s[0]=='=') 
		   break;    //�����ʽֻ��һ����=��ʱ��������� 
		//�����׺�������ʽ��ֵ
		cout<<fixed<<setprecision(2)<<EvaluateExpression(OPTR,OPND,s)<<endl;	
	}
	return 0;
}
