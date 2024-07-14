#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;
void CreateList_R(LinkList& L, int n)
{//后插法创建单链表
    L = new LNode;
	L->next = NULL;
	int num = n;
	LNode* p = L;
	while(num--)
	{
		LNode* t = new LNode;
		cin >> t->data;
		t->next = NULL;
		p->next = t;
		p = t;
	} 
}
int GetLength(LinkList L)
{//递归求解单链表中的结点个数
	if(!L->next)
		return 1;
	return (GetLength(L->next)) + 1;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        LinkList L;
        CreateList_R(L,n);
        L=L->next;    //L指向首元结点
        cout<<GetLength(L)<<endl;
    }
    return 0;
}

