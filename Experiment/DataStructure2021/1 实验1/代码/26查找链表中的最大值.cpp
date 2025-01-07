#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, * LinkList;

void CreateList_R(LinkList& L, int n)
{
    // 尾插法
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

int MaxData(LinkList L)
{//确定单链表中值最大的结点
	LNode* p = L->next;
	int max = -10086;
	for(p = L->next; p != NULL; p = p->next)
		if(p->data >= max)
			max = p->data;

	return max;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        LinkList L=new LNode;
        CreateList_R(L,n);
        cout<<MaxData(L)<<endl;
    }
    return 0;
}
