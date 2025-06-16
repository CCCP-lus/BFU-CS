#include<stdio.h>

const int MAXN = 50;
int queue[2*MAXN];

int main()
{
	int n;
	scanf("%d", &n);
	int front, rear;
	for(int i=0;i<n;i++) queue[i] = i+1;
	front = 0;
	rear = n;
	while(front<rear)
	{
		printf("%d ", queue[front++]);
		queue[rear++] = queue[front++];
	}
	printf("\n");
	return 0;
}