#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
//һ��ͷ�ļ� 
#define FILE_NAME "base.txt"
//����Ĭ���ļ�·�� 
enum Class 
{
	Professional = 1, Reference, Reports, Novels, Others
};
//��ʼ��ö�� 
struct Book
{
	char number[25];//��� 
	char name[25];//���� 
	char writer[25];//���� 
	char press[25];//������ 
	enum Class clas;//���� 
};
//�鼮��Ϣ�ṹ�� 
void Menu() 
{
	printf("*************��ӭʹ�ø����鼮����ϵͳ************\n");
	printf("-------------------------------------------------\n");
	printf("-----------------1.¼���鼮��Ϣ------------------\n\n");
	printf("-----------------2.�����鼮��Ϣ------------------\n\n");
	printf("-----------------3.����鼮��Ϣ------------------\n\n");
	printf("-----------------4.��ѯ�鼮��Ϣ------------------\n\n");
	printf("-----------------5.�����鼮��Ϣ------------------\n\n");
	printf("-----------------6.ɾ���鼮��Ϣ------------------\n\n");
	printf("-----------------7.�޸��鼮��Ϣ------------------\n\n");
	printf("-----------------8.�����ͳ���鼮����------------\n\n");
	printf("-----------------9.���������鼮��������----------\n\n");
	printf("-----------------10.�˳�-------------------------\n");
	printf("-------------------------------------------------\n");
	printf("********************ллʹ��*********************\n\n");
}
//�Զ���Ŀ¼����
void Opening()
{
	system("color 0a");//�ڿ͵۹���ɫ 
	int i;
	printf("��e������鼮����ϵͳ���ڼ����У����Ժ�......\n\n");
	printf("������������֧��^_^\n\n");
	for(i = 0; i < 25; i++)
	{
		printf("/");
		Sleep(100);
		if(i >18) Sleep(200);
	}
	Sleep(2000);
	printf("/\n");
	Sleep(1000);
	printf("�������\n");
	Sleep(2000);
	system("cls"); 
}
//��������
void Closing()
{
	//ż��Ҳ��Ҫ��һ�»��� 
	Sleep(1000);
	system("cls");
	printf("��������ͽ�����\n");
	Sleep(1000);
	printf("��л\n");
	Sleep(500);
	printf("�ҵ�Ů����");
	Sleep(500);
	printf("���ҵİ�����֧�֣�\n");
	Sleep(1000);
	printf("��Ϊ......\n");
	Sleep(2000);
	printf("����18�������������δ���ֹ�\n");
	printf("�����Ҳſ���ר��ѧϰ...");
	Sleep(2000);
} 
//�ػ����� 
void put1(const char* string)
{
	int a = strlen(string), i;
	while (*string)
		putchar(*string++);
	for (i = 0; i < 10 - a; i++)
		printf(" ");
	//�������Ǹ��ݸ�ʽ������� 
}
//�Զ��������ʽ
void Inn(struct Book *p, int *q)
{
	FILE* fp;
	fp = fopen(FILE_NAME, "a+");
	if (fp == NULL)//�����ļ��޷��򿪵���� 
	{
		printf("�޷���%s\n", FILE_NAME);
	}
	int i;
	char asd[2] = {'\0'};//�ж��ǿ�ʱʹ��,��������ʹ��ͬ���ṹ 
	*q = 0;
	for(i = 0; i < 2000; i++)
	{
		fscanf(fp, "%s", (*(p + i)).number);
		fscanf(fp, "%s", (*(p + i)).name);
		fscanf(fp, "%s", (*(p + i)).writer);
		fscanf(fp, "%s", (*(p + i)).press);
		fscanf(fp, "%u", &(*(p + i)).clas);
		if(strcmp((*(p + i)).number, asd) != 0)//�ǿ��ж�
			(*q)++; //����鼮���� 
	}
	fclose(fp);
}
//���ı�����װ��ṹ������
void Out(struct Book *p, int *q)
{
	char asd[2] = {'\0'};
	remove(FILE_NAME);
	//�Ƴ����ı��滻Ϊ���ı� 
	FILE *fp;
	fp = fopen(FILE_NAME, "a+");
	if (fp == NULL)//�����ļ��޷��򿪵���� 
	{
		printf("�޷���%s,���������\n", FILE_NAME);
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
	printf("����Ϊ������...");
	for(i = 0; i < 3; i++)
	{
		Sleep(500);
		printf(".");
	}
	Sleep(500);
loop:
	printf("\n�������!\n");
}
//���ṹ���������ݱ�����Ĭ��·���ı�
void Step1(struct Book *p, int *q) 
{
	printf("-----------------1.¼���鼮��Ϣ------------------\n");
	Sleep(1000);
	char x; int flag = 0, i;
	getchar(); 
loop:
	printf("��ѡ��:1.¼��Ĭ��·�� 2.¼��ָ��·��\n");
	x = getchar();
	fflush(stdin);//������뻺���� 
	if(x == '1')
	{
		Inn(p, q);
		flag = 1;
	}
	else if(x == '2')
	{
		printf("������¼���ļ���·��:\n");
		FILE *fp;
		char z[100] = {'\0'};
		gets(z);
		fp = fopen(z, "a+");
		if (fp == NULL)//�����ļ��޷��򿪵���� 
		{
			printf("�޷���%s�����ļ�\n", z);
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
			if(strcmp((*(p + i)).number, asd) != 0)//�ǿ��ж�
				(*q)++; //����鼮���� 
		}
		fclose(fp);
		flag = 1;		
	}
	if(flag != 1)
	{
		printf("��Ч����,����������:\n");
		goto loop;
	}
	printf("����Ϊ��¼��...");
	for(i = 0; i < 3; i++)
	{
		Sleep(500);
		printf(".");
	}
	Sleep(500);
loop1:
	printf("\n�������!\n");
}
//¼���鼮��Ϣ
void Step2(struct Book *p, int *q)
{
	printf("-----------------2.�����鼮��Ϣ------------------\n");
	Sleep(1000);
	char x; int flag = 0, i;
	getchar();
loop:
	printf("��ѡ��:1.������Ĭ��·�� 2.������ָ��·��\n");
	x = getchar();
	fflush(stdin);//������뻺���� 
	if(x == '1')
	{
		Out(p, q);
		flag = 1;
	}
	else if(x == '2')
	{
		printf("�����뱣���ļ���·��:\n");
		FILE *fp;
		char z[500] = {'\0'};
		gets(z);
		remove(z);
		fp = fopen(z, "a+");
		if (fp == NULL)//�����ļ��޷��򿪵���� 
		{
			printf("�޷���%s�����ļ�\n", z);
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
		printf("����Ϊ������...");
		for(i = 0; i < 3; i++)
		{
			Sleep(500);
			printf(".");
		}
		Sleep(500);
		printf("\n�������!\n");
		fclose(fp);
		flag = 1;		
	}
	if(flag != 1)
	{
		printf("��Ч����,����������:\n");
		goto loop;
	}
}
//�����鼮��Ϣ 
void Step3(struct Book *p, int *q)
{
	printf("-----------------3.����鼮��Ϣ------------------\n");
	Sleep(1000);
	printf("��X   ���飺\t���\t����\t\t����\t\t������\t\t����\n"); 
	int i, j, k, flag = 0;//flag���ڱ������Ƿ�Ϊ��
	struct Book t;
	char asd[2] = {'\0'};
	for(i = 0; i < (*q); i++)
	{
		k = i;
		for(j = i + 1; j < (*q); j++)
			if(strcmp((*(p + k)).number, (*(p + j)).number) > 0) 
			//����������� 
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
			printf("��%-4d���飺\t", i + 1);
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
	if(flag == 0) printf("��������\n");
	else printf("��%d����\n", (*q));
}
//����鼮��Ϣ 
void Step4(struct Book *p, int *q)
{
	printf("-----------------4.��ѯ�鼮��Ϣ------------------\n");
	Sleep(1000);
	printf("�밴�¶�Ӧ����ѡ���ѯ���\n1 ���  2 ����  3 ����  4 ������  5 ����\n");
	int i, n, flag1 = 0; 
	char asd[2] = {'\0'};
	char x[25];
	scanf("%d", &n);//��Ӧ��ѯ, ����ȡ�˷�ֹ��������Ĵ�ʩ
	switch(n)
	{
		case 1:
			printf("�������ѯ��ţ�\n");
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
			if(flag1 == 0) printf("����ѯ��   0�����\n");
			else printf("����ѯ��   1�����\n");
			//���ΪΨһ��ʶ 
			break;
		case 2:
			printf("�������ѯ������\n");
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
			if(num2 == 0) printf("����ѯ��   0�����\n");
			else printf("����ѯ��%4d�����\n", num2);
			break;
		case 3:
			printf("�������ѯ���ߣ�\n");
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
			if(num3 == 0) printf("����ѯ��   0�����\n");
			else printf("����ѯ��%4d�����\n", num3);
			break;
		case 4:
			printf("�������ѯ�����磺\n");
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
			if(num4 == 0) printf("����ѯ��   0�����\n");
			else printf("����ѯ��%4d�����\n", num4);
			break;
		case 5:
			printf("�������ѯ���ࣺ\n");
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
			if(num5 == 0) printf("����ѯ��   0�����\n");
			else printf("����ѯ��%4d�����\n", num5);
			break;
	}	
}
//��ѯ�鼮��Ϣ 
void Step5(struct Book *p, int *q)
{
	printf("-----------------5.�����鼮��Ϣ------------------\n");
	Sleep(1000);
	printf("�밴���¸�ʽ�����鼮��Ϣ\n");
	int i, j, k, num = 0;//numͳ������ 
	char asd[2] = {'\0'};
	for(i = 0; i < 2000; i++)
	{
		while(strcmp((*(p + i)).number, asd) != 0) i++;//��������Ѱ�ҿ�λ�������� 
		loop:
		printf("��ע��! ������֧�ֿո�,��ʹ��_����ո�!\n\n");
		Sleep(1000);		
		printf("������һ��������6λ����λΪ��ֵ���鼮��ţ�����0������\n");
		scanf("%s", (*(p + i)).number);
		char dsa[2] = {'0'};
		if(strcmp((*(p + i)).number, dsa) == 0)
		{
			for(k = 0; k < 6; k++)
				(*(p + i)).number[k] = '\0';//��Ч���ݣ����� 
			Sleep(1000);
			printf("����������������%d����\n�벻Ҫ���Ǳ���\n", num);
			break;
		}
		for(j = 0; j < 2000; j++)
		{
			if(strcmp((*(p + i)).number, (*(p + j)).number) == 0 && i != j)//�ж��Ƿ��Ѿ�ӵ�и��� 
			{
				Sleep(1000);
				printf("���������Ӹ��飬�����ظ�����\n");
				for(k = 0; k < 6; k++)
					(*(p + i)).number[k] = '\0';//��Ч���ݣ����� 
				goto loop;
			}
		}
		printf("������������\n");
		getchar();
		gets((*(p + i)).name);
		printf("����������:\n");
		gets((*(p + i)).writer);
		printf("�����������:\n");
		gets((*(p + i)).press);
		printf("���������:\n");
		scanf("%u",&(*(p + i)).clas);
		num++;
		Sleep(500);
		printf("������ϣ�����������%d����\n\n", num);
		(*q)++;
	}	
	Out(p, q);	
}
//�����鼮��Ϣ 
void Step6(struct Book *p, int *q)
{
	printf("-----------------6.ɾ���鼮��Ϣ------------------\n");
	Sleep(1000);
	printf("�������Ų�����Ҫ�޸ĵ��鼮��Ϣ\n");
loop:
	printf("���ڵ��ò�ѯ\n");
	Sleep(1000);
	Step4(p, q);
	printf("�������������0������Ҫ������Ҫɾ�����鼮��ţ������ȡ��ɾ����\n");
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
	if(flag == 1) printf("ɾ���ɹ�, �벻Ҫ���Ǳ���\n");
	else printf("δ�������鼮��Ϣ��Ϊ������\n");
	Out(p, q);
}
//ɾ���鼮��Ϣ 
void Step7(struct Book *p, int *q)
{
	printf("-----------------7.�޸��鼮��Ϣ------------------\n");
	Sleep(1000);
	printf("�������Ų�����Ҫ�޸����ݵ��鼮��Ϣ\n");
loop:
	printf("���ڵ��ò�ѯ\n");
	Sleep(1000);
	Step4(p, q);
	printf("�������������0������Ҫ������Ҫ�޸����ݵ��鼮��ţ�\n");	
	int i; 
	char n[25];
	gets(n);
	char dsa[2] = {'0'};
	if(strcmp(n, dsa) == 0) goto loop;
	for(i = 0; i < 2000; i++)
		if(strcmp((*(p + i)).number, n) == 0)
		{
			printf("������Ҫ�޸ĵ���Ϣ��\n");
			printf("1.���� 2.���� 3.������ 4.��� �����.ȡ��\n");
			fflush(stdin);
			int w; scanf("%d", &w);
			switch (w) 
			{
				case 1:
					printf("������������\n");
					gets((*(p + i)).name);					
					break;
				case 2:
					printf("����������:\n");
					gets((*(p + i)).writer);
					break;
				case 3:
					printf("�����������:\n");
					gets((*(p + i)).press);			
					break;
				case 4:
					printf("���������:\n");
					scanf("%u", &(*(p + i)).clas);
					break;			
				default:
					printf("������ȡ��\n");
					break;
			}
			Sleep(1000);
			printf("�������, �벻Ҫ���Ǳ���\n");
			break; 
		}	
	Out(p, q);
}
//�޸��鼮��Ϣ
void Step8(struct Book *p, int *q)
{
	printf("-----------------8.�����ͳ���鼮����---------------\n");
	Sleep(1000);
	printf("����������Ӧ���ֲ鿴������,���������:\n");
	int i, aa[6] = {0};
	for(i = 0; i < (*q); i++)
	{
		if((*(p + i)).clas == 1) aa[1]++; 
		if((*(p + i)).clas == 2) aa[2]++; 
		if((*(p + i)).clas == 3) aa[3]++; 
		if((*(p + i)).clas == 4) aa[4]++; 
		if((*(p + i)).clas == 5) aa[5]++; 
	}
	//Ͱ��ʵ�ּ��� 
	printf("ͳ����������:\n");
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
	if(num5 == 0) printf("���ڷ���...\n");
	else printf("��%4d����Ϣ\n", num5);
}
//�����ͳ���鼮������
void Step9(struct Book *p, int *q)
{
	printf("-----------------9.���������鼮��������--------------\n");	
	Sleep(1000); 
	int i, j, k;
	struct Book t;
	char asd[2] = {'\0'};
	for(i = 0; i < (*q); i++)
	{
		k = i;
		for(j = i + 1; j < (*q); j++)
			if(strcmp((*(p + k)).number, (*(p + j)).number) > 0) 
			//����������� 
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
			//�ֵ����������� 
				k = j;		
		if(k != i)
		{
			t = (*(p + i));
			(*(p + i)) = (*(p + k));
			(*(p + k)) = t;
		}
	}
	//���ǵ�׷�����ݣ��˴�ѡ����������� 
	printf("���\t����\t\t����\t\t������\t\t����\n");
	int flag = 0; //flag��������鼮 
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
	if(flag == 0) printf("��������\n");
	else printf("��%d����\n", (*q));
} 
//���������鼮��������
int main()
{
	Opening(); //�������� 
	struct Book ss[2000];//�鼮�ṹ������ 
	memset(ss, 0, sizeof(ss));//����memset����������� 
	struct Book *p = ss;//�ṹ��ָ�� 
	int n; 
	int v = 0; int *q = &v;//��v��ʾ�鼮����������ָ�� 
	printf("�״β�������¼������\n");
	
	//���ϲ������ڳ�ʼ������������ 
	
loop0:	//���ѭ�� 
	printf("\n");
	Sleep(2000);
	Menu();//���ò˵�
	p = ss;
	fflush(stdin); //������뻺����
	fflush(stdout);//������������
	Sleep(1000);
	printf("��ѡ�� 1-10:____\b\b\b"); 
	scanf("%d", &n);
	if (n < 1 || n > 10) 
		{
			Sleep(1000); 
			system("cls");
			printf("����!��Ч������!����������...\n");
			goto loop0;
		} 
	
	//���ϲ��ַ�ֹ���벻�Ϸ�������ɶ��ѭ���ж� 
	
	system("cls");//�������������� 
	switch (n) //����ѡ��ģ�� 
	{
		case 1:
			Step1(p, q); 
			n = 0;//��ֹ���������Ӱ�� 
			goto loop0;//loopʵ�������Ĳ��� 
			break;
		case 2:
			Step2(p, q);
			memset(ss, 0, sizeof(ss));
			//����װ�����ݷ�ֹ��Ч����ռλ
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
			printf("-----------------10.�˳�-------------------------\n");
			Sleep(1000);
			printf("ȷ���˳���? ��0ȷ��, �����ȡ��\n");
			n = 0;
			int qaz; scanf("%d", &qaz);
			if (qaz == 0) Closing();
			else
			{
				getchar();
				goto loop0;
			}
			break;
			//�˳���������������ʵ�� 
	}
	return 0;
}
