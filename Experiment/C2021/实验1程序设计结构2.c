#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
//这还是朴实无华且枯燥的红题 
//还有一种办法是int i从200~300循环，但是大家都这样就很无聊，我走条不一样的路 
int main()
{
	int i, j, k;
	printf("Here are the answers:\n");
	for(i = 2; i <= 2; i++)//百位 
		for(j = 0; j < 10; j++)//十位 
			for(k = 0; k < 10; k++)//个位 
			{
				if(i + j + k == 12 && i * j * k == 42)
				printf("%d%d%d\n", i, j, k);//组合成答案，进行朴实无华且枯燥的输出  
			}
	return 0;
}
