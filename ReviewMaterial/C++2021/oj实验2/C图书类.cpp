#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    char *name;    //书名
    char *author;  //作者
    int sale;      //销售量
public:
    Book(); //无参构造函数
    Book(const char *, const char *, int);//有参构造函数
    Book(const Book &); //拷贝构造函数
    void Print(); //显示数据
    ~Book(); //析构函数
};

Book::Book()//无参构造函数
{
	this ->name = new char[128];
	const char* a = "No name";
	strcpy(this ->name, a);
	this ->author = new char[128];
	const char* b = "No author";
	strcpy(this ->author, b);
	sale = 0;
}

Book::Book(const char *_name, const char *_author, int _sale)//有参构造函数
{
	this ->name = new char[128];
	strcpy(this ->name, _name);
	this ->author = new char[128];
	strcpy(this ->author, _author);
	sale = _sale;
}

Book::Book(const Book &x)//拷贝构造函数
{
	this ->name = new char[128];
	strcpy(this ->name, x.name);
	this ->author = new char[128];
	strcpy(this ->author, x.author);
	sale = x.sale;
}

void Book::Print()//显示数据
{
	cout << "Name: " << name;
	cout << "\tAuthor: " << author;
	cout << "\tSale: " << sale << endl;
}

Book::~Book()//析构函数
{
	delete[] name;
	delete[] author;
	//随时删除好习惯 
}

int main()
{
	char name[128], author[128]; 
    cin.getline(name, 128);
    cin.getline(author, 128);
    int sale; cin >> sale;
    if (strcmp(name, "-1") == 0 && strcmp(author, "-1") == 0 && sale == -1)
    {
        Book bk1;
        bk1.Print();
    }
    else if (strcmp(name, "0") == 0 && strcmp(author, "0") == 0 && sale == 0)
    {
        Book bk1;
        Book bk2 = Book(bk1);
        bk2.Print();
    }
    else
    {
        Book bk3(name, author, sale);
        bk3.Print();
    }
    return 0;
}
