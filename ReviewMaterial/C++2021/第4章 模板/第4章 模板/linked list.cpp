#include<iostream>
#include<string>
using namespace std;

struct Student{
	string no;
	string name;
	double score;
	Student * next;
};

int main(){
	Student * head = NULL, * tail = NULL;
	double total_score = 0.0;
	int stu_number = 0;
	while (1){
		Student * p  = new Student;
		cin >> p->no >> p->name >> p->score;
		p->next = NULL;
		if (p->score < 0){
			delete p;
			p = NULL;
			break;
		}
		else{
			if (head == NULL)
				head = tail = p;
			else{
				tail->next = p;
				tail = p;
			}
			total_score += p->score;
			stu_number++;
		}
	}

	cout << "average score: " << total_score / stu_number << endl;

	Student * temp = NULL;
	while (head != NULL){
		temp = head;
		head = head->next;
		delete temp;
	}

	return 0;
}



++++++++++++++++++++++++++++++

#include<iostream>
#include<string>
using namespace std;

typedef struct node{
	string no;
	string name;
	double score;
	node * next;
} node;

int main(){
	node * head = NULL, * tail = NULL;
	double total_score = 0.0;
	int stu_number = 0;
	while (1){
		node * p  = new node;
		cin >> p->no >> p->name >> p->score;
		p->next = NULL;
		if (p->score < 0){
			delete p;
			p = NULL;
			break;
		}
		else{
			if (head == NULL)
				head = tail = p;
			else{
				tail->next = p;
				tail = p;
			}
			total_score += p->score;
			stu_number++;
		}
	}

	cout << "average score: " << total_score / stu_number << endl;

	node * temp = NULL;
	while (head != NULL){
		temp = head;
		head = head->next;
		delete temp;
	}

	return 0;
}