
#include "天E阁.hpp"

int main()
{
    SetConsoleTitle("天E阁v2.0");
    system("color 0a");
    vector<Reference> list;
    User* u;
    bool b;
    if (LOGON() == '0')
    {
        Admin ad;
        u = &ad;
        b = true;
        PRMS prm(list, u, b);
        prm.LOAD();
        prm.OPERATE();
    }
    else
    {
        Visitor vi;
        u = &vi;
        b = false;
        PRMS prm(list, u, b);
        prm.LOAD();
        prm.OPERATE();
    }
    system("cls");
    cout << "天E阁(v2.0)已正常结束运行，文件保存成功!" << endl << endl;
    return 0;
}
