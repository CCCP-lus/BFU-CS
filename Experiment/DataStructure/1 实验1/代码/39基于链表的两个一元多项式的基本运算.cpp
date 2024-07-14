#include <iostream>
#include <string>
using namespace std;
typedef struct LNode
{
	int coe;    //ϵ��coe
	int exp;    //ָ��exp
	struct LNode* next;
}LNode, * LinkList;
void CreatePolynomial(LinkList& L, int n)
{//��ָ��exp�Ӵ�С�����ʽ
	L = new LNode;
	L->next = NULL;
	for(int i = 0; i < n; i++)
	{
		LNode *t = new LNode;
		cin >> t->coe >> t->exp;
		LNode* p = L;
		LNode* cur = L->next;
		while(cur && t->exp < cur->exp)
		{
			p = cur;
			cur = cur->next;
		}
		t->next = cur;
		p->next = t;
	}
}
void OutputPolynomial(LinkList L)
{//�������ʽ
	if (!L || !L->next) cout << 0;
	LinkList p = L->next;     //p�Ƕ���ʽ����Ĺ���ָ��,��ʼ��Ϊ��Ԫ���
	while (p)
	{
		if (p == L->next)     //pָ����Ԫ���ʱ������ָ��������������ʽ
		{
			if (p->exp != 0)
				cout << p->coe << "x^" << p->exp;
			else
				cout << p->coe;
		}
		else      //pָ���������ʱ������ϵ����������ָ��������������ʽ
		{
			if (p->coe > 0) cout << "+";
			if (p->exp != 0)
				cout << p->coe << "x^" << p->exp;
			else
				cout << p->coe;
		}
		p = p->next;
	}
	cout << endl;
}
LinkList Add(LinkList LA, LinkList LB)
{//����ʽ�ļӷ�����
	LinkList LC;    //Ŀ�����ʽ����LC
	LC = new LNode;
	LC->next = NULL;		
	LNode *p1 = LA->next, *p2 = LB->next, *p3 = LC;
	while(p1 && p2)
	{
		if(p1->exp == p2->exp)
		{
			if(p1->coe + p2->coe == 0)
			{
				p1 = p1->next;
				p2 = p2->next;
			}
			else
			{
				LNode *t = new LNode;
				t->coe = p1->coe + p2->coe;
				t->exp = p1->exp;
				t->next = NULL;
				p3->next = t;
				p3 = t;
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		else if(p1->exp > p2->exp)
		{
			p3->next = p1;
			p3 = p3->next;
			p1 = p1->next;
		}
		else
		{
			p3->next = p2;
			p3 = p3->next;
			p2 = p2->next;			
		}
	}
	p3->next = p1?p1:p2;
	
	return LC; 
}
void Minus(LinkList LA, LinkList LB)
{//����ʽ�ļ���
	LNode *p = LB->next;
	while(p)
	{
		p->coe *= -1;
		p = p->next;
	}
	OutputPolynomial(Add(LA, LB));
}
void Mul(LinkList LA, LinkList LB)
{//����ʽ�ĳ˷�
	LinkList LC, Lc;    //Ŀ�����ʽ����LC
	LC = new LNode;
	LC->next = NULL;
	Lc = new LNode;
	Lc->next = NULL;
	LNode *p1 = LA->next, *p2 = LB->next;
	LNode *p3 = Lc;
	while(p1)
	{
		while(p2)
		{
			LNode *t = new LNode;
			t->next = NULL;
			t->coe = p1->coe * p2->coe;
			t->exp = p1->exp + p2->exp;
			p3->next = t;
			LC = Add(LC, Lc);
			p2 = p2->next;
		}
		p2 = LB->next;
		p1 = p1->next;
	}
	
	OutputPolynomial(LC);
}
void Diff(LinkList L)
{//����ʽ��������
	LNode *p = L->next;
	while(p)
	{
		p->coe *= p->exp;
		p->exp--;
		p = p->next;
	}
	OutputPolynomial(L);
}



void Opt(LinkList& LA, LinkList& LB, string s)
{//�����ַ�ѡ�����ʽ�ļӷ����������˷���������
	if (s == "+") 
		OutputPolynomial(Add(LA, LB));
	if (s == "-") Minus(LA, LB);
	if (s == "*") Mul(LA, LB);
	if (s == "'")
	{
		Diff(LA);
		Diff(LB);
	}
}
int main()
{
    int n;    //�ܼ���n������
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        LinkList LA,LB;
        CreatePolynomial(LA,a);
        CreatePolynomial(LB,b);
        string s;
        cin>>s;
        Opt(LA,LB,s);
    }
    return 0;
}
