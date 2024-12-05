#ifndef STUDENT_H
#define STUDENT_H

#include "University.h"
#include <string>


class Student : public University
{
private:
	class Node
	{
	public:
		Node(Node* pNext = nullptr, string fullname = "", int group = 0, string speciality = "", int course = 0, float averageScore = 0)
		{
			cout << "Вызван конструктор с параметрами класса Node" << endl;
		}
		Node* pNext;
		string fullname;
		int group;
		string speciality;
		int course;
		float averegeScore;
	};

	Node* head;
	int Size;

public:
	Student();
	Student(Student& st);
	~Student(); 

	void GetData() override;
	void SetData() override;
	void DeleteData() override;
	void EditData() override;
	Student& operator=(const Student& st);
};

#endif STUDENT_H
