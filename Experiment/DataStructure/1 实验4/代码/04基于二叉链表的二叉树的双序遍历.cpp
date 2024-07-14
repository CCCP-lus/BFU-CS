#include<iostream>
#include <string.h>
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
void DoubleTraverse(BiTree T)
{//双序遍历二叉树T的递归算法
	if(T)
	{
		cout << T->data;
		DoubleTraverse(T->lchild);
		cout << T->data;
		DoubleTraverse(T->rchild);
	}
}

int main()
{
	char S[100];
	while(cin>>S)
    {
        if(strcmp(S,"0")==0) break;
        int i=-1;
	  	BiTree T;
		CreateBiTree(T,S,++i);
		DoubleTraverse(T);
		cout<<endl;
	}
	return 0;
}
