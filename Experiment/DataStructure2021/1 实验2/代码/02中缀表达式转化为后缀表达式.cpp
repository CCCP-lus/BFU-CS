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
{//��ʼ��ջ
	S.base = new char[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack &S, char e)
{//��ջ
	if(S.top - S.base == S.stacksize) return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack &S)
{//��ջ
	if(S.top == S.base) return ERROR;
	--S.top;
	return OK;
}
char GetTop(SqStack S)
{//ȡջ��Ԫ��
	if(S.top != S.base)
		return *(S.top - 1);
	else return ERROR;
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
void InfixToSuffix(SqStack OPTR,char s[])
{//����׺���ʽת��Ϊ��׺���ʽ����� 
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
	InitStack(OPTR);      //��ʼ��������ջOPTR
	Push(OPTR,'=');		//����ջ�׷���'='�����Ժ�ȽϷ������ȼ�	
	char s[100];
	while(cin>>s)
	{
		if(s[0]=='=')
			break;    	//�����ʽֻ��һ����=��ʱ��������� 
		else
			InfixToSuffix(OPTR,s); 	//����׺���ʽת��Ϊ��׺���ʽ�����	
	}
	return 0;
}
