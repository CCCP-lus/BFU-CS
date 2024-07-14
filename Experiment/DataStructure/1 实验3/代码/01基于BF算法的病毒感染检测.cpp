#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define MAXSIZE 2000

//- - - - - 串的堆式顺序存储结构- - - - - 
typedef struct
{   
   char *ch;				//若是非空串，则按串长分配存储区，否则ch为NULL   
   int length;			//串的当前长度   
}HString; 

int Index_BF(HString S,HString T,int pos)
{//返回模式T在主串S中第pos个字符开始第一次出现的位置。若不存在，则返回值为0 
 //其中，T非空，1≤pos≤StrLength(S) 
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
{//判断是否匹配，如果可以，返回true，否则返回false 
//模式匹配算法调用Index_BF函数 
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
    char a[MAXSIZE],b[MAXSIZE];//a存入病毒的DNA序列，b存入人的DNA序列
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
