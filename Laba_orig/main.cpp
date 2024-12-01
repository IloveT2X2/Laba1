#include <iostream>
#include "Student.h"
#include "Teacher.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	Student st, st1;
	Teacher tch, tch1;

	for (int choice = 0; choice != 3;)
	{
		cout << endl;
		cout << endl;
		cout << "Выберите, с какими данными хотите работать:" << endl;
		cout << "1. Данные о студентах" << endl;
		cout << "2. Данные о преподавателях" << endl;
		cout << "3. Выход из программы" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			for (int num = 0; num != 7;)
			{
				cout << endl;
				cout << endl;
				cout << "1. Добавить новые данные" << endl;
				cout << "2. Вывести данные на экран" << endl;
				cout << "3. Изменить данные" << endl;
				cout << "4. Удалить данные" << endl;
				cout << "5. Скопировать данные" << endl;
				cout << "6. Вывести скопированные данные на экран" << endl;
				cout << "7. Выход из данных" << endl;

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
			break;

		case 2:
			for (int num = 0; num != 7;)
			{
				cout << endl;
				cout << endl;
				cout << "1. Добавить новые данные" << endl;
				cout << "2. Вывести данные на экран" << endl;
				cout << "3. Изменить данные" << endl;
				cout << "4. Удалить данные" << endl;
				cout << "5. Скопировать данные" << endl;
				cout << "6. Вывести скопированные данные на экран" << endl;
				cout << "7. Выход из данных" << endl;
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
			break;

		case 3:
			break;

		default:
			cout << "Неккоректное значение" << endl;
			break;
		}
	}
	return 0;
}
