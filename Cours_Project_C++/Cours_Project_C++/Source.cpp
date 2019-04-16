/*C++
Предметна область - відділ продуктів в магазині.
Розв'язувані задачі: видача зведень про товари (опис, ціна в грн. і у.о., кількість на складі, марка тощо) .Реалізувати наступні сервіси:
Заповнення бази даних
Перегляд усіх даних
Доповнення бази даних новим записом
Видалення із бази даних
Упорядкування по полях: тип товару, ціна
Пошук: товару фабрика-виробник ХХ
Вибірка: принтери за ціною не більш Y; товари, яких на складі залишилося менше 5 штук
Корекція: зміна ціни в гривнях, у зв'язку зі зміною курсу долара
Табличний звіт: інформація про товари; упорядкування по типах(окремо - ковбаси, риба, овочі тощо)
Додаткові вимоги: перевірка на введення ціни товару (повинна бути більше 0 грн.), а також на те, щоб ціна в грн. відповідала ціні в у.о.
Для обробки даних скористатися динамічним масивом покажчиків на структури відповідного типу. */
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <conio.h>
using namespace std;
class  Product
{
private:
	const unsigned short Rate_of_conventional_units = 20;
	unsigned short Cost_in_UAN = Cost_in_CU * Rate_of_conventional_units;
	string Manufacturing_plant;
	string Description;
	string Products_Name;
	unsigned short Quantity_in_stock;
	unsigned short Cost_in_CU;
public:
	void Set_Quantity_in_stock(int new_Quantity_in_stock)
	{
		this->Quantity_in_stock = new_Quantity_in_stock;
	}
	void Set_Cost_in_CU(int new_Cost_in_CU)
	{
		this->Cost_in_CU = new_Cost_in_CU;
	}
	void Set_Manufacturing_plant(string new_Manufacturing_plant)
	{
		this->Manufacturing_plant = new_Manufacturing_plant;
	}
	void Set_Description(string new_Description)
	{
		this->Description = new_Description;
	}
	void Set_Products_Name(string new_Products_Name)
	{
		this->Products_Name = new_Products_Name;
	}
	int Get_Quantity_in_stock()
	{
		return this->Quantity_in_stock;
	}
	int Get_Cost_in_CU()
	{
		return this->Cost_in_CU;
	}
	string Get_Manufacturing_plant()
	{
		return this->Manufacturing_plant;
	}
	string Get_Description()
	{
		return this->Description;
	}
	string Get_Products_Name()
	{
		return this->Products_Name;
	}
};
//class Departament
//{
//	Product* get_product()
//	{
//		return 0;
//	}
//};
class W_W_D
{
public:
	void Get_Memory(Product *&product, unsigned short &Quantity_Products)
	{
		product = new Product[Quantity_Products];
	}
	void Enter_Data_Product(Product product[], unsigned short &Quantity_Products)
	{
		unsigned short new_Quantity_in_stock;
		unsigned short new_Cost_in_CU;
		string new_Manufacturing_plant;
		string new_Description;
		string new_Products_Name;
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			cout << "Enter name product> \n" << product << "\n";
			cin >> new_Products_Name;
			product[i].Set_Products_Name(new_Products_Name);

			cout << "Enter Quantity in stock> ";
			cin >> new_Quantity_in_stock;
			product[i].Set_Quantity_in_stock(new_Quantity_in_stock);

			cout << "Enter Cost in CU> ";
			cin >> new_Cost_in_CU;
			product[i].Set_Cost_in_CU(new_Cost_in_CU);

			cout << "Enter Manufacturingplant> ";
			cin >> new_Manufacturing_plant;
			product[i].Set_Manufacturing_plant(new_Manufacturing_plant);

			cout << "Enter Description product> ";
			cin >> new_Description;
			product[i].Set_Description(new_Description);
		}
	}
	void Show_Product(Product product[], unsigned short &Quantity_Products)
	{
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			cout << product << endl;
			cout << "ALL Products>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\nProduct >" << product[i].Get_Products_Name() << "\nCost in CU > " << product[i].Get_Cost_in_CU() << "\nQantity in stok> " << product[i].Get_Quantity_in_stock() << "\nManufacturing plant> " << product[i].Get_Manufacturing_plant() << "\nDescription>" << product[i].Get_Description() << endl;
			system("pause");
		}
	}
};
class menu
{
protected:
	void Menu_Private(W_W_D &work_with_database, Product *&product, unsigned short &Quantity_Products)
	{
		unsigned short choise = 1;
		char Control_Symbol{};
		const unsigned short size = 6;
		string menu[size]
		{
			"Show ALL Products",
			"Enter ALL Data base",
			"Set product size",
			"______________",
			"______________",
			"______________"
		};
		while (Control_Symbol != 13)
		{
			Control_Symbol = _getch();
			if (Control_Symbol != 119 && Control_Symbol != 115)
			{
				continue;
			}
			else
			{
				Control_Symbol == 119 ? choise-- : choise++;
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
			work_with_database.Show_Product(product, Quantity_Products);
			break;
		case 2:
			work_with_database.Enter_Data_Product(product, Quantity_Products);
			break;
		case 3:
			cout << "Enter Quantity Products> ";
			cin >> Quantity_Products;
			work_with_database.Get_Memory(product, Quantity_Products);
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
	void Menu(W_W_D &work_with_database, Product *&product, unsigned short &Quantity_Products)
	{
		Menu_Private(work_with_database, product, Quantity_Products);
	}
};

int main()
{
	srand(unsigned(time(NULL)));
	menu Menu;
	Product *product = NULL;
	unsigned short Quantity_Products = 0;
	W_W_D work_with_database;
	while (true)
	{
		system("cls");
		cout << "[ Show ALL Products ]\nEnter ALL Data base\nSet product size\n______________\n______________\n______________\n";
		Menu.Menu(work_with_database, product, Quantity_Products);
	}




	system("pause");
	return 0;
}