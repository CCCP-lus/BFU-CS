#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	typedef vector<string> string_vector;
	typedef istream_iterator<string> input;
	typedef ostream_iterator<string> output;
	typedef back_insert_iterator<string_vector> ins;

	string_vector vec;

	ifstream from_file("file1.txt");
	if(from_file.fail())
	{
		cout<<"file1.txt´ò¿ªÊ§°Ü"<<"\n";
		exit(0);
	}
	copy(input(from_file),input(),ins(vec));
	copy(vec.begin(),vec.end(),output(cout,"\n"));
	cout<<endl;
	ofstream to_file("file2.txt");
	copy(vec.begin(),vec.end(),output(to_file,"*"));
	return 0;
}