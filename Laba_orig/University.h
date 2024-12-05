#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <string>

using namespace std;

class University
{
public:

	University() { cout << "Вызван виртуальный конструктор абстрактного класса University" << endl; }
	~University() { cout << "Вызван виртуальный деструктор абстрактного класса University" << endl; }

	virtual void GetData() = 0;
	virtual void SetData() = 0;
	virtual void DeleteData() = 0;
	virtual void EditData() = 0;
	
};
#endif UNIVERSITY_H