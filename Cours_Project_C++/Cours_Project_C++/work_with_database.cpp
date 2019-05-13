#include"work_with_database.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
	void W_W_D::Get_Memory(Product *&product, unsigned short &Quantity_Products)
	{
		product = new Product[Quantity_Products];
	}
	void W_W_D::Add_item_Data_Product(Product *&product, unsigned short &Quantity_Products)
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
		unsigned short new_Quantity_in_stock=0;
		const string block_database = "[ Bread department ]\nPastry Department\nDairy department\nMeat section\nSausage department\nFish department\nGrocery department\nDepartment of drinks\nSemi - finished products\nFruit and vegetable\n";
		float new_Cost_in_CU=-1;
		string buf{};
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
		cout << "(\"!!q\" - Exit)\n\nEnter name product>\n";
		cin.ignore();
		getline(std::cin, buf);
		if (buf == "!q")
		{
			return;
		}
		product[Quantity_Products - 1].Set_Products_Name(buf);

		cout << "Enter Quantity in stock(input data > 0)> ";
		cin >> new_Quantity_in_stock;
		product[Quantity_Products - 1].Set_Quantity_in_stock(new_Quantity_in_stock);

		while (new_Cost_in_CU < 0)
		{
			cout << "Enter Cost in CU(input data > 0)> ";
			cin >> new_Cost_in_CU;
			product[Quantity_Products - 1].Set_Cost_in_CU(new_Cost_in_CU);
		}

		cout << "Enter Manufacturingplant> ";
		cin.ignore();
		getline(std::cin, buf);
		product[Quantity_Products - 1].Set_Manufacturing_plant(buf);
		
		cout << "Enter Description product> ";
		cin.ignore();
		getline(std::cin,buf);
		product[Quantity_Products - 1].Set_Description(buf);
	}
	void W_W_D::reduct_product(Product *&product, unsigned short &Quantity_Products)
	{
		string department;
		string buf{};
		const string block_database = "[ Bread department ]\nPastry Department\nDairy department\nMeat section\nSausage department\nFish department\nGrocery department\nDepartment of drinks\nSemi - finished products\nFruit and vegetable\n";
		system("cls");
		cout << block_database;
		switch (menu_DB.Get_menu_db(product, Quantity_Products))
		{
		case 1:
			department = "Bread department";
			break;
		case 2:
			department = "Pastry Department";
			break;
		case 3:
			department = "Dairy department";
			break;
		case 4:
			department = "Meat section";
			break;
		case 5:
			department = "Sausage department";
			break;
		case 6:
			department = "Fish department";
			break;
		case 7:
			department = "Grocery department";
			break;
		case 8:
			department = "Department of drinks";
			break;
		case 9:
			department = "Semi - finished products";
			break;
		case 10:
			department = "Fruit and vegetable";
			break;
		}
		system("cls");
		string name_product{};
		cout << "(\"!q\" - Exit)\n\nEnter name product> \n";
		cin >> name_product;
		if (name_product == "!q")
		{
			return;
		}
		unsigned short iterator = 0;
		bool flag=true;
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			if (product[i].Get_Products_Name() == name_product&& product[i].Get_Department() == department)
			{
					iterator = i;
					flag = false;
					break;
			}
			else if (product[i].Get_Products_Name() != name_product && department != product[i].Get_Department()|| product[i].Get_Products_Name() == name_product && department != product[i].Get_Department())
			{
				flag = true;
			}
		}
		if (flag == true)
		{
			cout << "Eror, check name or department\n";
			Sleep(2000);
			return;
		}
		system("cls");
		cout << "(\"!end\" - Finish editing)\n(\"!skip\" - Skip)\nAttention, an incorrectly entered keyword will lead to a program crash!!!\n\nOld data>"<<product->Get_Products_Name()<<"\nEnter new name product>";
		cin >> buf;
		if (buf == "!end")
		{
			return;
		}
		else if (buf != "!skip")
		{
			product[iterator].Set_Products_Name(buf);
		}
		cout << "Old data>" << product->Get_Quantity_in_stock() << "\nEnter new Quantity in stock> ";
		cin >> buf;
		if (buf == "!end")
		{
			return;
		}
		else if (buf != "!skip")
		{
			product[iterator].Set_Quantity_in_stock(stoi(buf));
		}
		cout << "Old data>" << product->Get_Cost_in_CU() << "\nEnter new Cost in CU> ";
		cin >> buf;
		if (buf == "!end")
		{
			return;
		}
		else if (buf != "!skip")
		{
			product[iterator].Set_Cost_in_CU(stof(buf));
		}
		cout << "Old data>" << product->Get_Manufacturing_plant() << "\nEnter new Manufacturingplant> ";
		cin >> buf;
		if (buf == "!end")
		{
			return;
		}
		else if (buf != "!skip")
		{
			product[iterator].Set_Manufacturing_plant(buf);
		}
		cout << "Old data > " << product->Get_Description() << "\nEnter new Description product> ";
		cin >> buf;
		if (buf == "!end")
		{
			return;
		}
		else if (buf != "!skip")
		{
			product[iterator].Set_Description(buf);
		}
	}
	void W_W_D::search_product(Product *&product, unsigned short &Quantity_Products)
	{
		system("cls");
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
	void W_W_D::Del_Product(Product *&product, unsigned short &Quantity_Products)
	{
		string departament;
		const string block_database = "[ Bread department ]\nPastry Department\nDairy department\nMeat section\nSausage department\nFish department\nGrocery department\nDepartment of drinks\nSemi - finished products\nFruit and vegetable\n";
		system("cls");
		cout << block_database;
		switch (menu_DB.Get_menu_db(product, Quantity_Products))
		{
		case 1:
			departament = "Bread department";
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
		cout << "(\"!q\" - Exit)\n\nEnter name product> \n";
		cin >> search_name_product;
		if (search_name_product == "!q")
		{
			return;
		}
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
				break;
			}
			else if (product[i].Get_Products_Name() == search_name_product && departament != product[i].Get_Department())
			{
				check_departament = true;
				break;
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
	void W_W_D::Show_Product(Product *&product, unsigned short &Quantity_Products)
	{
		system("cls");
		cout << "ALL Products>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			cout << "\n==================================================================================================\n" << "Departament => " << product[i].Get_Department() << "\nProduct > " << product[i].Get_Products_Name() << "\nCost in CU > " << product[i].Get_Cost_in_CU() << "\nCost in UAN > " << product[i].Get_Cost_in_UAN() << "\nQantity in stok> " << product[i].Get_Quantity_in_stock() << "\nManufacturing plant> " << product[i].Get_Manufacturing_plant() << "\nDescription>" << product[i].Get_Description() <<"\n==================================================================================================\n "<< endl;
		}
		system("pause");
	}
	void W_W_D::write_down_data(Product *&product, unsigned short &Quantity_Products)
	{
		unsigned short var = 0;
		string path = "database.txt";
		cout << "Use standard file - 1\nUse another file - 2\nExit - 0\n>";
		cin >> var;
		if (var == 2)
		{
			cout << "Enter path> ";
			cin>> path;
		}
		else if(var == 0)
		{
			return;
		}
		system("cls");
		cout << "Clean file and write your locate database - 1\nAdd your locate database to file - 2\n::";
		cin >> var;
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
				tmp_DB += "#";
				tmp_DB += to_string(product[i].Get_Cost_in_UAN());
				tmp_DB += "\n";
				tmp_DB += product[i].Get_Manufacturing_plant();
				tmp_DB += "\n";
				tmp_DB += product[i].Get_Description();
				tmp_DB += "\n~";
			}
			tmp_DB += "\n.#";
			string man_end = "\n####################################################################\n1 - \"Departament\"\n2 - \"Products_name\"\n3 - \"Quantity in stock\"\n4 - \"Cost in CU\"\n#4.a - \"Cost in UAN\"\n5 - \"Manufacturing plant\"\n6 - \"Description\"\n\nPS.This is all department names |\n\t\t\t\t\t\t\t\t|\n\t\t\t\t\t\t\t\tv\n\n\t\t\t\t\t\t\t\tbegin\n\t\t\t\t\t\t\t\tv\n\t\t\t\t\t\t\t\tBread departmen\n\t\t\t\t\t\t\t\tPastry Department\n\t\t\t\t\t\t\t\tDairy department\n\t\t\t\t\t\t\t\tMeat section\n\t\t\t\t\t\t\t\tSausage department\n\t\t\t\t\t\t\t\tFish department\n\t\t\t\t\t\t\t\tGrocery department\n\t\t\t\t\t\t\t\tDepartment of drinks\n\t\t\t\t\t\t\t\tSemi - finished products\n\t\t\t\t\t\t\t\tFruit and vegetable\n\t\t\t\t\t\t\t\t^\n\t\t\t\t\t\t\t\tend.";
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
	void W_W_D::upload_data(Product *&product, unsigned short &Quantity_Products)
	{
		unsigned short var = 0;
		string path = "database.txt";
		cout << "Use standard file - 1\nUse another file - 2\nExit - 0\n>";
		cin >> var;
		if (var == 2)
		{
			cout << "Enter path> ";
			cin >> path;
		}
		else if (var == 0)
		{
			return;
		}
		system("cls");
		cout << "Del all data and write new database=>1\nAdd data to data base=>2\n";
		cin >> var;
		system("cls");
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
		if (var == 1)
		{
			read_file.open(path);
			Product * new_product = new Product[Quantity_in_database];
			unsigned short tmp = 0;
			bool flag = false;
			getline(read_file, data);
			for (unsigned short i = 0; true; i++)
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
		else if (var == 2)
		{
			read_file.open(path);
			bool flag = false;
			Product * new_product = new Product[Quantity_in_database + Quantity_in_database];
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