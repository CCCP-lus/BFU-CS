#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define MAXSIZE 2000

//- - - - - ���Ķ�ʽ˳��洢�ṹ- - - - - 
typedef struct
{   
   char *ch;				//���Ƿǿմ����򰴴�������洢��������chΪNULL   
   int length;			//���ĵ�ǰ����   
}HString; 

int Index_BF(HString S,HString T,int pos)
{//����ģʽT������S�е�pos���ַ���ʼ��һ�γ��ֵ�λ�á��������ڣ��򷵻�ֵΪ0 
 //���У�T�ǿգ�1��pos��StrLength(S) 
	int i = pos - 1, j = 0;
	while(i < S.length && j < T.length)
	{
		if(S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if(j >= T.length) 
		return i - T.length + 1;
	else return 0;
} 


bool Virus_detection(HString Virus,HString Person)
{//�ж��Ƿ�ƥ�䣬������ԣ�����true�����򷵻�false 
//ģʽƥ���㷨����Index_BF���� 
	bool flag = false;
	if(Index_BF(Person, Virus, 1))
		return true;
	for(int i = 0; i <= Virus.length; i++)
	{
		char c = Virus.ch[0];
		for(int j = 1; j < Virus.length; j++)
			Virus.ch[j - 1] = Virus.ch[j];
		Virus.ch[Virus.length - 1] = c;
		if(Index_BF(Person, Virus, 1))
		{
			flag = true;
			break;
		}
	}
	return flag;
}

int main()
{
	 int num,m,flag,i,j; char Vir[1000];
    HString Virus,Person;
    char a[MAXSIZE],b[MAXSIZE];//a���벡����DNA���У�b�����˵�DNA����
	 while(cin>>a>>b)
	{
	   Virus.ch=new char[1000];
      Person.ch=new char[1000];
	   if(strcmp(a,"0")==0&&strcmp(b,"0")==0)
         break;
	   strcpy(Virus.ch,a);
	   strcpy(Person.ch,b);
      Virus.length=strlen(Virus.ch);
	   Person.length=strlen(Person.ch);
      if(Virus_detection(Virus,Person))
         cout<<"YES"<<endl;
      else
         cout<<"NO"<<endl;

    }//while
	return 0;
}
	
/*
abbab abbabaab
baa cacdvcabacsd
abc def
abbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbba
adsfasdfasdfa asdfasdfhsdfjlahsdfjhaljdfahdsf
adsfadfasdfasdf asdfasdfasdfasdfasdfasdfasd
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghiabcdefghijklnmop
qrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghiabcdefghijklnmopqrstuv
wxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghiabcdefghijklnmopqrstu
vwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghiabcdefghijklnmopqrstuvw
xyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghiabcdefghijklnmopqrstuvwx
yz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghiabcdefghijklnmopqr
stuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghiabcdefghijklnm
opqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghiabcdefghijklnmop
qrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghiabcdefghijklnmopqr
stuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghiabcdefghijklnmop
qrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
abcdefghijklnmopqrstuvwxyz klnmopqrstabcdefghijrstuvwxyzopqrstuv
abcdefghijklnmopqrstuvwxyz jklnmopqrstuvwxyzabcdefghi
cvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvc
0 0
*/

/*
YES
YES
NO
YES
NO
NO
NO
YES
NO
YES
NO
YES
NO
YES
NO
YES
NO
YES
NO
YES
NO
YES
NO
YES
YES
YES
NO
YES
NO
YES
YES
YES
NO
YES
NO
YES
YES
YES
NO
YES
NO
YES
YES
YES
NO
YES
NO
YES
YES
YES
NO
YES
NO
YES
YES
YES
NO
YES
NO
YES
NO
YES
NO
YES
NO
YES
YES
YES
NO
YES
NO
YES
NO
YES
NO
YES
NO
YES
YES
*/
