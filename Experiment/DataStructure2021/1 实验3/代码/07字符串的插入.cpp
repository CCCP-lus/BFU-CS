#include<iostream>
#define MAXSIZE 100
using namespace std;
void Insert(char s[],char t[],int pos,int LenS,int LenT)
{//字符串的插入
	for(int i = LenS - 1 + LenT; i >= pos - 1 + LenT; i--)
		s[i] = s[i - LenT];
	for(int i = pos - 1, j = 0; j < LenT; i++, j++)
		s[i] = t[j];
	s[LenS + LenT] = '\0';
	cout << s << endl;
}

int main()
{
    int pos;
    while(cin>>pos)    	              //输入插入位置pos
    {
        if(pos<=0) break;
        char s[MAXSIZE],t[MAXSIZE];
        cin>>s>>t;            	     //输入字符串s和t
        int LenS=0,LenT=0;
        while(s[LenS]!='\0') LenS++;  //求字符串s的长度LenS
        while(t[LenT]!='\0') LenT++;  //求字符串t的长度LenT
        if(pos>LenS) break;           //插入位置非法
        Insert(s,t,pos,LenS,LenT);
    }
    return 0;
}
