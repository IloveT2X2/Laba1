#ifndef ADMIN_H
#define ADMIN_H

#include "University.h"
#include <string>

class Admin : public University
{
private:
	class Node
	{
	public:
		Node(Node* pNext = nullptr, string fullname = "", string position = "", string phoneNumber = "", string areaOfResconsibility = "")
		{
			cout << "Вызван конструктор с параметрами класса Node" << endl;
		}
		Node* pNext;
		string fullname;
		string position;
		string phoneNumber;
		string areaOfResponsibility;
	};
	Node* head;
	int Size;

public:
	Admin();
	Admin(Admin& ad);
	~Admin();

	void SetData() override;
	void GetData() override;
	void EditData() override;
	void DeleteData() override;

	Admin& operator=(const Admin& ad);
};

#endif ADMIN_H
