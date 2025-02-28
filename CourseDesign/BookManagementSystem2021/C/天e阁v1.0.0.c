#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
//一堆头文件 
#define FILE_NAME "base.txt"
//定义默认文件路径 
enum Class 
{
	Professional = 1, Reference, Reports, Novels, Others
};
//初始化枚举 
struct Book
{
	char number[25];//序号 
	char name[25];//书名 
	char writer[25];//作者 
	char press[25];//出版社 
	enum Class clas;//分类 
};
//书籍信息结构体 
void Menu() 
{
	printf("*************欢迎使用个人书籍管理系统************\n");
	printf("-------------------------------------------------\n");
	printf("-----------------1.录入书籍信息------------------\n\n");
	printf("-----------------2.保存书籍信息------------------\n\n");
	printf("-----------------3.浏览书籍信息------------------\n\n");
	printf("-----------------4.查询书籍信息------------------\n\n");
	printf("-----------------5.增加书籍信息------------------\n\n");
	printf("-----------------6.删除书籍信息------------------\n\n");
	printf("-----------------7.修改书籍信息------------------\n\n");
	printf("-----------------8.按类别统计书籍数量------------\n\n");
	printf("-----------------9.按书名对书籍进行排序----------\n\n");
	printf("-----------------10.退出-------------------------\n");
	printf("-------------------------------------------------\n");
	printf("********************谢谢使用*********************\n\n");
}
//自定义目录函数
void Opening()
{
	system("color 0a");//黑客帝国配色 
	int i;
	printf("天e阁个人书籍管理系统正在加载中，请稍后......\n\n");
	printf("制作不易请多多支持^_^\n\n");
	for(i = 0; i < 25; i++)
	{
		printf("/");
		Sleep(100);
		if(i >18) Sleep(200);
	}
	Sleep(2000);
	printf("/\n");
	Sleep(1000);
	printf("加载完毕\n");
	Sleep(2000);
	system("cls"); 
}
//启动动画
void Closing()
{
	//偶尔也需要抖一下机灵 
	Sleep(1000);
	system("cls");
	printf("程序到这里就结束啦\n");
	Sleep(1000);
	printf("感谢\n");
	Sleep(500);
	printf("我的女朋友");
	Sleep(500);
	printf("对我的帮助与支持！\n");
	Sleep(1000);
	printf("因为......\n");
	Sleep(2000);
	printf("在我18年的生命中她从未出现过\n");
	printf("所以我才可以专心学习...");
	Sleep(2000);
} 
//关机动画 
void put1(const char* string)
{
	int a = strlen(string), i;
	while (*string)
		putchar(*string++);
	for (i = 0; i < 10 - a; i++)
		printf(" ");
	//其作用是根据格式对齐输出 
}
//自定义输出方式
void Inn(struct Book *p, int *q)
{
	FILE* fp;
	fp = fopen(FILE_NAME, "a+");
	if (fp == NULL)//考虑文件无法打开的情况 
	{
		printf("无法打开%s\n", FILE_NAME);
	}
	int i;
	char asd[2] = {'\0'};//判定非空时使用,后续会多次使用同名结构 
	*q = 0;
	for(i = 0; i < 2000; i++)
	{
		fscanf(fp, "%s", (*(p + i)).number);
		fscanf(fp, "%s", (*(p + i)).name);
		fscanf(fp, "%s", (*(p + i)).writer);
		fscanf(fp, "%s", (*(p + i)).press);
		fscanf(fp, "%u", &(*(p + i)).clas);
		if(strcmp((*(p + i)).number, asd) != 0)//非空判定
			(*q)++; //标记书籍数量 
	}
	fclose(fp);
}
//将文本内容装入结构体数组
void Out(struct Book *p, int *q)
{
	char asd[2] = {'\0'};
	remove(FILE_NAME);
	//移除旧文本替换为新文本 
	FILE *fp;
	fp = fopen(FILE_NAME, "a+");
	if (fp == NULL)//考虑文件无法打开的情况 
	{
		printf("无法打开%s,请检查后重试\n", FILE_NAME);
		goto loop;
	}
	int i;
	for(i = 0; i < (*q); i++)
	{
		if(strcmp((*(p + i)).number, asd) != 0)
		{
			fprintf(fp, "%-6s\t", (*(p + i)).number);
			fprintf(fp, "%-25s\t", (*(p + i)).name);
			fprintf(fp, "%-25s\t", (*(p + i)).writer);
			fprintf(fp, "%-25s\t", (*(p + i)).press);
			fprintf(fp, "%-25u\t\n", (*(p + i)).clas);
		}
	}
	fclose(fp);
	printf("正在为您保存...");
	for(i = 0; i < 3; i++)
	{
		Sleep(500);
		printf(".");
	}
	Sleep(500);
loop:
	printf("\n操作完毕!\n");
}
//将结构体数组内容保存至默认路径文本
void Step1(struct Book *p, int *q) 
{
	printf("-----------------1.录入书籍信息------------------\n");
	Sleep(1000);
	char x; int flag = 0, i;
	getchar(); 
loop:
	printf("请选择:1.录入默认路径 2.录入指定路径\n");
	x = getchar();
	fflush(stdin);//清空输入缓存区 
	if(x == '1')
	{
		Inn(p, q);
		flag = 1;
	}
	else if(x == '2')
	{
		printf("请输入录入文件的路径:\n");
		FILE *fp;
		char z[100] = {'\0'};
		gets(z);
		fp = fopen(z, "a+");
		if (fp == NULL)//考虑文件无法打开的情况 
		{
			printf("无法打开%s处的文件\n", z);
			goto loop1;
		}
		char asd[2] = {'\0'};
		*q = 0;
		for(i = 0; i < 2000; i++)
		{
			fscanf(fp, "%s", (*(p + i)).number);
			fscanf(fp, "%s", (*(p + i)).name);
			fscanf(fp, "%s", (*(p + i)).writer);
			fscanf(fp, "%s", (*(p + i)).press);
			fscanf(fp, "%u", &(*(p + i)).clas);
			if(strcmp((*(p + i)).number, asd) != 0)//非空判定
				(*q)++; //标记书籍数量 
		}
		fclose(fp);
		flag = 1;		
	}
	if(flag != 1)
	{
		printf("无效数据,请重新输入:\n");
		goto loop;
	}
	printf("正在为您录入...");
	for(i = 0; i < 3; i++)
	{
		Sleep(500);
		printf(".");
	}
	Sleep(500);
loop1:
	printf("\n操作完毕!\n");
}
//录入书籍信息
void Step2(struct Book *p, int *q)
{
	printf("-----------------2.保存书籍信息------------------\n");
	Sleep(1000);
	char x; int flag = 0, i;
	getchar();
loop:
	printf("请选择:1.保存至默认路径 2.保存至指定路径\n");
	x = getchar();
	fflush(stdin);//清空输入缓存区 
	if(x == '1')
	{
		Out(p, q);
		flag = 1;
	}
	else if(x == '2')
	{
		printf("请输入保存文件的路径:\n");
		FILE *fp;
		char z[500] = {'\0'};
		gets(z);
		remove(z);
		fp = fopen(z, "a+");
		if (fp == NULL)//考虑文件无法打开的情况 
		{
			printf("无法打开%s处的文件\n", z);
			goto loop;
		}
		char asd[2] = {'\0'};
		for(i = 0; i < (*q); i++)
		{
			if(strcmp((*(p + i)).number, asd) != 0)
			{
				fprintf(fp, "%-6s\t", (*(p + i)).number);
				fprintf(fp, "%-25s\t", (*(p + i)).name);
				fprintf(fp, "%-25s\t", (*(p + i)).writer);
				fprintf(fp, "%-25s\t", (*(p + i)).press);
				fprintf(fp, "%-25u\t\n", (*(p + i)).clas);
			}
		}
		printf("正在为您保存...");
		for(i = 0; i < 3; i++)
		{
			Sleep(500);
			printf(".");
		}
		Sleep(500);
		printf("\n操作完毕!\n");
		fclose(fp);
		flag = 1;		
	}
	if(flag != 1)
	{
		printf("无效数据,请重新输入:\n");
		goto loop;
	}
}
//保存书籍信息 
void Step3(struct Book *p, int *q)
{
	printf("-----------------3.浏览书籍信息------------------\n");
	Sleep(1000);
	printf("第X   本书：\t序号\t书名\t\t作者\t\t出版社\t\t分类\n"); 
	int i, j, k, flag = 0;//flag用于标记书库是否为空
	struct Book t;
	char asd[2] = {'\0'};
	for(i = 0; i < (*q); i++)
	{
		k = i;
		for(j = i + 1; j < (*q); j++)
			if(strcmp((*(p + k)).number, (*(p + j)).number) > 0) 
			//编号升序排列 
				k = j;
		if(k != i)
		{
			t = (*(p + i));
			(*(p + i)) = (*(p + k));
			(*(p + k)) = t;
		}
	}	
	for(i = 0; i < (*q); i++)
	{
		if(strcmp((*(p + i)).number, asd) != 0)
		{
			printf("第%-4d本书：\t", i + 1);
			printf("%-6s\t", (*(p + i)).number);
			put1((*(p + i)).name); printf("\t");
			put1((*(p + i)).writer); printf("\t");
			put1((*(p + i)).press); printf("\t");
			switch ((*(p + i)).clas) 
			{
				case 1:
					printf("Professional");
					break;
				case 2:
					printf("Reference");
					break;
				case 3:
					printf("Reports");
					break;
				case 4:
					printf("Novels");
					break;
				case 5:
					printf("Others");
					break;
			}
			printf("\n");
			flag = 1; 
		}
	} 
	if(flag == 0) printf("暂无数据\n");
	else printf("共%d本书\n", (*q));
}
//浏览书籍信息 
void Step4(struct Book *p, int *q)
{
	printf("-----------------4.查询书籍信息------------------\n");
	Sleep(1000);
	printf("请按下对应按键选择查询类别：\n1 序号  2 书名  3 作者  4 出版社  5 分类\n");
	int i, n, flag1 = 0; 
	char asd[2] = {'\0'};
	char x[25];
	scanf("%d", &n);//对应查询, 并采取了防止错误输入的措施
	switch(n)
	{
		case 1:
			printf("请输入查询序号：\n");
			getchar();
			gets(x);
			for(i = 0; i < (*q); i++)
			{
				if(strcmp((*(p + i)).number, x) == 0)
				{ 
					printf("%-6s\t", (*(p + i)).number);
					put1((*(p + i)).name); printf("\t");
					put1((*(p + i)).writer); printf("\t");
					put1((*(p + i)).press); printf("\t");
					switch ((*(p + i)).clas) 
					{
						case 1:
							printf("Professional");
							break;
						case 2:
							printf("Reference");
							break;
						case 3:
							printf("Reports");
							break;
						case 4:
							printf("Novels");
							break;
						case 5:
							printf("Others");
							break;
					}
					printf("\n");
					flag1 = 1;
				}
			}
			if(flag1 == 0) printf("共查询到   0个结果\n");
			else printf("共查询到   1个结果\n");
			//序号为唯一标识 
			break;
		case 2:
			printf("请输入查询书名：\n");
			getchar();
			gets(x);
			int num2 = 0;
			for(i = 0; i < (*q); i++)
			{
				if(strcmp((*(p + i)).number, asd) != 0 && strcmp(x, (*(p + i)).name) == 0)
				{
					printf("%-6s\t", (*(p + i)).number);
					put1((*(p + i)).name); printf("\t");
					put1((*(p + i)).writer); printf("\t");
					put1((*(p + i)).press); printf("\t");
					switch ((*(p + i)).clas) 
					{
						case 1:
							printf("Professional");
							break;
						case 2:
							printf("Reference");
							break;
						case 3:
							printf("Reports");
							break;
						case 4:
							printf("Novels");
							break;
						case 5:
							printf("Others");
							break;
					}
					printf("\n");
					num2++;
				}
			}
			if(num2 == 0) printf("共查询到   0个结果\n");
			else printf("共查询到%4d个结果\n", num2);
			break;
		case 3:
			printf("请输入查询作者：\n");
			getchar();
			gets(x);
			int num3 = 0;
			for(i = 0; i < (*q); i++)
			{
				if(strcmp((*(p + i)).number, asd) != 0 && strcmp(x, (*(p + i)).writer) == 0)
				{
					printf("%-6s\t", (*(p + i)).number);
					put1((*(p + i)).name); printf("\t");
					put1((*(p + i)).writer); printf("\t");
					put1((*(p + i)).press); printf("\t");
					switch ((*(p + i)).clas) 
					{
						case 1:
							printf("Professional");
							break;
						case 2:
							printf("Reference");
							break;
						case 3:
							printf("Reports");
							break;
						case 4:
							printf("Novels");
							break;
						case 5:
							printf("Others");
							break;
					} 
					printf("\n");
					num3++;
				}
			}
			if(num3 == 0) printf("共查询到   0个结果\n");
			else printf("共查询到%4d个结果\n", num3);
			break;
		case 4:
			printf("请输入查询出版社：\n");
			getchar();
			gets(x);
			int num4 = 0;
			for(i = 0; i < (*q); i++)
			{
				if(strcmp((*(p + i)).number, asd) != 0 && strcmp(x, (*(p + i)).press) == 0)
				{
					printf("%-6s\t", (*(p + i)).number);
					put1((*(p + i)).name); printf("\t");
					put1((*(p + i)).writer); printf("\t");
					put1((*(p + i)).press); printf("\t");
					switch ((*(p + i)).clas) 
					{
						case 1:
							printf("Professional");
							break;
						case 2:
							printf("Reference");
							break;
						case 3:
							printf("Reports");
							break;
						case 4:
							printf("Novels");
							break;
						case 5:
							printf("Others");
							break;
					}
					printf("\n");
					num4++;
				}
			}
			if(num4 == 0) printf("共查询到   0个结果\n");
			else printf("共查询到%4d个结果\n", num4);
			break;
		case 5:
			printf("请输入查询分类：\n");
			printf("1.Professional 2.Reference 3.Reports 4.Novels 5.Others\n");
			unsigned int xx; 
			scanf("%u", &xx);
			int num5 = 0;
			for(i = 0; i < (*q); i++)
			{
				if(strcmp((*(p + i)).number, asd) != 0 && (*(p + i)).clas == xx)
				{
					printf("%-6s\t", (*(p + i)).number);
					put1((*(p + i)).name); printf("\t");
					put1((*(p + i)).writer); printf("\t");
					put1((*(p + i)).press); printf("\t");
					switch ((*(p + i)).clas) 
					{
						case 1:
							printf("Professional");
							break;
						case 2:
							printf("Reference");
							break;
						case 3:
							printf("Reports");
							break;
						case 4:
							printf("Novels");
							break;
						case 5:
							printf("Others");
							break;
					}					
					printf("\n");
					num5++;
				}
			}
			if(num5 == 0) printf("共查询到   0个结果\n");
			else printf("共查询到%4d个结果\n", num5);
			break;
	}	
}
//查询书籍信息 
void Step5(struct Book *p, int *q)
{
	printf("-----------------5.增加书籍信息------------------\n");
	Sleep(1000);
	printf("请按以下格式输入书籍信息\n");
	int i, j, k, num = 0;//num统计数量 
	char asd[2] = {'\0'};
	for(i = 0; i < 2000; i++)
	{
		while(strcmp((*(p + i)).number, asd) != 0) i++;//遍历数组寻找空位增加数据 
		loop:
		printf("请注意! 本程序不支持空格,请使用_代替空格!\n\n");
		Sleep(1000);		
		printf("请输入一个不超过6位的首位为正值的书籍序号，输入0结束：\n");
		scanf("%s", (*(p + i)).number);
		char dsa[2] = {'0'};
		if(strcmp((*(p + i)).number, dsa) == 0)
		{
			for(k = 0; k < 6; k++)
				(*(p + i)).number[k] = '\0';//无效数据，归零 
			Sleep(1000);
			printf("结束，本次已增加%d本书\n请不要忘记保存\n", num);
			break;
		}
		for(j = 0; j < 2000; j++)
		{
			if(strcmp((*(p + i)).number, (*(p + j)).number) == 0 && i != j)//判定是否已经拥有该书 
			{
				Sleep(1000);
				printf("本次已增加该书，不必重复增加\n");
				for(k = 0; k < 6; k++)
					(*(p + i)).number[k] = '\0';//无效数据，归零 
				goto loop;
			}
		}
		printf("请输入书名：\n");
		getchar();
		gets((*(p + i)).name);
		printf("请输入作者:\n");
		gets((*(p + i)).writer);
		printf("请输入出版社:\n");
		gets((*(p + i)).press);
		printf("请输入类别:\n");
		scanf("%u",&(*(p + i)).clas);
		num++;
		Sleep(500);
		printf("输入完毕，本次已增加%d本书\n\n", num);
		(*q)++;
	}	
	Out(p, q);	
}
//增加书籍信息 
void Step6(struct Book *p, int *q)
{
	printf("-----------------6.删除书籍信息------------------\n");
	Sleep(1000);
	printf("请根据序号查找需要修改的书籍信息\n");
loop:
	printf("正在调用查询\n");
	Sleep(1000);
	Step4(p, q);
	printf("仍需检索请输入0，不需要则输入要删除的书籍序号，任意键取消删除：\n");
	int i, k, flag = 0; 
	char n[25];
	gets(n);
	char dsa[2] = {'0'};
	if(strcmp(n, dsa) == 0) goto loop;
	for(i = 0; i < 2000; i++)
		if(strcmp((*(p + i)).number, n) == 0)
			{
				for(k = 0; k < 25; k++)
				{
					(*(p + i)).name[k] = '\0';
					(*(p + i)).writer[k] = '\0';
					(*(p + i)).press[k] = '\0';
				}
				for(k = 0; k < 6; k++)
					(*(p + i)).number[k] = '\0';
				(*(p + i)).clas = 0;
			flag = 1;
			break;
			}
	Sleep(1000);
	if(flag == 1) printf("删除成功, 请不要忘记保存\n");
	else printf("未检索到书籍信息，为您返回\n");
	Out(p, q);
}
//删除书籍信息 
void Step7(struct Book *p, int *q)
{
	printf("-----------------7.修改书籍信息------------------\n");
	Sleep(1000);
	printf("请根据序号查找需要修改内容的书籍信息\n");
loop:
	printf("正在调用查询\n");
	Sleep(1000);
	Step4(p, q);
	printf("仍需检索请输入0，不需要则输入要修改内容的书籍序号：\n");	
	int i; 
	char n[25];
	gets(n);
	char dsa[2] = {'0'};
	if(strcmp(n, dsa) == 0) goto loop;
	for(i = 0; i < 2000; i++)
		if(strcmp((*(p + i)).number, n) == 0)
		{
			printf("请输入要修改的信息：\n");
			printf("1.书名 2.作者 3.出版社 4.类别 任意键.取消\n");
			fflush(stdin);
			int w; scanf("%d", &w);
			switch (w) 
			{
				case 1:
					printf("请输入书名：\n");
					gets((*(p + i)).name);					
					break;
				case 2:
					printf("请输入作者:\n");
					gets((*(p + i)).writer);
					break;
				case 3:
					printf("请输入出版社:\n");
					gets((*(p + i)).press);			
					break;
				case 4:
					printf("请输入类别:\n");
					scanf("%u", &(*(p + i)).clas);
					break;			
				default:
					printf("操作已取消\n");
					break;
			}
			Sleep(1000);
			printf("操作完毕, 请不要忘记保存\n");
			break; 
		}	
	Out(p, q);
}
//修改书籍信息
void Step8(struct Book *p, int *q)
{
	printf("-----------------8.按类别统计书籍数量---------------\n");
	Sleep(1000);
	printf("你可以输入对应数字查看相关情况,任意键返回:\n");
	int i, aa[6] = {0};
	for(i = 0; i < (*q); i++)
	{
		if((*(p + i)).clas == 1) aa[1]++; 
		if((*(p + i)).clas == 2) aa[2]++; 
		if((*(p + i)).clas == 3) aa[3]++; 
		if((*(p + i)).clas == 4) aa[4]++; 
		if((*(p + i)).clas == 5) aa[5]++; 
	}
	//桶排实现计数 
	printf("统计数据如下:\n");
	Sleep(1000);
	printf("1.Professional: %d\n2.Reference: %d\n", aa[1], aa[2]);
	printf("3.Reports: %d\n4.Novels: %d\n5.Others: %d\n\n", aa[3], aa[4], aa[5]);
	Sleep(1000);
	char asd[2] = {'\0'};
	unsigned int xxxxx; 
	scanf("%u", &xxxxx);
	int num5 = 0;
	for(i = 0; i < (*q); i++)
	{
		if(strcmp((*(p + i)).number, asd) != 0 && (*(p + i)).clas == xxxxx)
		{
			printf("%-6s\t", (*(p + i)).number);
			put1((*(p + i)).name); printf("\t");
			put1((*(p + i)).writer); printf("\t");
			put1((*(p + i)).press); printf("\t");
			switch ((*(p + i)).clas) 
			{
				case 1:
					printf("Professional");
					break;
				case 2:
					printf("Reference");
					break;
				case 3:
					printf("Reports");
					break;
				case 4:
					printf("Novels");
					break;
				case 5:
					printf("Others");
					break;
			}					
			printf("\n");
			num5++;
		}
	}
	if(num5 == 0) printf("正在返回...\n");
	else printf("共%4d条信息\n", num5);
}
//按类别统计书籍的数量
void Step9(struct Book *p, int *q)
{
	printf("-----------------9.按书名对书籍进行排序--------------\n");	
	Sleep(1000); 
	int i, j, k;
	struct Book t;
	char asd[2] = {'\0'};
	for(i = 0; i < (*q); i++)
	{
		k = i;
		for(j = i + 1; j < (*q); j++)
			if(strcmp((*(p + k)).number, (*(p + j)).number) > 0) 
			//编号升序排列 
				k = j;
		if(k != i)
		{
			t = (*(p + i));
			(*(p + i)) = (*(p + k));
			(*(p + k)) = t;
		}
	}		
	for(i = 0; i < (*q); i++)
	{
		k = i;
		for(j = i + 1; j < (*q); j++)	
			if(strcmp((*(p + k)).name, (*(p + j)).name) > 0) 
			//字典序升序排列 
				k = j;		
		if(k != i)
		{
			t = (*(p + i));
			(*(p + i)) = (*(p + k));
			(*(p + k)) = t;
		}
	}
	//考虑到追加数据，此处选插入排序更好 
	printf("序号\t书名\t\t作者\t\t出版社\t\t分类\n");
	int flag = 0; //flag标记有无书籍 
	for(i = 0; i < (*q); i++)
	{
		if(strcmp((*(p + i)).number, asd) != 0)
		{
			printf("%-6s\t", (*(p + i)).number);
			put1((*(p + i)).name); printf("\t");
			put1((*(p + i)).writer); printf("\t");
			put1((*(p + i)).press); printf("\t");
			switch ((*(p + i)).clas) 
			{
				case 1:
					printf("Professional");
					break;
				case 2:
					printf("Reference");
					break;
				case 3:
					printf("Reports");
					break;
				case 4:
					printf("Novels");
					break;
				case 5:
					printf("Others");
					break;
			} 
			printf("\n");
			flag = 1;
		}
	}
	if(flag == 0) printf("暂无数据\n");
	else printf("共%d本书\n", (*q));
} 
//按书名对书籍进行排序
int main()
{
	Opening(); //启动动画 
	struct Book ss[2000];//书籍结构体数组 
	memset(ss, 0, sizeof(ss));//调用memset方便后续操作 
	struct Book *p = ss;//结构体指针 
	int n; 
	int v = 0; int *q = &v;//以v表示书籍数量并创建指针 
	printf("首次操作请先录入数据\n");
	
	//以上部分用于初始化程序与数据 
	
loop0:	//完成循环 
	printf("\n");
	Sleep(2000);
	Menu();//调用菜单
	p = ss;
	fflush(stdin); //清空输入缓存区
	fflush(stdout);//清空输出缓存区
	Sleep(1000);
	printf("请选择 1-10:____\b\b\b"); 
	scanf("%d", &n);
	if (n < 1 || n > 10) 
		{
			Sleep(1000); 
			system("cls");
			printf("警告!无效的数据!请重新输入...\n");
			goto loop0;
		} 
	
	//以上部分防止输入不合法数据造成多次循环判定 
	
	system("cls");//清屏以美化程序 
	switch (n) //功能选择模块 
	{
		case 1:
			Step1(p, q); 
			n = 0;//防止旧数据造成影响 
			goto loop0;//loop实现连续的操作 
			break;
		case 2:
			Step2(p, q);
			memset(ss, 0, sizeof(ss));
			//重新装填数据防止无效数据占位
			Inn(p, q);
			n = 0;
			goto loop0;
			break;
		case 3:
			Step3(p, q);
			n = 0;
			goto loop0;
			break;
		case 4:
			Step4(p, q);
			n = 0;
			goto loop0;
			break;
		case 5:
			Step5(p, q);
			n = 0;
			goto loop0;
			break;
		case 6:
			Step6(p, q);
			n = 0;
			goto loop0;
			break;
		case 7:
			Step7(p, q);
			n = 0;
			goto loop0;
			break;
		case 8:
			Step8(p, q);
			n = 0;
			goto loop0;
			break;	
		case 9:
			Step9(p, q);
			n = 0;
			goto loop0;
			break;	
		case 10:
			printf("-----------------10.退出-------------------------\n");
			Sleep(1000);
			printf("确定退出吗? 按0确定, 任意键取消\n");
			n = 0;
			int qaz; scanf("%d", &qaz);
			if (qaz == 0) Closing();
			else
			{
				getchar();
				goto loop0;
			}
			break;
			//退出功能在主函数中实现 
	}
	return 0;
}
