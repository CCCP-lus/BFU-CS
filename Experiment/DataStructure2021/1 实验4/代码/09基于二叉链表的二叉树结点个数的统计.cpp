#include<iostream>
#include<string.h>
using namespace std;

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T,char S[],int &i)
{//先序建立二叉树
	if(S[i] == '0') 
		T = NULL;
	else
	{
		T = new BiTNode;
		T->data = S[i];
		CreateBiTree(T->lchild, S, ++i);
		CreateBiTree(T->rchild, S, ++i);
	}
}
void Count(BiTree T,int &a,int &b,int &c)
{//二叉树结点个数的统计
	if(T)
	{
		if(T->lchild && T->rchild)
			c++;//2
		else if((!T->lchild && T->rchild) || (T->lchild && !T->rchild))
			b++;//1
		else if(!T->lchild && !T->rchild)
			a++;//0
		Count(T->lchild, a, b, c);
		Count(T->rchild, a, b, c);	
	}
}

int main()
{
	
	char S[100];
	while(cin>>S)
	{
	    if(strcmp(S,"0")==0) break;
		int a=0,b=0,c=0;
      	int i=-1;
	  	BiTree T;
		CreateBiTree(T,S,++i);
		Count(T,a,b,c);
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}
