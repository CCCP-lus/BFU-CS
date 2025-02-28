#pragma once
#include<bits/stdc++.h>
#include<Windows.h>
#include<conio.h>
#pragma warning(disable:4996)
using namespace std;

class PRMS;
class Reference;
class User;
class Admin;
class Visitor;
class map_value_finder;
bool cmp_DOI(Reference a, Reference b);
bool cmp_date(Reference a, Reference b);
bool cmp_title(Reference a, Reference b);
void FIND(string, multimap<string, Reference>);

class PRMS//����ϵͳ�� 
{
private:
	vector<Reference> List;//��������
	User* People;//���ָ��
	bool limit = false;//Ȩ�޹���
protected:

public:
	PRMS();
	PRMS(vector<Reference>, User*, bool);
	~PRMS() {}
	void LOAD();//���ļ�������д�����
	void OPERATE();//�������
	void FILL();//������������д���ļ�
	vector<Reference> get_List();
	void set_List(vector<Reference>);
	bool get_limit();
	void set_limit(bool);
};

class Reference//������ 
{
private:
	string DOI;	//DOI
	string author1;	//һ��
	string author2;	//����
	string title;	//����
	string publication;	//����
	int date;	//���
	int type;	//����
protected:

public:
	Reference();
	Reference(string, string, string, string, string, int, int);
	~Reference();
	friend ostream& operator << (ostream&, const Reference&);
	string getDOI();
	void setDOI(string);
	string get_DOI() const;
	string getauthor1();
	void setauthor1(string);
	string getauthor2();
	void setauthor2(string);
	string gettitle();
	void settitle(string);
	string getpublication();
	void setpublication(string);
	int getdate();
	void setdate(int);
	int gettype();
	void settype(int);
};

class User//�û��� 
{
	friend class PRMS;
private:

protected:
	string una;
	string upd;
public:
	User() {}
	User(const User&) {}
	virtual ~User() {}

	virtual void add_reference(vector<Reference>&) = 0;	//¼������
	virtual void delete_reference(vector<Reference>&) = 0;	//ɾ������
	virtual void show_reference(const vector<Reference>&) = 0;	//��ʾȫ������
	virtual void edit_reference(vector<Reference>&) = 0;	//�༭������Ϣ
	virtual void search_reference(const vector<Reference>&) = 0;	//��ѯ������Ϣ
};

class Admin : public User//����Ա�� 
{
	friend class PRMS;
private:

protected:

public:
	Admin();
	Admin(string a);
	Admin(const Admin&);
	~Admin() {}
	void add_reference(vector<Reference>&);	//¼������
	void delete_reference(vector<Reference>&);	//ɾ������
	void show_reference(const vector<Reference>&);	//��ʾȫ������
	void edit_reference(vector<Reference>&);	//�༭������Ϣ
	void search_reference(const vector<Reference>&);	//��ѯ������Ϣ
};

class Visitor : public User//�ÿ��� 
{
private:

protected:

public:
	Visitor() {}
	Visitor(string);
	Visitor(const Visitor&);
	~Visitor() {}
	void add_reference(vector<Reference>&) {}//¼������
	void delete_reference(vector<Reference>&) {}//ɾ������
	void show_reference(const vector<Reference>&);	//��ʾȫ������
	void edit_reference(vector<Reference>&) {}//�༭������Ϣ
	void search_reference(const vector<Reference>&);	//��ѯ������Ϣ
};

PRMS::PRMS()
{
	People = NULL;
}

PRMS::PRMS(vector<Reference> v, User* u, bool b)
{
	List.clear();
	People = u;
	for (vector<Reference>::iterator it = v.begin(); it != v.end(); it++)
		List.push_back(*it);
	limit = b;
}

void PRMS::LOAD()
{
	system("cls");
	cout << "���ڶ�ȡ�ļ������Ժ�" << endl;
	Sleep(3000);
	ifstream inFile("Reference_List.csv", ios::in);
	if (!inFile)
	{
		std::cout << "��ȡ�ļ�ʧ�ܣ�����·���Ƿ���ȷ" << endl;
		exit(1);
	}
	string line;
	List.clear();
//	getline(inFile, line);
	while (getline(inFile, line))
	{
		string str;
		istringstream sin(line);
		//�����ַ���line�����ַ�����sin��
		Reference re;

		getline(sin, str, ',');
		re.setDOI(str);

		getline(sin, str, ',');
		re.setauthor1(str);

		getline(sin, str, ',');
		re.setauthor2(str);

		getline(sin, str, ',');
		re.settitle(str);

		getline(sin, str, ',');
		re.setpublication(str);

		getline(sin, str, ',');
		re.setdate(stoi(str));

		getline(sin, str);
		re.settype(stoi(str));

		List.push_back(re);
	}
	cout << "��ȡ�ɹ�!" << endl;
	inFile.close();
}

