#include<stdio.h>
#include<queue>
using namespace std;

queue<int> q;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++) q.push(i+1); //初始化队列

	while(!q.empty())                 //当队列非空时
	{
		printf("%d ", q.front());     //输出队首元素
		q.pop();                      //移除这一元素
		q.push(q.front());            //把队首元素移到队尾
		q.pop();                      //移除这一元素
	}
	printf("\n");
	return 0;
}