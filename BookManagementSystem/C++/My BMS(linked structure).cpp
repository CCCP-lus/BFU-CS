#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

#define MAXSIZE 120

typedef struct
{
    char no[15];
    char name[50];
    float price;
}Book;

typedef struct LNode
{
    Book data;
    struct LNode* next;
}LNode, * LinkList;

//辅助功能函数
void Load(LinkList head, int& sum);//读入文件
void Print(Book book);//自定义格式化输出
void BubbleSort(LinkList head, const int& sum);//自定义冒泡排序
void Menu();//自定义目录函数

//操作函数
void Show(LinkList head, int& sum);//图书浏览
void Sum(const int& sum);//图书统计
void Insert(LinkList head, int& sum);//图书插入
void Delete(LinkList head, int& sum);//图书删除
void Search(LinkList head, const int& sum);//图书查找
void Renew(LinkList head, const int& sum);//价格更新
void Sort(LinkList head, const int& sum);//价格排序
void Inverse(LinkList head, const int& sum);//逆序存储

//读入文件
void Load(LinkList head, int& sum)
{
    ifstream inFile("book.txt", ios::in);
    if (!inFile)
    {
        cout << "打开文件失败,请检查文件路径后重试" << endl;
        system("pause");
        return;
    }
    LNode* temp = head; //初始化中间变量
    string line;
    getline(inFile, line);
    getline(inFile, line);  //读入并抛弃标题、表头
    while (getline(inFile, line))
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

        LNode* t = (LNode*)malloc(sizeof(LNode));   //新建节点
        if (t == NULL)
        {
            cout << "出错!" << endl;
            exit(0);
        }
        t->data = bk;
        t->next = NULL;

        temp->next = t;
        temp = temp->next;
        sum++;
    }
    cout << "读取成功!" << endl;
    inFile.close();
}

//自定义格式化输出
void Print(Book book)
{
    cout << left << setw(15) << book.no << "\t";
    cout << left << setw(50) << book.name << "\t";
    cout << left << book.price << endl;
}

//自定义冒泡排序
void BubbleSort(LinkList head, const int& sum)
{
    if (!head || !head->next) 
        return;
    for (int i = 0; i < sum; ++i) 
    {
        LNode* pre = head->next;
        LNode* cur = head->next->next;
        bool flag = 0;
        for (int j = 0; j < sum - i - 1; ++j) 
        {
            if (cur != NULL && pre->data.price > cur->data.price) 
            {
                Book bk;
                bk = pre->data;
                pre->data = cur->data;
                cur->data = bk;
                flag = 1;
            }
            if (pre == NULL)
            {
                cout << "出错!" << endl;
                exit(0);
            }
            pre = pre->next;
            if (cur == NULL)
            {
                cout << "出错!" << endl;
                exit(0);
            }
            cur = cur->next;
        }
        if (!flag)   break;
    }
}

//自定义目录函数
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

//图书浏览
void Show(LinkList head, int& sum)
{
    cout << "1->图书浏览:" << endl;
    //为避免文件运行时二次操作重复读入,需额外增加一次判定
    if (sum == 0)
    {
        cout << "正在为您录入书籍信息..." << endl;
        Load(head, sum);
    }
    if (sum == 0)
    {
        cout << "未检索到文件信息，请检查文件路径后重试" << endl;
        system("pause");
    }
    else
    {
        cout << "系统已读入以下书籍信息:" << endl;
        LNode* t = head->next;
        while (t != NULL)
        {
            Print(t->data);
            t = t->next;
        }
        system("pause");
    }
}

//图书统计
void Sum(const int& sum)
{
    cout << "2->图书统计:" << endl;
    cout << "目前共录入" << sum << "本书籍，统计完毕!" << endl;
    system("pause");
}