void PRMS::OPERATE()
{
	int o;
	Sleep(1000);
	system("cls");
	cout << "��ѡ����:" << endl;
	cout << "0-�˳� 1-��ʾȫ������ 2-��ѯ�ļ���Ϣ" << endl;
	if (get_limit())
		cout << "3-¼������ 4-ɾ������ 5-�༭������Ϣ" << endl;
	while (cin >> o)
	{
		if (o == 0) break;
		else if (o == 1) People->show_reference(List);
		else if (o == 2) People->search_reference(List);
		else if (o == 3)
		{
			if(limit == true) People->add_reference(List);
			else cout << "���Ϸ�������!" << endl;
		}
		else if (o == 4)
		{
			if (limit == true) People->delete_reference(List);
			else cout << "���Ϸ�������!" << endl;
		}
		else if (o == 5) 
		{
			if (limit == true) People->edit_reference(List);
			else cout << "���Ϸ�������!" << endl;
		}
		else cout << "���Ϸ�������!" << endl;
		cout << endl;
		system("pause");
		FILL();
		cout << "��ѡ����:" << endl;
		cout << "0-�˳� 1-��ʾȫ������ 2-��ѯ�ļ���Ϣ" << endl;
		if (get_limit())
			cout << "3-¼������ 4-ɾ������ 5-�༭������Ϣ" << endl;
	}
}

void PRMS::FILL()
{
	ofstream outFile("Reference_List.csv", ios::out);

	if (!outFile)
	{
		cout << "��ȡ�ļ�ʧ�ܣ�����·���Ƿ���ȷ" << endl;
		exit(1);
	}
	sort(List.begin(), List.end(), cmp_DOI);
	for (vector<Reference>::iterator it = List.begin(); it != List.end(); it++)
	{
		outFile << it->getDOI() << ",";
		outFile << it->getauthor1() << ",";
		outFile << it->getauthor2() << ",";
		outFile << it->gettitle() << ",";
		outFile << it->getpublication() << ",";
		outFile << it->getdate() << ",";
		outFile << it->gettype() << endl;
	}
	outFile.close();
	system("cls");
	cout << "����ɹ�!" << endl;
}

vector<Reference> PRMS::get_List()
{
	return List;
}

void PRMS::set_List(vector<Reference> v)
{
	List.clear();
	for (vector<Reference>::iterator it = v.begin(); it != v.end(); it++)
		List.push_back(*it);
}

bool PRMS::get_limit()
{
	return limit;
}
void PRMS::set_limit(bool b)
{
	limit = b;
}

Reference::Reference()
{
	DOI = "NAN";
	author1 = "NAN";
	author2 = "NAN";
	title = "NAN";
	publication = "NAN";
	date = 0000;
	type = 0;
}

Reference::Reference(string a, string b, string c, string d, string e, int f, int t)
{
	DOI = a;
	author1 = b;
	author2 = c;
	title = d;
	publication = e;
	date = f;
	type = t;
}

Reference::~Reference()
{

}

ostream& operator << (ostream& o, const Reference& r)
{
	cout << setiosflags(ios::left) << setw(10) << r.DOI;
	cout << setiosflags(ios::left) << setw(10) << r.author1;
	cout << setiosflags(ios::left) << setw(10) << r.author2;
	cout << setiosflags(ios::left) << setw(10) << r.title;
	cout << setiosflags(ios::left) << setw(15) << r.publication;
	cout << setiosflags(ios::left) << setw(10) << r.date;
	if (r.type == 0)
		cout << setiosflags(ios::left) << setw(10) << "Article" << endl;
	else if (r.type == 1)
		cout << setiosflags(ios::left) << setw(10) << "Review" << endl;
	return o;
}

string Reference::getDOI()
{
	return DOI;
}

void Reference::setDOI(string s)
{
	DOI = s;
}

