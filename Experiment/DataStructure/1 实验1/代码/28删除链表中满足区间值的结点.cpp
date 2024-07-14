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
void DeleteMinMax(LinkList& L, int mink, int maxk)
{//删除链表中满足区间值的结点
    LNode* p;
    p = L;
    while(p->next)
    {
		LNode* t = p->next;
		if((p->next->data >= mink) && (p->next->data <= maxk))
		{
			p->next = t->next;
			delete t;
		}
        else
            p = p->next;
	}
}

void PrintList(LinkList &L)
{//打印依次输出链表中的数据
    L=L->next;
    while(L){
        if(L->next!=NULL) cout<<L->data<<" ";
        else cout<<L->data;
        L=L->next;
    }
    cout<<endl;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        LinkList L;
        CreateList_R(L,n);
        int mink,maxk;
        cin>>mink>>maxk;
        DeleteMinMax(L,mink,maxk);
        PrintList(L);
    }
    return 0;
}
