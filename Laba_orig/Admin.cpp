#include "Admin.h"

Admin::Admin()
{
	head = nullptr;
	Size = 0;

	cout << "Вызван конструктор без параметров класса Admin" << endl;
}

Admin::Admin(Admin& ad)
{
	if (ad.head == nullptr)
	{
		head = nullptr;
		cout << "Вызван конструктор копирования класса Admin" << endl;
		return;
	}

	Node* current = ad.head;
	head = new Node();
	head->fullname = current->fullname;
	head->position = current->position;
	head->phoneNumber = current->phoneNumber;
	head->areaOfResponsibility = current->areaOfResponsibility;

	Node* newNode = head;
	current = current->pNext;

	while (current != nullptr)
	{
		newNode->pNext = new Node();
		newNode = newNode->pNext;

		newNode->fullname = current->fullname;
		newNode->position = current->position;
		newNode->phoneNumber = current->phoneNumber;
		newNode->areaOfResponsibility = current->areaOfResponsibility;

		current = current->pNext;
	}

	newNode->pNext = nullptr;

	cout << "Вызван конструктор копирования класса Admin" << endl;
}

Admin::~Admin()
{
	Node* temp = head;
	while (head != nullptr)
	{
		head = temp->pNext;
		delete temp;
		temp = head;
	}
	cout << "Вызван деструктор класса Student" << endl;
}

void Admin::SetData()
{
	string fn;
	string psn;
	string pn;
	string aor;

	cout << "Введите ФИО административного работника: ";
	cin >> fn;

	cout << "Введите должность административного работника: ";
	cin >> psn;

	cout << "Введите телефон административного работника: ";
	cin >> pn;

	cout << "Введите область ответственности административного работника: ";
	cin >> aor;

	if (head == nullptr)
	{
		head = new Node();
		head->fullname = fn;
		head->position = psn;
		head->phoneNumber = pn;
		head->areaOfResponsibility = aor;
		head->pNext = nullptr;
	}
	else
	{
		Node* current = head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		Node* newNode = new Node();

		newNode->fullname = fn;
		newNode->position = psn;
		newNode->phoneNumber = pn;
		newNode->areaOfResponsibility = aor;

		current->pNext = newNode;
	}
	Size++;
}

void Admin::GetData()
{
	if (head == nullptr)
		throw runtime_error("Список пуст!");

	Node* current = head;
	int counter = 1;
	while (current != nullptr)
	{
		cout << counter++ << ". " << current->fullname << "\t" << current->position << "\t" << current->phoneNumber << "\t" << current->areaOfResponsibility << endl;
		current = current->pNext;
	}
}

void Admin::EditData()
{
	int n;
	string fn;
	string psn;
	string pn;
	string aor;

	cout << "Введите номер административного работника, чьи данные вы хотите изменить: ";
	cin >> n;
	while (n > Size || n < 0)
	{
		cout << "Такого элемента нет, введите корректный номер: ";
		cin >> n;
	}

	cout << "Введите ФИО административного работника: ";
	cin >> fn;

	cout << "Введите должность административного работника: ";
	cin >> psn;

	cout << "Введите телефон административного работника: ";
	cin >> pn;

	cout << "Введите область ответственности административного работника: ";
	cin >> aor;

	Node* current = head;
	int counter = 1;

	while (current != nullptr)
	{
		if (counter == n)
		{
			current->fullname = fn;
			current->position = psn;
			current->phoneNumber = pn;
			current->areaOfResponsibility = aor;
			break;
		}

		current = current->pNext;
		counter++;
	}
}

void Admin::DeleteData()
{
	int n;

	cout << "Введите номер административного работника, чьи данные вы хотите удалить: ";
	cin >> n;
	while (n > Size || n < 0)
	{
		cout << "Такого элемента нет, введите корректный номер: ";
		cin >> n;
	}

	Node* current = head;
	Node* temp = current->pNext;
	int counter = 1;
	while (current->pNext != nullptr)
	{
		if (n == 1)
		{
			head = temp;
			delete current;
			Size--;
			break;
		}
		counter++;

		if (counter == n)
		{
			current->pNext = temp->pNext;
			delete temp;
			Size--;
			break;
		}
		current = current->pNext;
		temp = temp->pNext;
	}
}

Admin& Admin::operator=(const Admin& ad)
{
	if (this == &ad)
	{
		return *this;
	}

	Node* current = head;
	while (current != nullptr)
	{
		Node* toDelete = current;
		current = current->pNext;
		delete toDelete;
	}

	if (ad.head == nullptr)
	{
		head = nullptr;
	}
	else
	{
		current = ad.head;
		head = new Node();
		head->fullname = current->fullname;
		head->position = current->position;
		head->phoneNumber = current->phoneNumber;
		head->areaOfResponsibility = current->areaOfResponsibility;
		
		Node* newNode = head;
		current = current->pNext;

		while (current != nullptr)
		{
			newNode->pNext = new Node();
			newNode = newNode->pNext;
			newNode->fullname = current->fullname;
			newNode->position = current->position;
			newNode->phoneNumber = current->phoneNumber;
			newNode->areaOfResponsibility = current->areaOfResponsibility;
			current = current->pNext;
		}

		newNode->pNext = nullptr;
	}

	return *this;
}
