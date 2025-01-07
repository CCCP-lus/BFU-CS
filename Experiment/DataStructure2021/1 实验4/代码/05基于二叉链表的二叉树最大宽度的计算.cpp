#include <iostream>
#include <string.h>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree CreateBiTree(int &pos, char *str)
{// ������������
	BiTree T;
	if(str[pos] == '0')
		T = NULL;
	else
	{
		T = new BiTNode;
		T->data = str[pos];
		T->lchild = CreateBiTree(++pos, str);
		T->rchild = CreateBiTree(++pos, str);
	}
	return T;
}

int Width(BiTree T)
{// �������T�����
	if(!T)
		return 0;
	BiTree B[1000];
	int front = 1, rear = 1, last = 1, width = 0, maxw = 0;
	B[rear] = T;
	while(front <= last)
	{
		width++;
		BiTree t = B[front++];
		if(t->lchild)
			B[++rear] = t->lchild;
		if(t->rchild)
			B[++rear] = t->rchild;
		if(front > last)
		{
			last = rear;
			if(maxw < width)
				maxw = width;
			width = 0;
		}
	}
	return maxw;
}

int main()
{
    char str[1000];
    while(cin>>str)
    {
        if(strcmp(str,"0")==0) break;
        int pos=0;                         // ����ַ�������λ��
        BiTree root=CreateBiTree(pos,str);
        cout<<Width(root)<<endl;
    }
    return 0;
}
