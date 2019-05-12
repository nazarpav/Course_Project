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
#include <windows.h>
using namespace std;
class  Product
{
private:
	const unsigned short Rate_of_conventional_units = 20;
	float Cost_in_UAN;
	string Department;
	string Manufacturing_plant;
	string Description;
	string Products_Name;
	unsigned short Quantity_in_stock;
	float Cost_in_CU;
public:
	void Set_UAN()
	{
		Cost_in_UAN = Cost_in_CU * Rate_of_conventional_units;
	}
	void Set_Quantity_in_stock(int new_Quantity_in_stock)
	{
		this->Quantity_in_stock = new_Quantity_in_stock;
	}
	void Set_Department(string new_Department)
	{
		this->Department = new_Department;
	}
	void Set_Cost_in_CU(float new_Cost_in_CU)
	{
		this->Cost_in_CU = new_Cost_in_CU;
		Set_UAN();
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
	float Get_Cost_in_CU()
	{
		return this->Cost_in_CU;
	}
	float Get_Cost_in_UAN()
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

		Product * new_product = new Product[Quantity_Products + 1];
		for (unsigned short i = 0; i < Quantity_Products - 1; i++)
		{
			new_product[i].Set_Cost_in_CU(product[i].Get_Cost_in_CU());
			new_product[i].Set_Department(product[i].Get_Department());
			new_product[i].Set_Description(product[i].Get_Description());
			new_product[i].Set_Manufacturing_plant(product[i].Get_Manufacturing_plant());
			new_product[i].Set_Products_Name(product[i].Get_Products_Name());
			new_product[i].Set_Quantity_in_stock(product[i].Get_Quantity_in_stock());
		}
		delete[] product;
		product = new_product;
		unsigned short new_Quantity_in_stock;
		const string block_database = "[ Bread department ]\nPastry Department\nDairy department\nMeat section\nSausage department\nFish department\nGrocery department\nDepartment of drinks\nDepartment of semi - finished products\nFruit and vegetable department\n";
		float new_Cost_in_CU;
		string new_Manufacturing_plant;
		string new_Description;
		string new_Products_Name;
		system("cls");
		cout << block_database;
		switch (menu_DB.Get_menu_db(product, Quantity_Products))
		{
		case 1:
			product[Quantity_Products - 1].Set_Department("Bread department");
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
		system("cls");
		cout << "Enter name product> \n";
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
		float new_Cost_in_CU;
		string new_Manufacturing_plant;
		string new_Description;
		string new_Products_Name;
		string departament;
		const string block_database = "[ Bread department ]\nPastry Department\nDairy department\nMeat section\nSausage department\nFish department\nGrocery department\nDepartment of drinks\nDepartment of semi - finished products\nFruit and vegetable department\n";
		system("cls");
		cout << block_database;
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
		system("cls");
		string search_name_product{};
		cout << "Enter name product> \n";
		cin >> search_name_product;
		unsigned short iterator = 0;
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			if (product[i].Get_Products_Name() == search_name_product && departament == product[i].Get_Department())
			{
				iterator = i;
				break;
			}
		}
		system("cls");
		cout << "Enter new name product> \n";
		cin >> new_Products_Name;
		product[iterator].Set_Products_Name(new_Products_Name);

		cout << "Enter new Quantity in stock> ";
		cin >> new_Quantity_in_stock;
		product[iterator].Set_Quantity_in_stock(new_Quantity_in_stock);

		cout << "Enter new Cost in CU> ";
		cin >> new_Cost_in_CU;
		product[iterator].Set_Cost_in_CU(new_Cost_in_CU);

		cout << "Enter new Manufacturingplant> ";
		cin >> new_Manufacturing_plant;
		product[iterator].Set_Manufacturing_plant(new_Manufacturing_plant);

		cout << "Enter new Description product> ";
		cin >> new_Description;
		product[iterator].Set_Description(new_Description);
	}
	void search_product(Product *&product, unsigned short &Quantity_Products)
	{
		string products_found{};
		string search_{};
		cout << "Enter text to search database-> ";
		cin >> search_;
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			if (to_string(product[i].Get_Cost_in_CU()) == search_ || to_string(product[i].Get_Cost_in_UAN()) == search_ || product[i].Get_Department() == search_ || product[i].Get_Description() == search_ || product[i].Get_Manufacturing_plant() == search_ || product[i].Get_Products_Name() == search_ || to_string(product[i].Get_Quantity_in_stock()) == search_)
			{
				cout << "Departament => " << product[i].Get_Department() << "\nProduct > " << product[i].Get_Products_Name() << "\nCost in CU > " << product[i].Get_Cost_in_CU() << "\nCost in UAN > " << product[i].Get_Cost_in_UAN() << "\nQantity in stok> " << product[i].Get_Quantity_in_stock() << "\nManufacturing plant> " << product[i].Get_Manufacturing_plant() << "\nDescription>" << product[i].Get_Description() << endl;
			}
		}
		system("pause");
	}
	void Del_Product(Product *&product, unsigned short &Quantity_Products)
	{
		string departament;
		const string block_database = "[ Bread department ]\nPastry Department\nDairy department\nMeat section\nSausage department\nFish department\nGrocery department\nDepartment of drinks\nDepartment of semi - finished products\nFruit and vegetable department\n";
		system("cls");
		cout << block_database;
		switch (menu_DB.Get_menu_db(product, Quantity_Products))
		{
		case 1:
			departament = "Bread departmen";
			break;
		case 2:
			departament = "Pastry department";
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
		system("cls");
		string search_name_product{};
		cout << "Enter name product> \n";
		cin >> search_name_product;
		unsigned short iteratorr = 0;
		bool check_name = false;
		bool check_departament = false;
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			if (product[i].Get_Products_Name() == search_name_product && departament == product[i].Get_Department())
			{
				iteratorr = i;
				break;
			}
			else if (product[i].Get_Products_Name() != search_name_product && departament == product[i].Get_Department())
			{
				check_name = true;
			}
			else if (product[i].Get_Products_Name() == search_name_product && departament != product[i].Get_Department())
			{
				check_departament = true;
			}
			else
			{
				check_name = false;
				check_departament = false;
			}
		}
		system("cls");
		if (check_name == true)
		{
			cout << "Product-> " << search_name_product << " not foud in the " << departament << " !!!please check input data\n";
			Sleep(1000);
			cout << ". ";
			Sleep(1000);
			cout << ". ";
			Sleep(1000);
			cout << ". ";
			Sleep(1000);
			cout << ". ";
			Sleep(1000);
			cout << ". ";
			system("cls");
			return;
		}
		else if (check_name == false && check_departament == true)
		{
			cout << "This product-> " << search_name_product << " not part of the " << departament << " !!!please check input data\n";
			Sleep(1000);
			cout << ". ";
			Sleep(1000);
			cout << ". ";
			Sleep(1000);
			cout << ". ";
			Sleep(1000);
			cout << ". ";
			Sleep(1000);
			cout << ". ";
			system("cls");
			return;
		}
		cout << "Realy delete this product?\n\n";
		for (unsigned short i = iteratorr; i < 1; i++)
		{
			cout << "Departament => " << product[i].Get_Department() << "\nProduct name > " << product[i].Get_Products_Name() << "\nCost in CU > " << product[i].Get_Cost_in_CU() << "\nCost in UAN > " << product[i].Get_Cost_in_UAN() << "\nQantity in stok> " << product[i].Get_Quantity_in_stock() << "\nManufacturing plant> " << product[i].Get_Manufacturing_plant() << "\nDescription>" << product[i].Get_Description() << "\n\n(y/n)>";
		}
		char var{};
		cin >> var;
		if (var == 'y')
		{
			system("cls");
			Quantity_Products--;
			Product * new_product = new Product[Quantity_Products];
			unsigned short tmp = 0;
			for (unsigned short i = 0; i < Quantity_Products + 1; i++)
			{
				if (i == iteratorr)
				{
					continue;
				}
				new_product[tmp].Set_Cost_in_CU(product[i].Get_Cost_in_CU());
				new_product[tmp].Set_Department(product[i].Get_Department());
				new_product[tmp].Set_Description(product[i].Get_Description());
				new_product[tmp].Set_Manufacturing_plant(product[i].Get_Manufacturing_plant());
				new_product[tmp].Set_Products_Name(product[i].Get_Products_Name());
				new_product[tmp].Set_Quantity_in_stock(product[i].Get_Quantity_in_stock());
				tmp++;
			}
			delete[] product;
			product = new_product;

		}
		else if (var == 'n')
		{
			cout << "Operation canceled";
			Sleep(1000);
		}
	}
	void Show_Product(Product *&product, unsigned short &Quantity_Products)
	{
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			cout << "ALL Products>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n" << "Departament => " << product[i].Get_Department() << "\nProduct > " << product[i].Get_Products_Name() << "\nCost in CU > " << product[i].Get_Cost_in_CU() << "\nCost in UAN > " << product[i].Get_Cost_in_UAN() << "\nQantity in stok> " << product[i].Get_Quantity_in_stock() << "\nManufacturing plant> " << product[i].Get_Manufacturing_plant() << "\nDescription>" << product[i].Get_Description() << endl;
			system("pause");
		}
	}
	void write_down_data(Product *&product, unsigned short &Quantity_Products)
	{
		unsigned short var = 0;
		system("cls");
		cout << "Clean file and write your locate database - 1\nAdd your locate database to file - 2\n::";
		cin >> var;
		string path = "database.txt";
		ofstream write_file;
		if (var == 1)
		{
			write_file.open(path);
			string tmp_DB{};
			string man_begin = "#syntax VVVVV (All department names can be found below.)\n#(#)-comment !!!The character of the beginning of the comment must be at the beginning of the line, otherwise it will not work:(!!!\n#(~)- end data product\n#(.#)-end all database\n####################################################################";
			for (unsigned short i = 0; i < Quantity_Products; i++)
			{
				tmp_DB += "\n";
				tmp_DB += product[i].Get_Department();
				tmp_DB += "\n";
				tmp_DB += product[i].Get_Products_Name();
				tmp_DB += "\n";
				tmp_DB += to_string(product[i].Get_Quantity_in_stock());
				tmp_DB += "\n";
				tmp_DB += to_string(product[i].Get_Cost_in_CU());
				tmp_DB += "\n";
				tmp_DB += product[i].Get_Manufacturing_plant();
				tmp_DB += "\n";
				tmp_DB += product[i].Get_Description();
				tmp_DB += "\n~";
			}
			tmp_DB += "\n.#";
			string man_end = "\n####################################################################\n1 - \"Departament\"\n2 - \"Products_name\"\n3 - \"Quantity in stock\"\n4 - \"Cost in CU\"\n5 - \"Manufacturing plant\"\n6 - \"Description\"\n\nPS.This is all department names |\n\t\t\t\t\t\t\t\t|\n\t\t\t\t\t\t\t\tv\n\n\t\t\t\t\t\t\t\tbegin\n\t\t\t\t\t\t\t\tv\n\t\t\t\t\t\t\t\tBread departmen\n\t\t\t\t\t\t\t\tPastry Department\n\t\t\t\t\t\t\t\tDairy department\n\t\t\t\t\t\t\t\tMeat section\n\t\t\t\t\t\t\t\tSausage department\n\t\t\t\t\t\t\t\tFish department\n\t\t\t\t\t\t\t\tGrocery department\n\t\t\t\t\t\t\t\tDepartment of drinks\n\t\t\t\t\t\t\t\tSemi - finished products\n\t\t\t\t\t\t\t\tFruit and vegetable\n\t\t\t\t\t\t\t\t^\n\t\t\t\t\t\t\t\tend.";
			write_file << man_begin;
			write_file << tmp_DB;
			write_file << man_end;
			write_file.close();
		}
		else if (var == 2)
		{
			string tmp_DB{};
			string tmp_DB_2{};
			string data;
			ifstream read_file;
			read_file.open(path);
			while (true)
			{
				getline(read_file, data);
				if (data == ".#")
				{
					break;
				}
				tmp_DB += data;
				tmp_DB += "\n";
			}
			for (unsigned short i = 0; i < Quantity_Products; i++)
			{
				tmp_DB += product[i].Get_Department();
				tmp_DB += "\n";
				tmp_DB += product[i].Get_Products_Name();
				tmp_DB += "\n";
				tmp_DB += to_string(product[i].Get_Quantity_in_stock());
				tmp_DB += "\n";
				tmp_DB += to_string(product[i].Get_Cost_in_CU());
				tmp_DB += "\n";
				tmp_DB += product[i].Get_Manufacturing_plant();
				tmp_DB += "\n";
				tmp_DB += product[i].Get_Description();
				tmp_DB += "\n~\n";
			}
			tmp_DB += ".#\n";
			while (getline(read_file, data))
			{
				tmp_DB += data;
				tmp_DB += "\n";
			}
			read_file.close();
			write_file.open(path);
			cout << tmp_DB << endl;
			cout << endl << endl;

			write_file << tmp_DB;
			write_file.close();
			system("pause");
		}
	}
	void upload_data(Product *&product, unsigned short &Quantity_Products)
	{
		unsigned short tmp = 0;
		system("cls");
		cout << "Del all data and write new database=>1\nAdd data to data base=>2\n";
		cin >> tmp;
		system("cls");
		string path = "database.txt";
		string data;
		ifstream read_file;
		unsigned short i = 0;
		read_file.open(path);
		unsigned short Quantity_in_database = 0;
		for (unsigned short i = 0; true; i++)
		{
			getline(read_file, data);
			if (data[0] == '~')
			{
				Quantity_in_database++;
			}
			else if (data == ".#")
			{
				break;
			}
			
		}
		read_file.close();
		if (tmp == 1)
		{
			read_file.open(path);
			Product * new_product = new Product[Quantity_in_database];
			unsigned short tmp = 0;
			bool flag = false;
			getline(read_file, data);
			for (unsigned short i = 0; true; i++)
			{
				flag = false;
				while (data == ".#" ||data[0] == '#'||data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						Quantity_Products = Quantity_in_database;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}
				new_product[i].Set_Department(data);
				getline(read_file, data);
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}
				new_product[i].Set_Products_Name(data);
				getline(read_file, data);
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}
				new_product[i].Set_Quantity_in_stock(stoi(data));
				getline(read_file, data);
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}
				new_product[i].Set_Cost_in_CU(stof(data));
				getline(read_file, data);
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}
				new_product[i].Set_Manufacturing_plant(data);
				getline(read_file, data);
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}
				new_product[i].Set_Description(data);
				getline(read_file, data);
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}

			}
			delete[] product;
			product = new_product;
			read_file.close();
		}
		else if (tmp == 2)
		{
			read_file.open(path);
			bool flag = false;
			Product * new_product = new Product[Quantity_in_database+Quantity_in_database];
			for (unsigned short i = 0; i < Quantity_Products; i++)
			{
				new_product[i].Set_Cost_in_CU(product[i].Get_Cost_in_CU());
				new_product[i].Set_Department(product[i].Get_Department());
				new_product[i].Set_Description(product[i].Get_Description());
				new_product[i].Set_Manufacturing_plant(product[i].Get_Manufacturing_plant());
				new_product[i].Set_Products_Name(product[i].Get_Products_Name());
				new_product[i].Set_Quantity_in_stock(product[i].Get_Quantity_in_stock());
			}
			getline(read_file, data);
			for (unsigned short i = Quantity_Products; true; i++)
			{
				flag = false;
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						Quantity_Products += Quantity_in_database;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}
				new_product[i].Set_Department(data);
				getline(read_file, data);
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}
				new_product[i].Set_Products_Name(data);
				getline(read_file, data);
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}
				new_product[i].Set_Quantity_in_stock(stoi(data));
				getline(read_file, data);
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}
				new_product[i].Set_Cost_in_CU(stof(data));
				getline(read_file, data);
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}
				new_product[i].Set_Manufacturing_plant(data);
				getline(read_file, data);
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}
				new_product[i].Set_Description(data);
				getline(read_file, data);
				while (data == ".#" || data[0] == '#' || data[0] == '~')
				{
					if (data[0] == '~')
					{
						flag = true;
						getline(read_file, data);
						break;
					}
					else if (data[0] == '#')
					{
						getline(read_file, data);
					}
					else if (data == ".#")
					{
						delete[] product;
						product = new_product;
						read_file.close();
						return;
					}
				}
				if (flag == true)
				{
					continue;
				}

			}
			delete[] product;
			product = new_product;
			read_file.close();
		}
		else
		{
			cout << "Eror!!!\n";
			Sleep(1000);
			system("cls");
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
		const unsigned short size = 9;
		string menu[size]
		{
			"Show ALL Products",
			"Add item Data base",
			"Set product size",
			"Delete product",
			"Redact product",
			"Search product",
			"Upload data with file",
			"Write down your local database to file",
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
			work_with_database.reduct_product(product, Quantity_Products);
			break;
		case 6:
			work_with_database.search_product(product, Quantity_Products);
			break;
		case 7:
			work_with_database.upload_data(product, Quantity_Products);
			break;
		case 8:
			work_with_database.write_down_data(product, Quantity_Products);
			break;
		case 9:
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
	//srand(unsigned(time(NULL)));
	menu Menu;
	Product *product = nullptr;
	unsigned short Quantity_Products = 0;
	W_W_D work_with_database;
	bool var = true;
	while (var)
	{
		system("cls");
		cout << "[ Show ALL Products ]\nAdd item Data base\nSet product size\nDelete product\nRedact product\nSearch product\nUpload data with file\nWrite down your local database to file\nExit\n";
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