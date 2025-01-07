#include<iostream>
#include<string.h>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T,char S[],int &i)
{//������������
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
void PreOrderTraverse(BiTree T)
{//���������������
	if(T)
	{
		cout << T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BiTree T)
{//���������������
	if(T)
	{
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}
void PostOrderTraverse(BiTree T)
{//�������ĺ������
	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data;
	}
}
int flag;

int main()
{
	char S[100];
	while(cin>>S)
	{
		if(strcmp(S,"0")==0) break;
		int i=-1;
	  	BiTree T;
		CreateBiTree(T,S,++i);
		PreOrderTraverse(T);
		cout<<endl;
  	    InOrderTraverse(T);
		cout<<endl;
		PostOrderTraverse(T);
		cout<<endl;
	}
	return 0;
}
