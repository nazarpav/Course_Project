/*Предметна область - відділ продуктів в магазині.
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
Для обробки даних скористатися динамічним масивом покажчиків на структури відповідного типу.*/
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
	string Department;
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
	void Set_Department(string new_Department)
	{
		this->Department = new_Department;
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
	unsigned short Get_Quantity_in_stock()
	{
		return this->Quantity_in_stock;
	}
	unsigned short Get_Cost_in_CU()
	{
		return this->Cost_in_CU;
	}
	unsigned short Get_Cost_in_UAN()
	{
		return this->Cost_in_UAN;
	}
	string Get_Department()
	{
		return this->Department;
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
class Menu_database
{
	unsigned short menu_db(Product *&product, unsigned short &Quantity_Products)
	{
		unsigned short choise = 1;
		char Control_Symbol{};
		const unsigned short size = 10;
		string menu[size]
		{
			"Bread department",
			"Pastry Department",
			"Dairy department",
			"Meat section",
			"Sausage department",
			"Fish department",
			"Grocery department",
			"Department of drinks",
			"Semi-finished products",
			"Fruit and vegetable"
		};
		while (Control_Symbol != 13)
		{
			Control_Symbol = _getch();
			if (Control_Symbol != 72 && Control_Symbol != 80)
			{
				continue;
			}
			else
			{
				Control_Symbol == 72 ? choise-- : choise++;
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
		return choise;

	}
public:
	unsigned short Get_menu_db(Product *&product, unsigned short &Quantity_Products)
	{
		return menu_db(product, Quantity_Products);
	}
};
class W_W_D
{
	Menu_database menu_DB;
public:
	void Get_Memory(Product *&product, unsigned short &Quantity_Products)
	{
		product = new Product[Quantity_Products];
	}
	void Add_item_Data_Product(Product *&product, unsigned short &Quantity_Products)
	{
		Quantity_Products++;

		/*Product * new_product=new Product[Quantity_Products+1];
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
		}
			cout<<new_product<<endl;
			cout<<product<<endl;
			system("pause");*/
		product = (Product*)realloc(product, Quantity_Products * sizeof(Product));
		unsigned short new_Quantity_in_stock;
		const string block_database = "Bread departmen\t\t1\nPastry Department\t2\nDairy department\t3\nMeat section\t\t4\nSausage department\t5\nFish department\t\t6\nGrocery department\t7\nDepartment of drinks\t8\nSemi-finished products\t9\nFruit and vegetable\t10\n";
		unsigned short new_Cost_in_CU;
		string new_Manufacturing_plant;
		string new_Description;
		string new_Products_Name;
		unsigned int new_Department;
		switch (menu_DB.Get_menu_db(product, Quantity_Products))
		{
		case 1:
			product[Quantity_Products - 1].Set_Department("Bread departmen");
			break;
		case 2:
			product[Quantity_Products - 1].Set_Department("Pastry Department");
			break;
		case 3:
			product[Quantity_Products - 1].Set_Department("Dairy department");
			break;
		case 4:
			product[Quantity_Products - 1].Set_Department("Meat section");
			break;
		case 5:
			product[Quantity_Products - 1].Set_Department("Sausage department");
			break;
		case 6:
			product[Quantity_Products - 1].Set_Department("Fish department");
			break;
		case 7:
			product[Quantity_Products - 1].Set_Department("Grocery department");
			break;
		case 8:
			product[Quantity_Products - 1].Set_Department("Department of drinks");
			break;
		case 9:
			product[Quantity_Products - 1].Set_Department("Semi - finished products");
			break;
		case 10:
			product[Quantity_Products - 1].Set_Department("Fruit and vegetable");
			break;
		}
		cout << "Enter name product> \n" << product << "\n";
		cin >> new_Products_Name;
		product[Quantity_Products - 1].Set_Products_Name(new_Products_Name);

		cout << "Enter Quantity in stock> ";
		cin >> new_Quantity_in_stock;
		product[Quantity_Products - 1].Set_Quantity_in_stock(new_Quantity_in_stock);

		cout << "Enter Cost in CU> ";
		cin >> new_Cost_in_CU;
		product[Quantity_Products - 1].Set_Cost_in_CU(new_Cost_in_CU);

		cout << "Enter Manufacturingplant> ";
		cin >> new_Manufacturing_plant;
		product[Quantity_Products - 1].Set_Manufacturing_plant(new_Manufacturing_plant);

		cout << "Enter Description product> ";
		cin >> new_Description;
		product[Quantity_Products - 1].Set_Description(new_Description);
	}
	void reduct_product(Product *&product, unsigned short &Quantity_Products)
	{
		unsigned short new_Quantity_in_stock;
		unsigned short new_Cost_in_CU;
		string new_Manufacturing_plant;
		string new_Description;
		string new_Products_Name;
		string departament;
		const string block_database = "Bread departmen\t\t1\nPastry Department\t2\nDairy department\t3\nMeat section\t\t4\nSausage department\t5\nFish department\t\t6\nGrocery department\t7\nDepartment of drinks\t8\nSemi-finished products\t9\nFruit and vegetable\t10\n";
		system("cls");
		cout << "Enter Departament\t\t"<<block_database<<"\n -> ";
		cin >> departament;
		cout << "Enter name product> \n" << product << "\n";
		cin >> new_Products_Name;
		product[Quantity_Products - 1].Set_Products_Name(new_Products_Name);

		cout << "Enter Quantity in stock> ";
		cin >> new_Quantity_in_stock;
		product[Quantity_Products - 1].Set_Quantity_in_stock(new_Quantity_in_stock);

		cout << "Enter Cost in CU> ";
		cin >> new_Cost_in_CU;
		product[Quantity_Products - 1].Set_Cost_in_CU(new_Cost_in_CU);

		cout << "Enter Manufacturingplant> ";
		cin >> new_Manufacturing_plant;
		product[Quantity_Products - 1].Set_Manufacturing_plant(new_Manufacturing_plant);

		cout << "Enter Description product> ";
		cin >> new_Description;
		product[Quantity_Products - 1].Set_Description(new_Description);
	}
	void search_product(Product *&product, unsigned short &Quantity_Products, unsigned short &Departament)
	{

	}
	void Del_Product(Product *&product, unsigned short &Quantity_Products)
	{
		Quantity_Products++;
		Product * new_product = new Product[Quantity_Products + 1];
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			new_product[i].Set_Cost_in_CU(product[i].Get_Cost_in_CU());
			new_product[i].Set_Department(product[i].Get_Department());
			new_product[i].Set_Description(product[i].Get_Description());
			new_product[i].Set_Manufacturing_plant(product[i].Get_Manufacturing_plant());
			new_product[i].Set_Products_Name(product[i].Get_Products_Name());
			new_product[i].Set_Quantity_in_stock(product[i].Get_Quantity_in_stock());
		}
			system("pause");
		//product = (Product*)realloc(product, Quantity_Products * sizeof(Product));
		string Products_Name;
		bool tmp = false;
		string departament;
		unsigned short index = 0;
		unsigned short new_Quantity_in_stock;
		const string block_database = "Bread departmen\t\t1\nPastry Department\t2\nDairy department\t3\nMeat section\t\t4\nSausage department\t5\nFish department\t\t6\nGrocery department\t7\nDepartment of drinks\t8\nSemi-finished products\t9\nFruit and vegetable\t10\n";
		switch (menu_DB.Get_menu_db(product, Quantity_Products))
		{
		case 1:
			departament = "Bread departmen";
			break;
		case 2:
			departament = "Pastry Department";
			break;
		case 3:
			departament = "Dairy department";
			break;
		case 4:
			departament = "Meat section";
			break;
		case 5:
			departament = "Sausage department";
			break;
		case 6:
			departament = "Fish department";
			break;
		case 7:
			departament = "Grocery department";
			break;
		case 8:
			departament = "Department of drinks";
			break;
		case 9:
			departament = "Semi - finished products";
			break;
		case 10:
			departament = "Fruit and vegetable";
			break;
		}
		for (unsigned short i = 0; tmp != true; i++)
		{
			cout << "Enter name product> \n" << product << "\n";
			cin >> Products_Name;
			if (Products_Name == product[i].Get_Products_Name())
			{
				tmp = true;
				index == i;
			}
		}
		if (tmp == true)
		{

		}
		//product[Quantity_Products - 1].Set_Products_Name(Products_Name);
	}
	void Show_Product(Product *&product, unsigned short &Quantity_Products)
	{
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			cout << product << endl;
			cout << "ALL Products>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n" << "Departament => " << product[i].Get_Department() << "\nProduct > " << product[i].Get_Products_Name() << "\nCost in CU > " << product[i].Get_Cost_in_CU() << "\nCost in UAN > " << product[i].Get_Cost_in_UAN() << "\nQantity in stok> " << product[i].Get_Quantity_in_stock() << "\nManufacturing plant> " << product[i].Get_Manufacturing_plant() << "\nDescription>" << product[i].Get_Description() << endl;
			system("pause");
		}
	}
};

class menu
{
protected:
	string text_to_search{};
	Menu_database menu_DB_;
	unsigned short departament = 0;
	void Menu_Private(W_W_D &work_with_database, Product *&product, unsigned short &Quantity_Products, bool &var)
	{
		unsigned short choise = 1;
		char Control_Symbol{};
		const unsigned short size = 7;
		string menu[size]
		{
			"Show ALL Products",
			"Add item Data base",
			"Set product size",
			"Delete product",
			"Redact product",
			"Search product",
			"Exit"
		};

		while (Control_Symbol != 13)
		{
			Control_Symbol = _getch();
			if (Control_Symbol != 72 && Control_Symbol != 80)
			{
				continue;
			}
			else
			{
				Control_Symbol == 72 ? choise-- : choise++;
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
			work_with_database.Add_item_Data_Product(product, Quantity_Products);
			break;
		case 3:
			cout << "Enter Quantity Products> ";
			cin >> Quantity_Products;
			work_with_database.Get_Memory(product, Quantity_Products);
			break;
		case 4:
			system("cls");
			cout << "[ Bread department ]\nPastry Department\nDairy department\nMeat section\nSausage department\nFish department\nGrocery department\nDepartment of drinks\nDepartment of semi - finished products\nFruit and vegetable department\n";
			work_with_database.Del_Product(product, Quantity_Products);
			break;
		case 5:
			/*cout << "[ Bread department ]\nPastry Department\nDairy department\nMeat section\nSausage department\nFish department\nGrocery department\nDepartment of drinks\nDepartment of semi - finished products\nFruit and vegetable department\n";
			departament = menu_DB_.Get_menu_db(product, Quantity_Products);*/
			work_with_database.reduct_product(product, Quantity_Products);
			break;
		case 6:
			cout << "Enter text to searchs-> \n";
			cin >> text_to_search;
			work_with_database.search_product(product, Quantity_Products, departament);
			break;
		case 7:
			var = false;
			break;
		default:
			cout << "Eror!!!\n";
			break;
		}
	}
public:
	void Menu(W_W_D &work_with_database, Product *&product, unsigned short &Quantity_Products, bool &var)
	{
		Menu_Private(work_with_database, product, Quantity_Products, var);
	}
};

int main()
{
	srand(unsigned(time(NULL)));
	menu Menu;
	Product *product = nullptr;
	unsigned short Quantity_Products = 0;
	W_W_D work_with_database;
	bool var = true;
	while (var)
	{
		system("cls");
		cout << "[ Show ALL Products ]\nAdd item Data base\nSet product size\nDelete product\nRedact product\nSearch product\nExit\n";
		Menu.Menu(work_with_database, product, Quantity_Products, var);
	}

	return 0;
}

/*
72-> UP
75-> LEFT
77-> RIGHT
80-> DOWN
*/