string Reference::get_DOI() const
{
	return DOI;
}

string Reference::getauthor1()
{
	return author1;
}

void Reference::setauthor1(string s)
{
	author1 = s;
}

string Reference::getauthor2()
{
	return author2;
}

void Reference::setauthor2(string s)
{
	author2 = s;
}

string Reference::gettitle()
{
	return title;
}

void Reference::settitle(string s)
{
	title = s;
}

string Reference::getpublication()
{
	return publication;
}

void Reference::setpublication(string s)
{
	publication = s;
}

int Reference::getdate()
{
	return date;
}

void Reference::setdate(int i)
{
	date = i;
}

int Reference::gettype()
{
	return type;
}

void Reference::settype(int i)
{
	type = i;
}

Admin::Admin()
{
	una = "Admin";
	upd = "NAN";
}

Admin::Admin(string a)
{
	una = "Admin";
	upd = a;
}

Admin::Admin(const Admin& a)
{
	una = "Admin";
	upd = a.upd;
}

void Admin::add_reference(vector<Reference>& p)
{
	system("cls");
	cout << "�������\n" << endl;
	flagadd1:
	cout << "������DOI:" << endl;
	string adoi; cin >> adoi;
	for (vector<Reference>::iterator it = p.begin(); it != p.end(); it++)
	{
		if ((*it).getDOI() == adoi)
		{
			cout << "��⵽�Ѵ���DOIΪ" << adoi << "�����ף��Ƿ񸲸�?" << endl;
			cout << "0-��, �����-��" << endl;
			char nn; cin >> nn;
			if (nn == '0') break;
			else goto flagadd1;
		}
	}
	cout << "������һ��:" << endl;
	string awriter1; cin >> awriter1;
	cout << "���������:" << endl;
	string awriter2; cin >> awriter2;
	cout << "���������:" << endl;
	string atitle; cin >> atitle;
	cout << "�����뿯��" << endl;
	string apublication; cin >> apublication;
	cout << "���������" << endl;
	int ayear; cin >> ayear;
	cout << "��ѡ�����ͣ�0-Article��1-Review" << endl;
	int atype; cin >> atype;
	if (atype == 0)
	{
		Reference add(adoi, awriter1, awriter2, atitle, apublication, ayear, 0);
		p.push_back(add);
		MessageBox(0, "������", "��E��v2.0", 0);
		getchar();
	}
	else if (atype == 1)
	{
		Reference add(adoi, awriter1, awriter2, atitle, apublication, ayear, 1);
		p.push_back(add);
		MessageBox(0, "������", "��E��v2.0", 0);
		getchar();
	}
	else
	{
		MessageBox(0, "��Ч����ֵ, ������!", "��E��v2.0", 0);
		getchar();
		cin.clear();
		goto flagadd1;
	}
}

void Admin::delete_reference(vector<Reference>& p)
{
	system("cls");
	cout << "ɾ������:\n" << endl;
	vector<Reference> temp;
	for (vector<Reference>::iterator it = p.begin(); it != p.end(); it++)
		temp.push_back(*it);
	cout << "������Ҫɾ�����׵�DOI" << endl;
	string Doi; cin >> Doi;
	int t;
	for (int i = 0; i < (int)temp.size(); i++)
	{
		if (temp[i].getDOI() == Doi)
		{
			cout << "�ҵ����½��" << endl;
			cout << temp[i];
			t = i;
			break;
		}
		if (i == (int)temp.size())
		{
			cout << "δ������DOIΪ" << Doi << "������";
		}
	}
	cout << "ȷ��ɾ��? 0-ȷ�� �����ȡ��" << endl;
	string a; cin >> a;
	if (a == "0")
	{

		MessageBox(0, "ɾ�����", "��E��v2.0", 0);
		getchar();
		return;
	}
	else
	{
		MessageBox(0, "������ȡ��!", "��E��v2.0", 0);
		getchar();
	}
	p.clear();
	for (vector<Reference>::iterator it = temp.begin(); it != temp.end(); it++)
		p.push_back(*it);
}

