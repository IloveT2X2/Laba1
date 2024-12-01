#include "Teacher.h"

Teacher::Teacher()
{
	head = nullptr;
	Size = 0;

	cout << "Вызван конструктор без параметров класса Teacher" << endl;
}

Teacher::Teacher(Teacher& tch)
{
	if (tch.head == nullptr)
	{
		head = nullptr;
		cout << "Вызван конструктор копирования класса Student" << endl;
		return;
	}

	Node* current = tch.head;
	head = new Node();
	head->fullname = tch.head->fullname;
	for (int i = 0; tch.head->groups[i] != 0; i++)
	{
		head->groups[i] = tch.head->groups[i];
	}

	for (int i = 0; tch.head->subjects[i] != ""; i++)
	{
		head->subjects[i] = tch.head->subjects[i];
	}

	Node* newNode = head;
	current = current->pNext;

	while (current != nullptr)
	{
		newNode->pNext = new Node();
		newNode = newNode->pNext;

		newNode->fullname = current->fullname;
		for (int i = 0; current->groups[i] != 0; i++)
		{
			newNode->groups[i] = current->groups[i];
		}

		for (int i = 0; current->subjects[i] != ""; i++)
		{
			newNode->subjects[i] = current->subjects[i];
		}

		current = current->pNext;
	}

	newNode->pNext = nullptr;

	cout << "Вызван конструктор копирования класса Teacher" << endl;
}

Teacher::~Teacher()
{
	Node* temp = head;
	while (head != nullptr)
	{
		head = temp->pNext;
		delete temp;
		temp = head;
	}
	cout << "Вызван деструктор класса Teacher" << endl;
}

void Teacher::EditData()
{
	constexpr int num = 100;
	int n, g, e;
	string fn;
	int grps[num];

	for (int i = 0; i < num; ++i)
	{
		grps[i] = 0;
	}

	string subs[num];

	for (int i = 0; i < num; ++i)
	{
		subs[i] = "";
	}

	cout << "Введите номер преподавателя, чьи данные вы хотите изменить: ";
	cin >> e;
	while (e > Size || e < 0)
	{
		cout << "Такого элемента нет, введите корректный номер: ";
		cin >> e;
	}

	cout << "Введите имя преподавателя: ";
	cin >> fn;

	cout << "Введите количество групп преподавателя: ";
	cin >> n;

	cout << "Перечислите группы преподавателя: ";
	for (int i = 0; n > i; i++)
	{
		cin >> g;
		grps[i] = g;
	}

	cout << "Введите количество предметов преподавателя: ";
	cin >> n;

	cout << "Перечислите предметы преподавателя: ";
	for (int i = 0; n > i; i++)
	{
		cin >> subs[i];
	}

	Node* current = head;
	int counter = 1;
	while (current != nullptr)
	{
		if (counter == e)
		{
			current->fullname = fn;
			for (int i = 0; current->groups[i] != 0; i++)
			{
				current->groups[i] = 0;
			}

			for (int i = 0; grps[i] != 0; i++)
			{
				current->groups[i] = grps[i];
			}

			for (int i = 0; current->subjects[i] != ""; i++)
			{
				current->subjects[i] = "";
			}

			for (int i = 0; subs[i] != ""; i++)
			{
				current->subjects[i] = subs[i];
			}
			break;
		}
		current = current->pNext;
		counter++;
	}
}

Teacher& Teacher::operator=(const Teacher& tch)
{
	if (this == &tch)
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

	if (tch.head == nullptr)
	{
		head = nullptr;
	}
	else
	{
		current = tch.head;
		head = new Node();
		head->fullname = current->fullname;
		for (int i = 0; current->groups[i] != 0; i++)
		{
			head->groups[i] = current->groups[i];
		}

		for (int i = 0; current->subjects[i] != ""; i++)
		{
			head->subjects[i] = current->subjects[i];
		}

		Node* newNode = head;
		current = current->pNext;

		while (current != nullptr)
		{
			newNode->pNext = new Node();
			newNode = newNode->pNext;

			newNode->fullname = current->fullname;
			for (int i = 0; current->groups[i] != 0; i++)
			{
				newNode->groups[i] = current->groups[i];
			}

			for (int i = 0; current->subjects[i] != ""; i++)
			{
				newNode->subjects[i] = current->subjects[i];
			}

			current = current->pNext;
		}

		newNode->pNext = nullptr;
	}

	return *this;
}

void Teacher::SetData()
{
	constexpr int num = 100;
	int n, g;
	string fn;
	int grps[num];

	for (int i = 0; i < num; ++i)
	{
		grps[i] = 0;
	}

	string subs[num];

	for (int i = 0; i < num; ++i)
	{
		subs[i] = "";
	}

	cout << "Введите имя преподавателя: ";
	cin >> fn;

	cout << "Введите количество групп преподавателя: ";
	cin >> n;

	cout << "Перечислите группы преподавателя: ";
	for (int i = 0; n > i; i++)
	{
		cin >> g;
		grps[i] = g;
	}

	cout << "Введите количество предметов преподавателя: ";
	cin >> n;

	cout << "Перечислите предметы преподавателя: ";
	for (int i = 0; n > i; i++)
	{
		cin >> subs[i];
	}

	if (head == nullptr)
	{
		head = new Node();
		head->fullname = fn;
		for (int i = 0; grps[i] != 0; i++)
		{
			head->groups[i] = grps[i];
		}

		for (int i = 0; subs[i] != ""; i++)
		{
			head->subjects[i] = subs[i];
		}

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
		for (int i = 0; grps[i] != 0; i++)
		{
			newNode->groups[i] = grps[i];
		}

		for (int i = 0; subs[i] != ""; i++)
		{
			newNode->subjects[i] = subs[i];
		}

		current->pNext = newNode;
	}

	Size++;
}

void Teacher::GetData()
{
	if (head == nullptr)
		throw runtime_error("Список пуст!");

	Node* current = head;
	int counter = 1;
	while (current != nullptr)
	{
		cout << counter << ". " << current->fullname << endl;
		cout << "Группы: ";
		for (int i = 0; current->groups[i] != 0; i++)
		{
			cout << current->groups[i] << "\t";
		}
		cout << endl;

		cout << "Предметы: ";
		for (int i = 0; current->subjects[i] != ""; i++)
		{
			cout << current->subjects[i] << "\t";
		}
		cout << endl;

		current = current->pNext;
		counter++;
	}
}

void Teacher::DeleteData()
{
	int n;

	cout << "Введите номер преподавателя, чьи данные вы хотите удалить: ";
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
		if (counter == n)
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