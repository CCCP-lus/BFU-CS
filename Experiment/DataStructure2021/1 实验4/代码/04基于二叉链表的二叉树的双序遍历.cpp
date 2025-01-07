#include<iostream>
#include <string.h>
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
void DoubleTraverse(BiTree T)
{//˫�����������T�ĵݹ��㷨
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
