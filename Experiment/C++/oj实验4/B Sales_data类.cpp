#include<bits/stdc++.h>
using namespace std;

class Sales_data
{
    //输入书号、销量和收入 
    friend istream & operator>>(istream&, Sales_data &);
    //输出书号、销量、收入和均价 
    friend ostream & operator<<(ostream &, const Sales_data &);
    friend bool operator==(const Sales_data &, const Sales_data &);
    friend bool operator!=(const Sales_data &, const Sales_data &);
    // for "+", assume that both objects refer to the same book
    friend Sales_data operator+(const Sales_data &, const Sales_data &);

public:
    Sales_data() : units_sold(0), revenue(0.0) {}
    Sales_data(const string & s, unsigned n, double r) :
        bookNo(s), units_sold(n), revenue(r)
    {}
    string get_bookNo() const;
    // for "+=", assume that both objects refer to the same book
    Sales_data & operator+=(const Sales_data &);

private:
    double avg_price() const;  //均价，等于收入除以销量 
    string bookNo;        //书号  
    unsigned units_sold; //销量 
    double revenue;      //收入 
};

//输入书号、销量和收入
istream & operator>>(istream& in, Sales_data & sd)
{
	cin >> sd.bookNo >> sd.units_sold >> sd.revenue;
	return in;
}

//输出书号、销量、收入和均价 
ostream & operator<<(ostream& out, const Sales_data & sd)
{
	cout << sd.bookNo << " " << sd.units_sold << " " << sd.revenue << " " << sd.avg_price();
	return out;
}

bool operator==(const Sales_data & aa, const Sales_data & bb)
{
	return aa.units_sold == bb.units_sold? 1: 0;
}

bool operator!=(const Sales_data & aa, const Sales_data & bb)
{
	return aa.units_sold != bb.units_sold? 1: 0;
}

Sales_data operator+(const Sales_data &aa, const Sales_data & bb)
{
	Sales_data temp;
	temp.bookNo = aa.bookNo;
	temp.units_sold = aa.units_sold + bb.units_sold;
	temp.revenue = aa.revenue + bb.revenue;
	return temp;
}

string Sales_data::get_bookNo() const
{
	return bookNo;
}

Sales_data & Sales_data::operator+=(const Sales_data & sa)
{
	units_sold += sa.units_sold;
	revenue += sa.revenue;
	return *this;
}

double Sales_data::avg_price() const
{
	return revenue / units_sold;
}

int main()
{
    Sales_data item1, item2;
    while(std::cin >> item1 >> item2)
    {
        std::cout << item1 << "\n" << item2 << "\n";
        if (item1 == item2){
            std::cout << item1.get_bookNo() << " equals " << item2.get_bookNo() << "\n";
            std::cout << (item1 + item2) << "\n";
            item1 += item2;
            std::cout << item1 << "\n";
        }
        else if (item1 != item2)
            std::cout << item1.get_bookNo() << " doesn't equal " << item2.get_bookNo() << "\n";
    }
    return 0;
}
