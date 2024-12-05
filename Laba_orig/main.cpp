#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int num = 0;
	int choice = 0;
	Student st, st1;
	Teacher tch, tch1;
	Admin ad, ad1;

	for (int i = 0; choice !=4 ;)
	{
		cout << endl;
		cout << endl;
		cout << "Выберите, с какими данными хотите работать:" << endl;
		cout << "1. Данные о студентах" << endl;
		cout << "2. Данные о преподавателях" << endl;
		cout << "3. Данные административного персонала" << endl;
		cout << "4. Выход из программы" << endl;
		num = 0;

		cin >> choice;

		switch (choice)
		{
		case 1:
			for (; num != 7;)
			{
				cout << endl;
				cout << endl;
				cout << "1. Добавить новые данные" << endl;
				cout << "2. Вывести данные на экран" << endl;
				cout << "3. Изменить данные" << endl;
				cout << "4. Удалить данные" << endl;
				cout << "5. Скопировать данные" << endl;
				cout << "6. Вывести скопированные данные на экран" << endl;
				cout << "7. Выход из программы" << endl;

				cin >> num;

				switch (num)
				{
				case 1:
					st.SetData();
					cout << "Данные сохранены" << endl;
					break;

				case 2:
					try
					{
						st.GetData();
					}
					catch (const exception& e)
					{
						cerr << "Ошибка: " << e.what() << endl;
					}
					break;

				case 3:
					st.EditData();
					cout << "Данные изменены" << endl;
					break;

				case 4:
					st.DeleteData();
					cout << "Данные удалены" << endl;
					break;

				case 5:
					st1 = st;
					cout << "Копия создана" << endl;
					break;

				case 6:
					st1.GetData();
					break;

				case 7:
					break;

				default:
					cout << "Неккоректная команда" << endl;
					break;
				}
			}

		case 2:
			for (; num != 7;)
			{
				cout << endl;
				cout << endl;
				cout << "1. Добавить новые данные" << endl;
				cout << "2. Вывести данные на экран" << endl;
				cout << "3. Изменить данные" << endl;
				cout << "4. Удалить данные" << endl;
				cout << "5. Скопировать данные" << endl;
				cout << "6. Вывести скопированные данные на экран" << endl;
				cout << "7. Выход из программы" << endl;
				cin >> num;

				switch (num)
				{
				case 1:
					tch.SetData();
					cout << "Данные сохранены" << endl;
					break;

				case 2:
					try
					{
						tch.GetData();
					}
					catch (const exception& e)
					{
						cerr << "Ошибка: " << e.what() << endl;
					}
					break;

				case 3:
					tch.EditData();
					cout << "Данные изменены" << endl;
					break;

				case 4:
					tch.DeleteData();
					cout << "Данные удалены" << endl;
					break;

				case 5:
					tch1 = tch;
					cout << "Копия создана" << endl;
					break;

				case 6:
					tch1.GetData();
					break;

				case 7:
					break;

				default:
					cout << "Неккоректная команда" << endl;
					break;
				}
			}

		case 3:
			for (; num != 7;)
			{
				cout << endl;
				cout << endl;
				cout << "1. Добавить новые данные" << endl;
				cout << "2. Вывести данные на экран" << endl;
				cout << "3. Изменить данные" << endl;
				cout << "4. Удалить данные" << endl;
				cout << "5. Скопировать данные" << endl;
				cout << "6. Вывести скопированные данные на экран" << endl;
				cout << "7. Выход из программы" << endl;
				cin >> num;

				switch (num)
				{
				case 1:
					ad.SetData();
					cout << "Данные сохранены" << endl;
					break;

				case 2:
					try
					{
						ad.GetData();
					}
					catch (const exception& e)
					{
						cerr << "Ошибка: " << e.what() << endl;
					}
					break;

				case 3:
					ad.EditData();
					cout << "Данные изменены" << endl;
					break;

				case 4:
					ad.DeleteData();
					cout << "Данные удалены" << endl;
					break;

				case 5:
					ad1 = ad;
					cout << "Копия создана" << endl;
					break;

				case 6:
					ad1.GetData();
					break;

				case 7:
					break;

				default:
					cout << "Неккоректная команда" << endl;
					break;
				}
			}

		case 4:
			break;

		default:
			cout << "Неккоректное значение" << endl;
			break;
		}
	}
	return 0;
}