void Admin::show_reference(const vector<Reference>& p)
{
	system("cls");
	cout << "չʾ����:\n" << endl;
	cout << setiosflags(ios::left) << setw(5) << "num";
	cout << setiosflags(ios::left) << setw(10) << "DOI";
	cout << setiosflags(ios::left) << setw(10) << "author1";
	cout << setiosflags(ios::left) << setw(10) << "author2";
	cout << setiosflags(ios::left) << setw(10) << "title";
	cout << setiosflags(ios::left) << setw(15) << "publication";
	cout << setiosflags(ios::left) << setw(10) << "date";
	cout << setiosflags(ios::left) << setw(10) << "type" << endl;
	for (int i = 0; i < (int)p.size(); i++)
		cout << setiosflags(ios::left) << setw(5) << i + 1 << p[i];
	cout << "չʾ���" << endl;
}

void Admin::edit_reference(vector<Reference>& p)
{
	system("cls");
	cout << "�༭����:\n" << endl;
	vector<Reference> temp;
	for (vector<Reference>::iterator it = p.begin(); it != p.end(); it++)
		temp.push_back(*it);
	cout << "������Ҫ�༭���׵�DOI" << endl;
	string Doi; cin >> Doi;
	int t;
	for (int i = 0; i < (int)temp.size(); i++)
	{
		if (temp[i].getDOI() == Doi)
		{
			cout << "�ҵ����½��" << endl;
			cout << temp[i];
			t = i;
			vector<Reference>::iterator it = temp.begin() + t;
			temp.erase(it);
			break;
		}
		if (i == (int)temp.size())
		{
			cout << "δ������DOIΪ" << Doi << "������";
		}
	}
	cout << "������DOI:" << endl;
	string adoi; cin >> adoi;
	cout << "������һ��:" << endl;
	string awriter1; cin >> awriter1;
	cout << "���������:" << endl;
	string awriter2; cin >> awriter2;
	cout << "���������:" << endl;
	string atitle; cin >> atitle;
	cout << "�����뿯��" << endl;
	string apublication; cin >> apublication;
	cout << "���������" << endl;
	int ayear; cin >> ayear;
	cout << "��ѡ�����ͣ�0-Article��1-Review" << endl;
	int atype; cin >> atype;
	if (atype == 0)
	{
		Reference add(adoi, awriter1, awriter2, atitle, apublication, ayear, 0);
		temp.push_back(add);
	}
	else if (atype == 1)
	{
		Reference add(adoi, awriter1, awriter2, atitle, apublication, ayear, 1);
		temp.push_back(add);
	}
	else
	{
		MessageBox(0, "��Ч����ֵ!", "��E��v2.0", 0);
		getchar();
		add_reference(p);
	}
	MessageBox(0, "�޸����", "��E��v2.0", 0);
	getchar();
	p.clear();
	for (vector<Reference>::iterator it = temp.begin(); it != temp.end(); it++)
		p.push_back(*it);
}

void Admin::search_reference(const vector<Reference>& p)
{
	system("cls");
	cout << "��������:" << endl;
	cout << "������Ҫ�������׵�DOI" << endl;
	string Doi; cin >> Doi;
	multimap<string, Reference> m;
	multimap<string, int>::iterator it, p1, p2, pp, begin;
	for (int i = 0; i < (int)p.size(); i++)
	{
		string str = p[i].get_DOI();
		m.insert(make_pair(str, p.at(i)));
	}
	FIND(Doi, m);
	Sleep(500);
	MessageBox(0, "�������", "��E��v2.0", 0);
}

Visitor::Visitor(string a)
{
	una = "Visitot";
	upd = a;
}

Visitor::Visitor(const Visitor& v)
{
	una = "Visitor";
	upd = v.upd;
}

void Visitor::show_reference(const vector<Reference>& p)
{
	system("cls");
	cout << "չʾ����:\n" << endl;
	cout << setiosflags(ios::left) << setw(5) << "num";
	cout << setiosflags(ios::left) << setw(10) << "DOI";
	cout << setiosflags(ios::left) << setw(10) << "author1";
	cout << setiosflags(ios::left) << setw(10) << "author2";
	cout << setiosflags(ios::left) << setw(10) << "title";
	cout << setiosflags(ios::left) << setw(15) << "publication";
	cout << setiosflags(ios::left) << setw(10) << "date";
	cout << setiosflags(ios::left) << setw(10) << "type" << endl;
	for (int i = 0; i < (int)p.size(); i++)
		cout << setiosflags(ios::left) << setw(5) << (i + 1) << p[i];
	MessageBox(0, "չʾ���", "��E��v2.0", 0);
	getchar();
}

