#include<iostream>
#include<string>
using namespace std;
class Date    //日期类
{
private:
    int Date_year;    //年
    int Date_month;    //月
    int Date_day;    //日
public:
    Date(int year = 2000, int month = 1, int day = 1);
    void show(); //以“年-月-日”格式输出年月日
    ~Date();
};

class Croster    //名单类
{
private:
    string name;
    Date birthday;
public:
    Croster();
    Croster(string name, int year, int month, int day);
    Croster(string name, Date date);
    void show();//显示姓名和出生日期
    ~Croster();
};

Date::Date(int year, int month, int day)//有参构造函数 
{
	this ->Date_year = year;//年赋值 
	this ->Date_month = month;//月赋值 
	this ->Date_day = day;//日赋值 
}

void Date::show()//以“年-月-日”格式输出年月日
{
	std::cout << this ->Date_year << "-" << this ->Date_month << "-" << this ->Date_day << std::endl;
}

Date::~Date()//析构函数 
{
	//这里没有内容 
}

Croster::Croster()//输入为0，无参构造函数 
{
	this ->name = "NULL";//名字为NULL 
	this ->birthday = Date(0, 0, 0);//日期默认为0-0-0 
}

Croster::Croster(string name, int year, int month, int day)//输入为1，4个参数构造函数 
{
	this ->name = name;//名字赋值 
	this ->birthday = Date(year, month, day);//生日赋值 
}

Croster::Croster(string name,Date date)//输入为2，2个参数构造函数
{
	this ->name = name;//名字赋值
	this ->birthday = date;//生日赋值 
} 

void Croster::show()//按格式输出所有信息 
{
	cout << "Name: " << this ->name;
	cout << ", Birthday: ";
	birthday.show();
}

Croster::~Croster()//析构函数 
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
