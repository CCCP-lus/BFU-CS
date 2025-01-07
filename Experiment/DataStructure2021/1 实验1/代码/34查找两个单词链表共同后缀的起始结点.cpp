#include <iostream>
using namespace std;
typedef struct LNode
{
    char data;
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

void FindSuffix(LinkList str1, LinkList str2, int n, int m)
{//查找两个单词链表共同后缀的起始结点    直接输出字母
    LNode *p1 = str1, *p2 = str2;
	if(n > m)
	{
		for(p1 = str1; n > m; n--)
			p1 = p1->next;
	}
	else if(n < m)
	{
		for(p2 = str2; n < m; m--)
			p2 = p2->next;
	}
	while(p1->next && p1->next->data != p2->next->data)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	cout << p1->next->data << endl;
}

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        LinkList str1,str2,p;
        CreateList_R(str1,n);
        CreateList_R(str2,m);
        FindSuffix(str1,str2,n,m);
    }
    return 0;
}
