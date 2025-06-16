#include <iostream>
#include <cstdio>
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
	
	cout << "输入学生的人数：";
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		fflush(stdin);   //清空缓冲区
		cout << "输入第" << i + 1 << "个学生的姓名、学号和成绩：";
		cin.getline(temp[i].name, 20);
		cin >> temp[i].num >> temp[i].score;
	}
	FILE * out;
	out = fopen("text.txt", "w");
	if (!out)
	{
		cout << "cannot open text.txt. out \n";
		exit(0);
	}
	for (int i = 0; i<n; i++)
	{
		if (fwrite(&temp[i], sizeof(Student), 1, out) != 1)
		{
			cout << "file write error.\n";
			exit(0);
		}
	} 
	fclose(out);

	FILE * in;
	in = fopen("text.txt", "r");
	if (!in)
	{
		cout << "cannot open text.txt. in \n";
		exit(0);
	}
	
	cout << "姓名\t学号\t成绩\n";
	for (int i = 0; i<n; i++)
	{
		fread(&temp[i], sizeof(Student), 1, in);
		cout << temp[i].name << "\t" << temp[i].num << "\t" << temp[i].score << "\n";
	}
	fclose(in);
	
	return 0;
}
