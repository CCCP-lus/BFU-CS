#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

#define MAXSIZE 10000

//书籍信息结构体
typedef struct
{
    char no[15];
    char name[50];
    float price;
}Book;

//顺序存储结构类型
typedef struct
{
    Book* elem;
    int length;
}SqList;

SqList L;   //定义变量
bool newb = false;  //重复更新提示

//辅助功能函数
void Load();//读入文件
void Print(Book book);//自定义格式化输出
void Insertionsort();//自定义插入排序
void Menu();//自定义目录函数

//操作函数
void Show();//图书浏览
void Sum();//图书统计
void Insert();//图书插入
void Delete();//图书删除
void Search();//图书查找
void Renew();//价格更新
void Sort();//价格排序
void Inverse();//逆序存储

//读入文件
void Load()
{
    ifstream inFile("book.txt", ios::in);
    if (!inFile)
    {
        cout << "打开文件失败,请检查文件路径后重试" << endl;
        system("pause");
        return;
    }
    string line;
    getline(inFile, line);  //读入并抛弃标题
    getline(inFile, line);  //读入并抛弃表头
    while (getline(inFile, line))   //文件读入到系统
    {
        string str;
        istringstream sin(line);
        Book bk;
        getline(sin, str, '\t');
        strcpy_s(bk.no, str.c_str());
        getline(sin, str, '\t');
        strcpy_s(bk.name, str.c_str());
        getline(sin, str, '\t');
        bk.price = stof(str);
        L.elem[L.length] = bk;
        L.length++;
        if (L.length == MAXSIZE)    //防止内存溢出
        {
            cout << "因空间不足,操作终止!" << endl;
            break;
        }
    }
    cout << "读取完成!" << endl;
    inFile.close();
}

//自定义格式化输出
void Print(Book book)
{
    cout << left << setw(15) << book.no << "\t";
    cout << left << setw(50) << book.name << "\t";
    cout << left << book.price << endl;
}

//自定义插入排序(价格升序)
void Insertionsort()
{
    int i, j;
    Book bk;
    for (i = 1; i < L.length; i++)
    {
        bk = L.elem[i];
        j = i - 1;
        while ((j >= 0) && (L.elem[j].price > bk.price))
        {
            L.elem[j + 1] = L.elem[j];
            j--;
        }
        L.elem[j + 1] = bk;
    }
}

//自定义目录函数(参照C大作业格式)
void Menu()
{
    printf("*************欢迎使用个人书籍管理系统************\n");
    printf("-------------------------------------------------\n");
    printf("-------------------1.图书浏览--------------------\n\n");
    printf("-------------------2.图书统计--------------------\n\n");
    printf("-------------------3.图书插入--------------------\n\n");
    printf("-------------------4.图书删除--------------------\n\n");
    printf("-------------------5.图书查找--------------------\n\n");
    printf("-------------------6.价格更新--------------------\n\n");
    printf("-------------------7.价格排序--------------------\n\n");
    printf("-------------------8.逆序储存--------------------\n\n");
    printf("-------------------0.退出系统--------------------\n");
    printf("-------------------------------------------------\n");
    printf("********************言锡制作*********************\n\n");
}

//操作函数通过书籍数量是否为零判定表是否非空

//1.图书浏览
void Show()
{
    cout << "1->图书浏览:" << endl;
    //两次判定,防止多次读入造成信息重复
    if (L.length == 0)
    {
        cout << "正在为您录入书籍信息..." << endl;
        Load();
    }
    if (L.length == 0)
    {
        cout << "未检索到文件信息，请检查文件路径后重试" << endl;
        system("pause");
    }
    else
    {
        cout << "系统已读入以下书籍信息:" << endl;
        Sleep(1000);
        for (int i = 0; i < L.length; i++)
            Print(L.elem[i]);
        system("pause");
    }
}

//图书统计
void Sum()
{
    cout << "2->图书统计:" << endl;
    cout << "目前共录入" << L.length << "本书籍，统计完毕!" << endl;
    system("pause");
}

