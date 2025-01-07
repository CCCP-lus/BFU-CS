 #include<iostream>
#define MAXSIZE 100
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
int len;
void LongestPath(BiTree T,BiTree l[],int &longest)
{//二叉树最长路径的求解
	if(T)
	{
		len++;
		if(!T->lchild && !T->rchild)
		{
			if(longest < len)
			{
				longest = len;
				l[len] = T;
				len--;
				return ;
			}
		}
		else if(T->lchild)
		{
			LongestPath(T->lchild, l, longest);
			if(l[len + 1]->data == T->lchild->data)
				l[len] = T;
		}
		else if(T->rchild)
		{
			LongestPath(T->rchild, l, longest);
			if(l[len + 1]->data == T->rchild->data)
				l[len] = T;
		}
	}
	len--;
}

int main()
{
	char S[100];
	while(cin>>S&&S[0]!='0')
	{
		int i=-1;
		BiTree T;
        BiTree l[MAXSIZE];
        int longest=0;
		CreateBiTree(T,S,++i);
		LongestPath(T,l,longest);
        cout<<longest<<endl;
       for(int k=1;k<=longest;k++)
          cout<<l[k]->data;
       cout<<endl;
	}
	return 0;
}
