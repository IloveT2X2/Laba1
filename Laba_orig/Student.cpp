#include "Student.h"

Student::Student()
{
	head = nullptr;
	Size = 0;

	cout << "Вызван конструктор без параметров класса Student" << endl;
}

Student::Student(Student& st)
{
	if (st.head == nullptr)
	{
		head = nullptr;
		cout << "Вызван конструктор копирования класса Student" << endl;
		return;
	}

	Node* current = st.head;
	head = new Node();
	head->fullname = current->fullname;
	head->group = current->group;
	head->speciality = current->speciality;
	head->course = current->course;
	head->averegeScore = current->averegeScore;

	Node* newNode = head;
	current = current->pNext;

	while (current != nullptr)
	{
		newNode->pNext = new Node();
		newNode = newNode->pNext;

		newNode->fullname = current->fullname;
		newNode->group = current->group;
		newNode->speciality = current->speciality;
		newNode->course = current->course;
		newNode->averegeScore = current->averegeScore;

		current = current->pNext;
	}

	newNode->pNext = nullptr;

	cout << "Вызван конструктор копирования класса Student" << endl;
}

Student::~Student()
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

void Student::SetData()
{
	string fn;
	int grp;
	string sp;
	int crs;
	float avSc;

	cout << "Введите имя студента: ";
	cin >> fn;

	cout << "Введите группу студента: ";
	cin >> grp;

	cout << "Введите специальность студента: ";
	cin >> sp;

	cout << "Введите курс студента: ";
	cin >> crs;

	cout << "Введите средний балл студента: ";
	cin >> avSc;

	if (head == nullptr)
	{
		head = new Node();
		head->fullname = fn;
		head->group = grp;
		head->speciality = sp;
		head->course = crs;
		head->averegeScore = avSc;
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
		newNode->group = grp;
		newNode->speciality = sp;
		newNode->course = crs;
		newNode->averegeScore = avSc;

		current->pNext = newNode;
	}
	Size++;
}

void Student::GetData()
{
	if (head == nullptr)
		throw runtime_error("Список пуст!");

	Node* current = head;
	int counter = 1;
	while (current != nullptr)
	{
		cout << counter++ << ". " << current->fullname << "\t" << current->group << "\t" << current->speciality << "\t" << current->course << "\t" << current->averegeScore << endl;
		current = current->pNext;
	}
}

void Student::EditData()
{
	setlocale(LC_ALL, "Rus");

	string fn;
	int grp;
	string sp;
	int crs;
	float avSc;
	int n;

	cout << "Введите номер студента, чьи данные вы хотите изменить: ";
	cin >> n;
	while (n > Size || n < 0)
	{
		cout << "Такого элемента нет, введите корректный номер: ";
		cin >> n;
	}

	cout << "Введите имя студента: ";
	cin >> fn;

	cout << "Введите гурппу студента: ";
	cin >> grp;

	cout << "Введите специальность студента: ";
	cin >> sp;

	cout << "Введите курс студента: ";
	cin >> crs;

	cout << "Введите средний балл студента: ";
	cin >> avSc;

	Node* current = head;
	int counter = 1;

	while (current != nullptr)
	{
		if (counter == n)
		{
			current->fullname = fn;
			current->group = grp;
			current->speciality = sp;
			current->course = crs;
			current->averegeScore = avSc;
			break;
		}

		current = current->pNext;
		counter++;
	}
}

Student& Student::operator=(const Student& st)
{
	if (this == &st)
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

	if (st.head == nullptr)
	{
		head = nullptr;
	}
	else
	{
		current = st.head;
		head = new Node();
		head->fullname = current->fullname;
		head->group = current->group;
		head->speciality = current->speciality;
		head->course = current->course;
		head->averegeScore = current->averegeScore;

		Node* newNode = head;
		current = current->pNext;

		while (current != nullptr)
		{
			newNode->pNext = new Node();
			newNode = newNode->pNext;
			newNode->fullname = current->fullname;
			newNode->group = current->group;
			newNode->speciality = current->speciality;
			newNode->course = current->course;
			newNode->averegeScore = current->averegeScore;
			current = current->pNext;
		}

		newNode->pNext = nullptr;
	}

	return *this;
}

void Student::DeleteData()
{
	int n;

	cout << "Введите номер студента, чьи данные вы хотите удалить: ";
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