//图书插入
void Insert()
{
    cout << "3->图书插入:" << endl;
    if (L.length == 0)
    {
        cout << "未检索到书籍信息,请先输入" << endl;
        system("pause");
    }
    else
    {
        cout << "请输入要插入的位置:";
        int x; cin >> x;
        if (x <= 0 || x > L.length + 1)
        {
            cout << "不合法的数据!" << endl;
        }
        else if (L.length == MAXSIZE)
        {
            cout << "当前存储空间已满!" << endl;
        }
        else
        {
            Book bk;
            cout << "请输入要插入图书的信息:" << endl;
            cout << "请按顺序输入ISBN,书名,价格,以空格隔开,信息中空格请用下划线_代替:" << endl;
            cin >> bk.no >> bk.name >> bk.price;
            for (int i = 0; i < L.length; i++)
                if (bk.no == L.elem[i].no && bk.name == L.elem[i].name && bk.price == L.elem[i].price)
                {//重复信息判定
                    cout << "该图书已存在!" << endl;
                    return;
                }
            for (int i = L.length - 1; i >= x - 1; i--)
                L.elem[i + 1] = L.elem[i];
            L.length++;
            L.elem[x - 1] = bk;
            cout << "插入完毕!" << endl;

            remove("book.txt");
            ofstream outFile("book.txt", ios::out);
            if (!outFile)
            {
                cout << "读取文件失败，请检查路径是否正确!" << endl;
                exit(1);
            }
            outFile << "北京林业大学图书馆计算机类图书采购列表" << endl;
            outFile << "ISBN	                  书名	                定价" << endl;
            for (int i = 0; i < L.length; i++)
            {
                outFile << L.elem[i].no << "\t";
                outFile << L.elem[i].name << "\t";
                outFile << L.elem[i].price << endl;
            }
            outFile.close();
            cout << "文件已保存为'book.txt'!" << endl;
        }
        system("pause");
    }
}

//图书删除
void Delete()
{
    if (L.length == 0)
    {
        cout << "未检索到书籍信息，请先输入" << endl;
        system("pause");
    }
    else
    {
        cout << "请输入要删除的位置:";
        int x; cin >> x;
        if (x <= 0 || x > L.length)
        {
            cout << "不合法的数据!" << endl;
        }
        else
        {
            Print(L.elem[x - 1]);
            cout << "按0确认删除,任意键取消" << endl;
            int y; cin >> y;
            switch (y)
            {
            case 0:
                for (int i = x - 1; i < L.length; i++)
                    L.elem[i] = L.elem[i + 1];
                L.length--;
                cout << "删除完毕!" << endl;
                break;
            default:
                cout << "操作已取消" << endl;
                return ;
                break;
            }

            remove("book.txt");
            ofstream outFile("book.txt", ios::out);
            if (!outFile)
            {
                cout << "读取文件失败，请检查路径是否正确!" << endl;
                exit(1);
            }
            outFile << "北京林业大学图书馆计算机类图书采购列表" << endl;
            outFile << "ISBN	                  书名	                定价" << endl;
            for (int i = 0; i < L.length; i++)
            {
                outFile << L.elem[i].no << "\t";
                outFile << L.elem[i].name << "\t";
                outFile << L.elem[i].price << endl;
            }
            outFile.close();
            cout << "文件已保存为'book.txt'!" << endl;
        }
        system("pause");
    }
}

//图书查找
void Search()
{
    cout << "5->图书查找" << endl;
    if (L.length == 0)
    {
        cout << "未检索到书籍信息，请先输入" << endl;
        system("pause");
    }
    else
    {
        int o;
        cout << "请选择模式:" << endl;
        cout << "1->按位置    2->按书名    任意键->取消" << endl;
        cin >> o;
        switch (o)
        {
        case 1:
            cout << "请输入目标位置:";
            int ad; cin >> ad;
            if (0 < ad && ad <= L.length)
            {
                cout << "目标位置 " << ad << " 处的书籍信息如下:" << endl;
                Print(L.elem[ad - 1]);
            }
            else
            {
                cout << "不合法的数据!" << endl;
            }
            break;
        case 2:
            cout << "请输入目标书名:";
            char b[50]; cin >> b;
            cout << "找到以下数据:" << endl;
            for (int i = 0; i < L.length; i++)
            {
                if (strcmp(b, L.elem[i].name) == 0)
                {
                    Print(L.elem[i]);
                }
            }
            break;
        default:
            cout << "操作已取消." << endl;
            break;
        }
        system("pause");
    }
}

