#include<iostream>
#include<cstring>
#define MAXSIZE 100
using namespace std;
typedef struct BiTNode
{//二叉树的双链表存储表示
	double data;          //结点数据域
	bool ischaracter;      //判断结点是否为字符
	struct BiTNode *lchild,*rchild;    //左右孩子指针
}BiTNode,*BiTree;
typedef struct
{//字符栈的存储结构
	char *base;     //栈底指针
	char *top;       //栈顶指针
	int stacksize;   //栈可用的最大容量
}SqStack1;
typedef struct
{//结点栈的存储结构
	BiTree *base;
	BiTree *top;
	int stacksize;
}SqStack2;
void InitStack1(SqStack1 &s)
{//字符栈的初始化
	s.base = new char[MAXSIZE];
	if(!s.base) exit(-1);
	s.top = s.base;
	s.stacksize = MAXSIZE;
}
void InitStack2(SqStack2 &s)
{//结点栈的初始化
	s.base = new BiTree[MAXSIZE];
	if(!s.base) exit(-1);
	s.top = s.base;
	s.stacksize = MAXSIZE;	
}
void Push1(SqStack1 &s,char ch)
{//字符入栈操作
	if(s.top - s.base == s.stacksize) exit(-1);
	*s.top++ = ch;	
}
void Push2(SqStack2 &s,BiTree t)
{//结点入栈操作
	if(s.top - s.base == s.stacksize) exit(-1);
	*s.top++ = t;	
}

void Pop1(SqStack1 &s,char &ch)
{//字符出栈操作
	ch = *--s.top;	
}
void Pop2(SqStack2 &s,BiTree &t)
{//结点出栈操作
	t = *--s.top;	
}
char GetTop(SqStack1 s)
{//取字符栈的栈顶元素
	return *(s.top - 1);
}
bool EmptyStack(SqStack1 s)
{//栈的判空操作
	if(s.top == s.base)
		return true;
	else
		return false;
}
char Precede(char a,char b)
{//判断符号的优先级
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
{//运算操作，返回相应的数值结果
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
{//判断ch是否为+、-、*、/、(、)、= 这类的字符，是则返回true
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
{//中序遍历二叉树并求表达式的值
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
{//创建二叉树
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
		SqStack1 optr;      //运算符栈optr
		SqStack2 expt;        //数字栈expt
		InitStack1(optr);     //初始化栈
		InitStack2(expt);     //初始化栈
		Push1(optr,'=');    //先在运算符栈底放入一个'='
		CreateBT(ch,t,optr,expt);       //创建二叉树
		double answer=InOrder(t);
		cout<<answer<<endl;
	}
	return 0;
}