//图书插入
void Insert(LinkList head, int& sum)
{
    cout << "3->图书插入:" << endl;
    if (sum == 0)
    {
        cout << "未检索到书籍信息,请先输入" << endl;
        system("pause");
    }
    else
    {
        LNode* temp = head->next;
        cout << "请输入要插入的位置:";
        int x; cin >> x;
        if (x <= 0 || x > sum + 1)
        {
            cout << "不合法的数据!" << endl;
        }
        else
        {
            Book bk;
            cout << "请输入要插入图书的信息:" << endl;
            cout << "请按顺序输入ISBN,书名,价格,以空格隔开:" << endl;
            cin >> bk.no >> bk.name >> bk.price;
            while (temp->next != NULL)
            {
                if (temp->data.no == bk.no && temp->data.name == bk.name && temp->data.price == bk.price)
                {
                    cout << "该图书已存在!" << endl;
                    return;
                }
                temp = temp->next;
            }
            LNode* t = (LNode*)malloc(sizeof(LNode));   //新建节点
            if (t == NULL)
            {
                cout << "出错!" << endl;
                exit(0);
            }
            t->data = bk;
            t->next = NULL;
            temp = head;
            for (int i = 0; i < x; i++)
            {
                if (i == x - 1)
                {
                    t->next = temp->next;
                    temp->next = t;
                }
                if (temp == NULL)
                {
                    cout << "出错!" << endl;
                    exit(0);
                }
                temp = temp->next;
            }
            sum++;
            cout << "插入完毕!" << endl;
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
        temp = head->next;
        while (temp != NULL)
        {
            outFile << temp->data.no << "\t";
            outFile << temp->data.name << "\t";
            outFile << temp->data.price << endl;
            temp = temp->next;
        }
        outFile.close();
        cout << "文件已保存为'book.txt'!" << endl;
    }
    system("pause");
}

//图书删除
void Delete(LinkList head, int& sum)
{
    cout << "4->图书删除:" << endl;
    if (sum == 0)
    {
        cout << "未检索到书籍信息，请先输入" << endl;
        system("pause");
    }
    else
    {
        LNode* temp = head->next;
        cout << "请输入要删除的位置:";
        int x; cin >> x;
        if (x < 0 || x > sum)
        {
            cout << "不合法的数据!" << endl;
        }
        else
        {
            LNode* last = head;
            for (int i = 0; i < x; i++)
            {
                if (i == x - 1)
                    Print(temp->data);
                else
                {
                    last = temp;
                    temp = temp->next;
                }
            }
            cout << "按0确认删除,任意键取消" << endl;
            int y; cin >> y;
            LNode* t = temp->next;
            switch (y)
            {
            case 0:
                last->next = t;
                sum--;
                cout << "删除完毕!" << endl;
                break;
            default:
                cout << "操作已取消" << endl;
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
            temp = head->next;
            while (temp != NULL)
            {
                outFile << temp->data.no << "\t";
                outFile << temp->data.name << "\t";
                outFile << temp->data.price << endl;
                temp = temp->next;
            }
            outFile.close();
            cout << "文件已保存为'book.txt'!" << endl;
        }
        system("pause");
    }
}

//图书查找
void Search(LinkList head, const int& sum)
{
    cout << "5->图书查找" << endl;
    if (sum == 0)
    {
        cout << "未检索到书籍信息，请先输入" << endl;
        system("pause");
    }
    else
    {
        int o;
        cout << "请选择模式:" << endl;
        cout << "1->按位置 2->按书名" << endl;
        cin >> o;
        LNode* temp = head->next;
        switch (o)
        {
        case 1:
            cout << "请输入目标位置:";
            int ad; cin >> ad;
            if (0 < ad && ad <= sum)
            {
                cout << "目标位置的书籍信息如下:" << endl;
                for (int i = 0; i < ad; i++)
                {
                    if (i == ad - 1)
                        Print(temp->data);
                    else
                        temp = temp->next;
                }
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
            while (temp->next != NULL)
            {
                if (strcmp(b, temp->data.name) == 0)
                {
                    Print(temp->data);
                    break;
                }
                else
                    temp = temp->next;
            }
            break;
        default:
            cout << "不合法的数据!" << endl;
            break;
        }
        system("pause");
    }
}

//价格更新
void Renew(LinkList head, const int& sum)
{
    cout << "6->价格更新" << endl;
    if (sum == 0)
    {
        cout << "未检索到书籍信息，请先输入" << endl;
        system("pause");
    }
    else
    {
        LNode* temp = head->next;
        for (int i = 0; i < sum; i++)
        {
            if (temp->data.price < 45)
            {
                temp->data.price *= (float)1.2;
            }
            else
            {
                temp->data.price *= (float)1.1;
            }
            temp = temp->next;
        }
        cout << "更新完成,结果如下:" << endl;
        temp = head->next;
        for (int i = 0; i < sum; i++)
        {
            Print(temp->data);
            temp = temp->next;
        }
        cout << "共" << sum << "本" << endl;
        temp = head->next;

        ofstream outFile("book-newprice.txt", ios::out);
        if (!outFile)
        {
            cout << "读取文件失败，请检查路径是否正确!" << endl;
            exit(1);
        }
        outFile << "北京林业大学图书馆计算机类图书采购列表" << endl;
        outFile << "ISBN	                  书名	                定价" << endl;
        for (int i = 0; i < sum; i++)
        {
            outFile << temp->data.no << "\t";
            outFile << temp->data.name << "\t";
            outFile << temp->data.price << endl;
            temp = temp->next;
        }
        outFile.close();
        cout << "文件已保存为'book-newprice.txt'!" << endl;
        system("pause");
    }
}

//价格排序
void Sort(LinkList head, const int& sum)
{
    cout << "7->价格排序" << endl;
    if (sum == 0)
    {
        cout << "未检索到书籍信息，请先输入" << endl;
        system("pause");
    }
    else
    {
        LNode* temp = head->next;
        BubbleSort(head, sum);
        cout << "排序完成,结果如下:" << endl;
        temp = head->next;
        for (int i = 0; i < sum; i++)
        {
            Print(temp->data);
            temp = temp->next;
        }
        cout << "共" << sum << "本" << endl;

        ofstream outFile("book-newsort.txt", ios::out);
        if (!outFile)
        {
            cout << "读取文件失败，请检查路径是否正确!" << endl;
            exit(1);
        }
        outFile << "北京林业大学图书馆计算机类图书采购列表" << endl;
        outFile << "ISBN	                  书名	                定价" << endl;
        temp = head->next;
        for (int i = 0; i < sum; i++)
        {
            outFile << temp->data.no << "\t";
            outFile << temp->data.name << "\t";
            outFile << temp->data.price << endl;
            temp = temp->next;
        }
        outFile.close();
        cout << "文件已保存为'book-newsort.txt'!" << endl;
        system("pause");
    }
}

//逆序存储
void Inverse(LinkList head, const int& sum)
{
    cout << "8->逆序存储" << endl;
    if (sum == 0)
    {
        cout << "未检索到书籍信息，请先输入" << endl;
        system("pause");
    }
    else
    {
        LNode* p1, * p2, * p3, * temp;
        p1 = head;
        p2 = head->next;
        p3 = head->next->next;
        while (p3 != NULL)
        {
            if (p1->next == head)
                p1->next = NULL;    //头结点后继置空
            p2->next = p1;
            p1 = p3->next;  //将23变为21
            temp = p1;
            p1 = p3;
            p3 = temp;  //调整顺序
            temp = p2;
            p2 = p1;
            p1 = temp;
        }
        p2->next = p1;
        head->next = p2;    //头结点指向末元
        cout << "排序完成,结果如下:" << endl;
        temp = head->next;
        for (int i = 0; i < sum; i++)
        {
            Print(temp->data);
            temp = temp->next;
        }
        cout << "共" << sum << "本" << endl;

        ofstream outFile("book-newinverse.txt", ios::out);
        if (!outFile)
        {
            cout << "读取文件失败，请检查路径是否正确!" << endl;
            exit(1);
        }
        outFile << "北京林业大学图书馆计算机类图书采购列表" << endl;
        outFile << "ISBN	                  书名	                定价" << endl;
        temp = head->next;
        for (int i = 0; i < sum; i++)
        {
            outFile << temp->data.no << "\t";
            outFile << temp->data.name << "\t";
            outFile << temp->data.price << endl;
            temp = temp->next;
        }
        outFile.close();
        cout << "文件已保存为'book-newinverse.txt'!" << endl;
        system("pause");
    }
}

int main()
{
    LinkList head = (LNode*)malloc(sizeof(LNode));
    if (head == NULL)
    {
        cout << "初始化失败!" << endl;
        exit(0);
    }
    head->next = NULL;
    cout << "初始化完毕!" << endl;
    Sleep(1000);
    bool flag = true;   //操作循环控制
    int sum = 0;    //书籍数量
    int selection;
    system("color 0a");
    while (flag)
    {
        system("cls");
        Menu();
        cout << "请选择您需要的服务:";
        cin >> selection;
        system("cls");
        switch (selection)
        {
        case 1:
            Show(head, sum);
            break;
        case 2:
            Sum(sum);
            break;
        case 3:
            Insert(head, sum);
            break;
        case 4:
            Delete(head, sum);
            break;
        case 5:
            Search(head, sum);
            break;
        case 6:
            Renew(head, sum);
            break;
        case 7:
            Sort(head, sum);
            break;
        case 8:
            Inverse(head, sum);
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
    cout << "系统已正常退出!文件自动保存!";
    return 0;
}
