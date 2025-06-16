#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
	fstream myfile;
	myfile.open("test.txt",ios::out);
	if(!myfile)
	{
		cout<<"Cannot open the test.txt file.\n";
		exit(0);
	}
	myfile<<100<<"\n"<<"file read and write testing\n";
	myfile.close();

	myfile.open("test.txt",ios::in);
	if(!myfile)
	{
		cout<<"Cannot open the test.txt file.\n";
		exit(0);
	}
	char temp[50];
	while(!myfile.eof())
	{
		myfile.getline(temp,sizeof(temp));
		cout<<temp<<"\n";
	}
	myfile.close();
	
	return 0;
}

+++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	fstream file("test.txt",ios_base::out);
	file<<10<<"hello world";
	file.close();
	
	file.open("test.txt",ios_base::in);
	int num;
	char str[20];
	file>>num;
	cout<<num<<"\n";
	file.read(str,19);
	cout<<str<<endl;
	file.close();
	
	return 0;
}