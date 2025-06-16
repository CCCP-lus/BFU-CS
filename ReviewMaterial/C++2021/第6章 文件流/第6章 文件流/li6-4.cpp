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
	Student stu[3] = {{"Mary","001",98},{"Susan","002",97},{"Peter","003",99}};
	fstream myfile;
	myfile.open("test.txt",ios::out|ios::in | ios::binary);  // ios::in | ios::out 需要先创建文件
	if(!myfile)
	{
		cout<<"cannot open text.txt\n";
		exit(0);
	}
	for(int i=0;i<3;i++)
		myfile.write((char *)&stu[i],sizeof(Student));
	myfile.seekp(sizeof(Student)*2);               //指向第3个同学,在fstream中,seekp和seekg没有区别
	Student temp;
	myfile.read((char *)&temp,sizeof(Student));
	cout<<temp.name<<"\t"<<temp.num<<"\t"<<temp.score<<"\n";
	myfile.seekp(0);                //指向第1位同学         
	myfile.read((char *)&temp,sizeof(Student));
	cout<<temp.name<<"\t"<<temp.num<<"\t"<<temp.score<<"\n";
	myfile.seekp(sizeof(Student)*1, ios::cur);         //指向第3个同学
	myfile.read((char *)&temp,sizeof(Student));
	cout<<temp.name<<"\t"<<temp.num<<"\t"<<temp.score<<"\n";
	myfile.seekp(sizeof(Student)*1, ios::beg);         //指向第2个同学
	myfile.read((char *)&temp,sizeof(Student));
	cout<<temp.name<<"\t"<<temp.num<<"\t"<<temp.score<<"\n";

	myfile.close();


	return 0;
}