#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    char *name;    //����
    char *author;  //����
    int sale;      //������
public:
    Book(); //�޲ι��캯��
    Book(const char *, const char *, int);//�вι��캯��
    Book(const Book &); //�������캯��
    void Print(); //��ʾ����
    ~Book(); //��������
};

Book::Book()//�޲ι��캯��
{
	this ->name = new char[128];
	const char* a = "No name";
	strcpy(this ->name, a);
	this ->author = new char[128];
	const char* b = "No author";
	strcpy(this ->author, b);
	sale = 0;
}

Book::Book(const char *_name, const char *_author, int _sale)//�вι��캯��
{
	this ->name = new char[128];
	strcpy(this ->name, _name);
	this ->author = new char[128];
	strcpy(this ->author, _author);
	sale = _sale;
}

Book::Book(const Book &x)//�������캯��
{
	this ->name = new char[128];
	strcpy(this ->name, x.name);
	this ->author = new char[128];
	strcpy(this ->author, x.author);
	sale = x.sale;
}

void Book::Print()//��ʾ����
{
	cout << "Name: " << name;
	cout << "\tAuthor: " << author;
	cout << "\tSale: " << sale << endl;
}

Book::~Book()//��������
{
	delete[] name;
	delete[] author;
	//��ʱɾ����ϰ�� 
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