//价格更新
void Renew()
{
    cout << "6->价格更新" << endl;
    if (L.length == 0)
    {
        cout << "未检索到书籍信息，请先输入" << endl;
        system("pause");
    }
    else
    {
        if (newb == true)   //二次更新判定
        {
            cout << "已经更新过价格!再次更新将导致二次提价!" << endl;
            cout << "按0取消,其他键继续" << endl;
            string c; cin >> c;
            char x = c.at(0);   //防止输入过多
            if (x == '0')
            {
                cout << "已中止操作!" << endl;
                return ;
            }
        }
        for (int i = 0; i < L.length; i++)
        {
            if (L.elem[i].price < 45)
            {
                L.elem[i].price *= (float)1.2;
            }
            else
            {
                L.elem[i].price *= (float)1.1;
            }
        }
        newb = true;
        cout << "更新完成,结果如下:" << endl;
        for (int i = 0; i < L.length; i++)
            Print(L.elem[i]);

        ofstream outFile("book-newprice.txt", ios::out);
        if (!outFile)
        {
            cout << "读取文件失败，请检查路径是否正确!" << endl;
            exit(1);
        }
        outFile << "北京林业大学图书馆计算机类图书采购列表" << endl;
        outFile << "ISBN	                  书名	                定价" << endl;
        for (int i = 0; i < L.length; i++)
        {
            outFile << L.elem[i].no << "\t";
            outFile << L.elem[i].name << "\t";
            outFile << L.elem[i].price << endl;
        }
        outFile.close();
        cout << "文件已保存为'book-newprice.txt'!" << endl;
        system("pause");
    }
}

//价格排序
void Sort()
{
    cout << "7->价格排序" << endl;
    if (L.length == 0)
    {
        cout << "未检索到书籍信息，请先输入" << endl;
        system("pause");
    }
    else
    {
        Insertionsort();
        cout << "排序完成,结果如下:" << endl;
        for (int i = 0; i < L.length; i++)
            Print(L.elem[i]);
        cout << "共" << L.length << "本" << endl;

        ofstream outFile("book-newsort.txt", ios::out);
        if (!outFile)
        {
            cout << "读取文件失败，请检查路径是否正确!" << endl;
            exit(1);
        }
        outFile << "北京林业大学图书馆计算机类图书采购列表" << endl;
        outFile << "ISBN	                  书名	                定价" << endl;
        for (int i = 0; i < L.length; i++)
        {
            outFile << L.elem[i].no << "\t";
            outFile << L.elem[i].name << "\t";
            outFile << L.elem[i].price << endl;
        }
        outFile.close();
        cout << "文件已保存为'book-newsort.txt'!" << endl;
        system("pause");
    }
}

//逆序存储
void Inverse()
{
    cout << "8->逆序存储" << endl;
    if (L.length == 0)
    {
        cout << "未检索到书籍信息，请先输入" << endl;
        system("pause");
    }
    else
    {
        Book bk;
        for (int i = 0; i < (L.length / 2); i++)
        {
            bk = L.elem[i];
            L.elem[i] = L.elem[L.length - 1 - i];
            L.elem[L.length - 1 - i] = bk;
        }
        for (int i = 0; i < L.length; i++)
            Print(L.elem[i]);

        ofstream outFile("book-newinverse.txt", ios::out);
        if (!outFile)
        {
            cout << "读取文件失败，请检查路径是否正确!" << endl;
            exit(1);
        }
        outFile << "北京林业大学图书馆计算机类图书采购列表" << endl;
        outFile << "ISBN	                  书名	                定价" << endl;
        for (int i = 0; i < L.length; i++)
        {
            outFile << L.elem[i].no << "\t";
            outFile << L.elem[i].name << "\t";
            outFile << L.elem[i].price << endl;
        }
        outFile.close();
        cout << "文件已保存为'book-newinverse.txt'!" << endl;
        system("pause");
    }
}

int main()
{
    L.elem = new Book[MAXSIZE];
    if (!L.elem)    //存储分配失败则退出
        exit(OVERFLOW);
    bool flag = true;   //操作循环控制
    bool data = false;  //判定初始数据
    int selection;  //操作选择
    system("color 0a"); //更改配色
    while (flag)    //操作循环
    {
        system("cls");
        Menu();
        cout << "请选择功能:" << endl;
        cin >> selection;
        system("cls");
        switch (selection)
        {
        case 1:
            Show();
            break;
        case 2:
            Sum();
            break;
        case 3:
            Insert();
            break;
        case 4:
            Delete();
            break;
        case 5:
            Search();
            break;
        case 6:
            Renew();
            break;
        case 7:
            Sort();
            break;
        case 8:
            Inverse();
            break;
        case 0:
            cout << "0->退出系统:" << endl;
            flag = false;
            break;
        default:
            cout << "无效数据，正在请求跳回:" << endl;
            system("pause");
            break;
        }
    }
    delete[] L.elem;
    cout << "系统已正常退出!文件自动保存!";
    return 0;
}