void Visitor::search_reference(const vector<Reference>& p)
{
	system("cls");
	cout << "��������:" << endl;
	cout << "������Ҫ�������׵�DOI" << endl;
	string Doi; cin >> Doi;
	multimap<string, Reference> m;
	multimap<string, int>::iterator it, p1, p2, pp, begin;
	for (int i = 0; i < (int)p.size(); i++)
	{
		string str = p[i].get_DOI();
		m.insert(make_pair(str, p.at(i)));
	}
	FIND(Doi, m);
	Sleep(500);
	MessageBox(0, "�������", "��E��v2.0", 0);
	getchar();
}

//ȫ�ֺ������ж���¼�Ϸ���
bool CHECK(string b)
{
	ifstream inFile("Admin_pwd.txt", ios::in);
	if (!inFile)
	{
		MessageBox(0, "��ȡ�ļ�ʧ��! �����·�����ļ��Ƿ����", "��E��v2.0", 0);
		getchar();
		exit(1);
	}
	string line;
	set<string> List;
	List.clear();
	while (getline(inFile, line))
	{
		string str;
		istringstream sin(line);
		//�����ַ���line�����ַ�����sin��
		string re;

		getline(sin, str, ',');
		re = str;
		List.insert(re);
	}
	inFile.close();

	if (List.find(b) != List.end())
		return true;
	else 
		return false;
}

//ȫ�ֺ�������¼����
char LOGON()
{
	Flag1:
	cout << "��ӭʹ����E��������׹���ϵͳ����ѡ���������" << endl;
	cout << "0-Admin, 1-Visitor" << endl;
	char p; cin >> p;
	if (p == '0')
	{
		system("cls");
		cout << "��ѡ��������Admin:" << endl;
		Sleep(500);
		cout << "������������֤���:";
		string pwd; cin >> pwd;

		bool ID = CHECK(pwd);
//		bool ID = true;//����ʱʹ��
		if (ID)
		{
			MessageBox(0, "��½�ɹ�", "��E��v2.0", 0);
			getchar();
		}
		else
		{
			MessageBox(0, "�������, ������һ�λ���, ʧ���Զ��˳�", "��E��v2.0", 0);
			getchar();
			cin >> pwd;
			ID = CHECK(pwd);
			if (ID)
			{
				MessageBox(0, "��½�ɹ�!", "��E��v2.0", 0);
				getchar();
			}
			else
				exit(1);
		}
	}
	else if (p == '1')
	{
		system("cls");
		cout << "��ѡ��������Visitor:" << endl;
		Sleep(500);
		string pwdd = "";
		MessageBox(0, "��½�ɹ�", "��E��v2.0", 0);
		getchar();
	}
	else
	{
		MessageBox(0, "���Ϸ�����������", "��E��v2.0", 0);
		getchar();
		Sleep(1000);
		goto Flag1;
	}
	return p;
}

//ȫ�ֺ���*3���Ƚ�
bool cmp_DOI(Reference a, Reference b)
{
	return a.getDOI() < b.getDOI();
}

bool cmp_date(Reference a, Reference b)
{
	return a.getdate() < b.getdate();
}

bool cmp_title(Reference a, Reference b)
{
	return a.gettitle() < b.gettitle();
}

//ȫ�ֺ�����ģ��ƥ��
void FIND(string a, multimap<string, Reference> b)
{
	int n = a.length();
	bool flag = false;
	cout << "�ҵ����½��:" << endl;
	cout << setiosflags(ios::left) << setw(10) << "DOI";
	cout << setiosflags(ios::left) << setw(10) << "author1";
	cout << setiosflags(ios::left) << setw(10) << "author2";
	cout << setiosflags(ios::left) << setw(10) << "title";
	cout << setiosflags(ios::left) << setw(15) << "publication";
	cout << setiosflags(ios::left) << setw(10) << "date";
	cout << setiosflags(ios::left) << setw(10) << "type" << endl;
	for (multimap<string, Reference>::iterator it = b.begin(); it != b.end(); it++)
	{
			string c = it->first;
			for (int j = 0; j < (int)c.length(); j++)
			{
				if (c.substr(j, n) == a)
				{
					cout << it->second;
					flag = true;
					break;
				}
			}
	}
	if (!flag)
	{
		MessageBox(0, "δ�����������Ϣ", "��E��v2.0", 0);
		getchar();
	}
}