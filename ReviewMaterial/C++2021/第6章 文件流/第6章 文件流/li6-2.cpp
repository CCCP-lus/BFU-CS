#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	FILE * read, * write;
	read = fopen("read.txt", "r"); 
	if(!read)
	{
		cout<<"cannot open the read file.\n";
		exit(0);
	}
	write = fopen("write.txt", "w"); 
	if(!write)
	{
		cout<<"cannot open the write file.\n";
		exit(0);
	}
	while(!feof(read))
		fputc(fgetc(read),write);
	fclose(read);
	fclose(write);
	
	return 0;
}

+++++++++++++++++++++++++++

#include<cstdio>

int main() {

	FILE * fread = fopen("test.txt", "r");
	FILE * fwrite = fopen("answer.txt", "w");
	char c;
	while (( c = fgetc(fread)) != EOF) fputc(c, fwrite);

	fclose(fwrite);
	fclose(fread);

	return 0;
}
