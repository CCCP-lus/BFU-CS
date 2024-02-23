#include<iostream>
#include<string>
using namespace std;
class Date    //������
{
private:
    int Date_year;    //��
    int Date_month;    //��
    int Date_day;    //��
public:
    Date(int year = 2000, int month = 1, int day = 1);
    void show(); //�ԡ���-��-�ա���ʽ���������
    ~Date();
};

class Croster    //������
{
private:
    string name;
    Date birthday;
public:
    Croster();
    Croster(string name, int year, int month, int day);
    Croster(string name, Date date);
    void show();//��ʾ�����ͳ�������
    ~Croster();
};

Date::Date(int year, int month, int day)//�вι��캯�� 
{
	this ->Date_year = year;//�긳ֵ 
	this ->Date_month = month;//�¸�ֵ 
	this ->Date_day = day;//�ո�ֵ 
}

void Date::show()//�ԡ���-��-�ա���ʽ���������
{
	std::cout << this ->Date_year << "-" << this ->Date_month << "-" << this ->Date_day << std::endl;
}

Date::~Date()//�������� 
{
	//����û������ 
}

Croster::Croster()//����Ϊ0���޲ι��캯�� 
{
	this ->name = "NULL";//����ΪNULL 
	this ->birthday = Date(0, 0, 0);//����Ĭ��Ϊ0-0-0 
}

Croster::Croster(string name, int year, int month, int day)//����Ϊ1��4���������캯�� 
{
	this ->name = name;//���ָ�ֵ 
	this ->birthday = Date(year, month, day);//���ո�ֵ 
}

Croster::Croster(string name,Date date)//����Ϊ2��2���������캯��
{
	this ->name = name;//���ָ�ֵ
	this ->birthday = date;//���ո�ֵ 
} 

void Croster::show()//����ʽ���������Ϣ 
{
	cout << "Name: " << this ->name;
	cout << ", Birthday: ";
	birthday.show();
}

Croster::~Croster()//�������� 
{
	
}

int main()
{
    int ch;
    while (cin >> ch)
    {
        int y, m, d;
        string name;
        if (ch == 0)
        {
            Croster s0;
            s0.show();
        }
        else if (ch == 1)
        {
            cin >> name >> y >> m >> d;
            Croster s1(name, y, m, d);
            s1.show();
        }
        else if (ch == 2)
        {
            cin >> name >> y >> m >> d;
            Date md(y, m, d);
            Croster s2(name, md);
            s2.show();
        }
        else if (ch == -1)
            return 0;
    }
    return 0;
}
