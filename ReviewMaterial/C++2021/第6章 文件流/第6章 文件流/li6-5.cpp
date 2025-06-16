#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Student{
	char name[20];
	char num[10];
	double score;
};

int main()
{
	Student temp[100];
	int n;
	cout<<"输入学生的人数：";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		fflush(stdin);   //清空缓冲区
		cout<<"输入第"<<i+1<<"个学生的姓名、学号和成绩：";
		cin.getline(temp[i].name,20);
		cin>>temp[i].num>>temp[i].score;
	}
	fstream fin, fout;
	fout.open("data.dat",ios::out);
	if(!fout)
	{
		cout<<"cannot open data.dat.\n";
		exit(0);
	}
	for(i=0;i<n;i++)
		fout.write((char *)&temp[i],sizeof(Student));
	fout.close();
	fin.open("data.dat",ios::in);
	if(!fin)
	{
		cout<<"cannot open data.dat.\n";
		exit(0);
	}
	cout<<"姓名\t学号\t成绩\n";
	for(i=0;i<n;i++)
	{
		fout.read((char *)&temp[i],sizeof(Student));
		cout<<temp[i].name<<"\t"<<temp[i].num<<"\t"<<temp[i].score<<"\n";
	}
	fin.close();


	return 0;
}