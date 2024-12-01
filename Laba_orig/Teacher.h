#ifndef TEACHER_H
#define TEACHER_H
#include "University.h"
#include <string>

class Teacher : public University
{
private:
	class Node
	{
	public:
		static const int num = 100;

		Node(Node* pNext = nullptr, string fullname = "", int groups[num] = nullptr, string subjects[num] = nullptr)
		{
			for (int i = 0; i < num; ++i)
			{
				this->groups[i] = 0;
			}

			for (int i = 0; i < num; ++i)
			{
				this->subjects[i] = "";
			}

			cout << "Вызван конструктор с параметрами класса Node" << endl;
		}
		Node* pNext;
		string fullname;
		int groups[num];
		string subjects[num];
	};

	Node* head;
	int Size;

public:
	Teacher();
	Teacher(Teacher& tch);
	~Teacher();

	void GetData() override;
	void SetData() override;
	void DeleteData() override;
	void EditData() override;

	Teacher& operator=(const Teacher& tch);
};
#endif TEACHER_H
