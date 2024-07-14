#include<iostream>
using namespace std;
typedef int Status;
typedef struct
{
	int top[2], bot[2];//栈顶和栈底指针
	int* V;//栈数组
	int m;//栈最大可容纳元素个数
}DblStack;
void InitDblStack(DblStack& S, int m)
{//初始化一个大小为m的双向栈
	S.V = new int[m];
	S.bot[0] = S.top[0] = -1;
	S.bot[1] = S.top[1] = m;
}
Status IsEmpty(DblStack S, int i)
{//判断指定的i号栈是否为空，空返回1，否则返回0
	if(S.top[i] == S.bot[i]) 
		return 1;
	else
		return 0;
}
Status IsFull(DblStack S)
{//判断栈是否满，满则返回1，否则返回0
	if(S.top[0] + 1 == S.top[1])
		return 1;
	else
		return 0;
}
void Push(DblStack& S, int i)
{//向指定的i号栈中插入元素x，先移动指针再入栈
	if(IsFull(S)) 
		exit(-1);
	if(i == 0)
		cin >> S.V[++S.top[i]];
	else	
		cin >> S.V[--S.top[i]];
}

void Pop(DblStack& S, int i)
{//删除指定的i号栈的栈顶元素，先出栈再移动指针
	if(IsEmpty(S, i))
		exit(-1);
	if(i == 0)
		cout << S.V[S.top[i]--] << " ";
	else
		cout << S.V[S.top[i]++] << " ";
}

int main()
{
  	DblStack S;
	int m,e0,e1,d0,d1;
	while(cin>>m)
	{
		if(m==0) break;
		InitDblStack(S,m);
      	cin>>e0>>e1>>d0>>d1;
		while(e0--)
			Push(S,0);
		while(e1--)
			Push(S,1);
      	cout<<IsFull(S)<<endl;
		while(d0--)
			Pop(S,0);
      	cout<<!IsEmpty(S,0)<<endl;
		while(d1--)
			Pop(S,1);
      	cout<<!IsEmpty(S,1)<<endl;
	}
	return 0;
}
