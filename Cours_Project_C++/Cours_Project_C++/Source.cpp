/*C++ 
Предметна область - відділ продуктів в магазині. 
Розв'язувані задачі: видача зведень про товари (опис, ціна в грн. і у.о., кількість на складі, марка тощо) .Реалізувати наступні сервіси: 
Заповнення бази даних 
Перегляд усіх даних 
Доповнення бази даних новим записом 
Видалення із бази даних 
Упорядкування по полях: тип товару, ціна 
Пошук: характеристики комп'ютера марки ХХ 
Вибірка: принтери за ціною не більш Y; товари, яких на складі залишилося менше 5 штук 
Корекція: зміна ціни в гривнях, у зв'язку зі зміною курсу долара 
Табличний звіт: інформація про товари; упорядкування по типах (окремо - принтери, комп'ютери, монітори тощо) 
Додаткові вимоги: перевірка на введення ціни товару (повинна бути більше 0 грн.), а також на те, щоб ціна в грн. відповідала ціні в у.о.
Для обробки даних скористатися динамічним масивом покажчиків на структури відповідного типу. */
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <conio.h>
using namespace std;

class menu
{
protected:
	void MenuPrivate()
	{
		unsigned short choise = 3;
		char ControlSymbol{};
		const unsigned short size = 6;
		string menu[size]
		{
			"11111111111111",
			"22222222222222",
			"33333333333333",
			"44444444444444",
			"55555555555555",
			"66666666666666"
		};
			while (ControlSymbol != 13)
			{
				ControlSymbol = _getch();
				if (ControlSymbol != 119 && ControlSymbol != 115)
				{
					continue;
				}
				else
				{
					ControlSymbol == 119 ? choise-- : choise++;
					if (choise == 0)
					{
						choise++;
						continue;
					}
					else if (choise > size)
					{
						choise--;
						continue;
					}
				}
				system("cls");
				for (unsigned short i = 0; i < size; i++)
				{
					if (i + 1 == choise)
					{
						cout << "[ " << menu[i] << " ]" << endl;
						continue;
					}
					cout << menu[i] << endl;
				}

			}
			switch (choise)
			{
			case 1:
				cout << "1\n";
				break;
			case 2:
				cout << "2\n";
				break;
			case 3:
				cout << "3\n";
				break;
			case 4:
				cout << "4\n";
				break;
			case 5:
				cout << "5\n";
				break;
			case 6:
				cout << "6\n";
				break;
			default:
				cout << "Eror!!!\n";
				break;
			}
	}
public:
	void Menu()
	{
		MenuPrivate();
	}
};
int main()
{
	srand(unsigned(time(NULL)));
	menu Menu;
	Menu.Menu();
		
	
	system("pause");
	return 0;
}