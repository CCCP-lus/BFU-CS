#include <iostream>
using namespace std;

template <class T>
class List{
private:
	T data;
	List * next;
	static List * tail;      //指向最后一个结点
	static List * head;      //指向头结点
public:
	List() :next(NULL)                  //构造头结点
	{
		head = tail = this;
	}
	List(T newnode) :data(newnode), next(NULL)    //构造新结点
	{}
	void append(T node);               //往后面添加结点
	bool insert(T node, T posnode);   //在结点posnode第一次出现的后面插入新结点, 插入成功返回true，否则false
	void deleteNode(T node);          //删除结点,注意可能有多个相同的结点需要删除
	void delList();                   //删除整个链表
	void dispList();                  //显示链表
};

template <class T>
List<T> * List<T>::tail = NULL;

template <class T>
List<T> * List<T>::head = NULL;

template <class T>
void List<T>::append(T node)
{
	tail->next = new List(node);
	tail = tail->next;
}

template <class T>
bool List<T>::insert(T node, T posnode)
{
	for (List * find = head->next; find != NULL; find = find->next)
		if (find->data == posnode)       //找到了插入的位置
		{
			List * temp = new List(node);
			if (find->next == NULL)         //posnode是最后一个结点，此时需要修改tail
			{
				find->next = tail = temp;
				return true;
			}
			else{                            //不是最后一个结点，只是中间结点,不需要修改tail
				temp->next = find->next;
				find->next = temp;
				return true;
			}
		}
	return false;
}

template <class T>
void List<T>::deleteNode(T node)
{
	List * find = head->next, *pre = head;
	while (find != NULL)
	{
		if (find->data == node)
		{
			if (find->next == NULL)         //要删除的是最后一个结点，需要修改tail
			{
				pre->next = NULL;
				tail = pre;
				delete find;
				find = NULL;
			}
			else{                      //要删除的不是最后一个结点
				pre->next = find->next;
				delete find;
				find = pre->next;
			}
		}
		else{                        //不是需要删除的结点
			pre = find;
			find = find->next;
		}
	}
}

template <class T>
void List<T>::delList()
{
	List * current = head->next;
	List * temp;
	while (current != NULL)
	{
		temp = current;
		head->next = current->next;
		current = current->next;
		delete temp;
	}
	tail = head;
	head->next = NULL;
}

template <class T>
void List<T>::dispList()
{
	for (List * temp = head->next; temp != NULL; temp = temp->next)
		cout << temp->data << " ";
	cout << endl;
}

int main()
{
	List<int> list1;
	list1.append(1);
	list1.deleteNode(1);
	list1.append(2);
	list1.append(3);
	list1.append(4);
	list1.insert(10, 2);
	list1.append(5);
	list1.append(3);
	list1.append(3);
	list1.dispList();
	list1.deleteNode(3);
	list1.dispList();
	list1.delList();
	list1.dispList();

	List<char> list2;
	list2.append('A');
	list2.append('B');
	list2.append('C');
	list2.append('D');
	list2.insert('E', 'B');
	list2.insert('F', 'D');
	list2.append('G');
	list2.append('G');
	list2.append('G');
	list2.dispList();
	list2.deleteNode('G');
	list2.dispList();
	list2.delList();
	list2.dispList();

	return 0;
}