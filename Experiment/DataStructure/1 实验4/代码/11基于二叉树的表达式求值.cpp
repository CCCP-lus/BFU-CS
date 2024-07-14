#include<iostream>
#include<cstring>
#define MAXSIZE 100
using namespace std;
typedef struct BiTNode
{//��������˫����洢��ʾ
	double data;          //���������
	bool ischaracter;      //�жϽ���Ƿ�Ϊ�ַ�
	struct BiTNode *lchild,*rchild;    //���Һ���ָ��
}BiTNode,*BiTree;
typedef struct
{//�ַ�ջ�Ĵ洢�ṹ
	char *base;     //ջ��ָ��
	char *top;       //ջ��ָ��
	int stacksize;   //ջ���õ��������
}SqStack1;
typedef struct
{//���ջ�Ĵ洢�ṹ
	BiTree *base;
	BiTree *top;
	int stacksize;
}SqStack2;
void InitStack1(SqStack1 &s)
{//�ַ�ջ�ĳ�ʼ��
	s.base = new char[MAXSIZE];
	if(!s.base) exit(-1);
	s.top = s.base;
	s.stacksize = MAXSIZE;
}
void InitStack2(SqStack2 &s)
{//���ջ�ĳ�ʼ��
	s.base = new BiTree[MAXSIZE];
	if(!s.base) exit(-1);
	s.top = s.base;
	s.stacksize = MAXSIZE;	
}
void Push1(SqStack1 &s,char ch)
{//�ַ���ջ����
	if(s.top - s.base == s.stacksize) exit(-1);
	*s.top++ = ch;	
}
void Push2(SqStack2 &s,BiTree t)
{//�����ջ����
	if(s.top - s.base == s.stacksize) exit(-1);
	*s.top++ = t;	
}

void Pop1(SqStack1 &s,char &ch)
{//�ַ���ջ����
	ch = *--s.top;	
}
void Pop2(SqStack2 &s,BiTree &t)
{//����ջ����
	t = *--s.top;	
}
char GetTop(SqStack1 s)
{//ȡ�ַ�ջ��ջ��Ԫ��
	return *(s.top - 1);
}
bool EmptyStack(SqStack1 s)
{//ջ���пղ���
	if(s.top == s.base)
		return true;
	else
		return false;
}
char Precede(char a,char b)
{//�жϷ��ŵ����ȼ�
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
	return -1;
}
double Operate(double a,char ch,double b)
{//���������������Ӧ����ֵ���
    switch (ch) 
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
			if(b == 0) return -1;
			return a / b;
			break;			
		default:
			return -1;
			break;
	}   
}
bool IsCharacter(char ch)
{//�ж�ch�Ƿ�Ϊ+��-��*��/��(��)��= ������ַ������򷵻�true
	bool flag = false;
	if(ch == '+' || ch == '-')
		flag = true;
	if(ch == '*' || ch == '/')
		flag = true;
	if(ch == '(' || ch == ')' || ch == '=')
		flag = true;	
	return flag;
}
double InOrder(BiTree T)
{//�������������������ʽ��ֵ
	if(!T)
		return 0;
	if(!T->lchild && !T->rchild)
		return T->data;
	else
	{
		int lv = 0, rv = 0;
		lv = InOrder(T->lchild);
		rv = InOrder(T->rchild);
		return Operate(lv, T->data, rv);
		
	}
}
void CreateBT(char ch[],BiTree &t,SqStack1 optr,SqStack2 expt)
{//����������
	for(int i = 0; i < (int)strlen(ch);)
	{
		if(!IsCharacter(ch[i]))
		{
			BiTree T = new BiTNode;
			T->data = ch[i] - '0';
			T->ischaracter = 0;
			T->lchild = NULL;
			T->rchild = NULL;
			Push2(expt, T);
			i++;
		}
		else
		{
			char sb;
			switch (Precede(GetTop(optr), ch[i])) 
			{
				case '<':
					Push1(optr, ch[i++]);
					break;
				case '=':
					Pop1(optr, sb);
					i++;
					break;
				case '>':
					GetTop(optr);
					Pop1(optr, sb);
					BiTree rc;
					Pop2(expt, rc);
					BiTree lc;
					Pop2(expt, lc);
					BiTree rt = new BiTNode;
					rt->data = sb;
					rt->ischaracter = 1;
					rt->lchild = lc;
					rt->rchild = rc;
					Push2(expt, rt);
					break;
			}
			
		}
	}
	Pop2(expt, t);
}

int main()
{
	char ch[MAXSIZE];
	while(cin>>ch)
	{
		if(ch[0]=='=') break;
		BiTree t;
		SqStack1 optr;      //�����ջoptr
		SqStack2 expt;        //����ջexpt
		InitStack1(optr);     //��ʼ��ջ
		InitStack2(expt);     //��ʼ��ջ
		Push1(optr,'=');    //���������ջ�׷���һ��'='
		CreateBT(ch,t,optr,expt);       //����������
		double answer=InOrder(t);
		cout<<answer<<endl;
	}
	return 0;
}
