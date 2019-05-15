 #include"work_with_database.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
unsigned short W_W_D::template_menu(string menu[],unsigned short size)
{
	for (unsigned short i = 0; i < size; i++)
	{
		if (i == 0)
		{
		cout<<"[ "<<menu[i]<<" ]"<<endl;
		continue;
		}
		cout<<menu[i]<<endl;
	}
	unsigned short choise = 1;
	char Control_Symbol{};
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
void W_W_D::write_block_database(Product *&product,unsigned short i)
{
	cout << "\n==================================================================================================\n" << "Departament => " << product[i].Get_Department() << "\nProduct > " << product[i].Get_Products_Name() << "\nCost in CU > " << product[i].Get_Cost_in_CU() << "\nCost in UAN > " << product[i].Get_Cost_in_UAN() << "\nQantity in stok> " << product[i].Get_Quantity_in_stock() << "\nManufacturing plant> " << product[i].Get_Manufacturing_plant() << "\nDescription>" << product[i].Get_Description() << "\n==================================================================================================\n " << endl;
}
void W_W_D::Sampling_products(Product *&product, unsigned short &Quantity_Products)
{
	system("cls");
	const unsigned short size = 4;
	string menu[size]
	{
		"Quantity in stock",
		"Costs",
		"Manufacture plant",
		"Department"
	};
	string  manufacture_plant_{};
	unsigned short from = 0, to = 0;
	string Department{};
	switch (template_menu(menu, size))
	{
	case 1:
		system("cls");
		cout << "Please indicate the span\n\nFrom(currency=\"CU\")>";
		cin >> from;
		cout << "To(currency=\"CU\")>";
		cin >> to;
		system("cls");
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			if (product[i].Get_Quantity_in_stock() >= from && product[i].Get_Quantity_in_stock() <= to)
			{
				write_block_database(product,i);
			}
		}
		system("pause");
		break;
	case 2:
		system("cls");
		cout << "Please indicate the span\n\nFrom>";
		cin >> from;
		cout << "To>";
		cin >> to;
		system("cls");
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			if (product[i].Get_Cost_in_CU() >= from && product[i].Get_Cost_in_CU() <= to)
			{
				write_block_database(product, i);
			}
		}
		system("pause");
		break;
	case 3:
		system("cls");
		cout << "Please enter manufacture plant>";
		cin.ignore();
		cin.sync();
		getline(std::cin, manufacture_plant_);
		system("cls");
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			if (product[i].Get_Manufacturing_plant() == manufacture_plant_)
			{
				write_block_database(product, i);
			}
		}
		system("pause");
		break;
	case 4:
		system("cls");
		switch (menu_DB.Get_menu_db(product, Quantity_Products))
		{
		case 1:
			Department = "Bread department";
			break;
		case 2:
			Department = "Pastry Department";
			break;
		case 3:
			Department = "Dairy department";
			break;
		case 4:
			Department = "Meat section";
			break;
		case 5:
			Department = "Sausage department";
			break;
		case 6:
			Department = "Fish department";
			break;
		case 7:
			Department = "Grocery department";
			break;
		case 8:
			Department = "Department of drinks";
			break;
		case 9:
			Department = "Semi - finished products";
			break;
		case 10:
			Department = "Fruit and vegetable";
			break;
		}
		system("cls");
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			if (product[i].Get_Department() == Department)
			{
				write_block_database(product, i);
			}
		}
		system("pause");
		break;
	}

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
		float new_Cost_in_CU=-1;
		string buf{};
		system("cls");
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
		cout << "(\"!q\" - Exit)\n\nEnter name product>\n";
		cin.sync();
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
		cin.sync();
		getline(std::cin, buf);
		product[Quantity_Products - 1].Set_Manufacturing_plant(buf);
		
		cout << "Enter Description product> ";
		cin.sync();
		getline(std::cin,buf);
		product[Quantity_Products - 1].Set_Description(buf);
	}
	void W_W_D::reduct_product(Product *&product, unsigned short &Quantity_Products)
	{
		string department;
		string buf{};
		system("cls");
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
		cin.sync();
		getline(std::cin,name_product);
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
			cout << char(7);
			cout << "Eror, check name or department\n";
			Sleep(3000);
			return;
		}
		system("cls");
		cout << "(\"!end\" - Finish editing)\n(\"!skip\" - Skip)\nAttention, an incorrectly entered keyword will lead to a program crash!!!\n\nOld data>"<<product->Get_Products_Name()<<"\nEnter new name product>";
		cin.sync();
		getline(std::cin,buf);
		if (buf == "!end")
		{
			return;
		}
		else if (buf != "!skip")
		{
			product[iterator].Set_Products_Name(buf);
		}
		cout << "Old data>" << product->Get_Quantity_in_stock() << "\nEnter new Quantity in stock> ";
		cin.sync();
		getline(std::cin, buf);
		if (buf == "!end")
		{
			return;
		}
		else if (buf != "!skip")
		{
			product[iterator].Set_Quantity_in_stock(stoi(buf));
		}
		cout << "Old data>" << product->Get_Cost_in_CU() << "\nEnter new Cost in CU> ";
		cin.sync();
		getline(std::cin, buf);
		if (buf == "!end")
		{
			return;
		}
		else if (buf != "!skip")
		{
			product[iterator].Set_Cost_in_CU(stof(buf));
		}
		cout << "Old data>" << product->Get_Manufacturing_plant() << "\nEnter new Manufacturingplant> ";
		cin.sync();
		getline(std::cin, buf);
		if (buf == "!end")
		{
			return;
		}
		else if (buf != "!skip")
		{
			product[iterator].Set_Manufacturing_plant(buf);
		}
		cout << "Old data > " << product->Get_Description() << "\nEnter new Description product> ";
		cin.sync();
		getline(std::cin, buf);
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
		cin.sync();
		getline(std::cin,search_);
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			if (to_string(product[i].Get_Cost_in_CU()) == search_ || to_string(product[i].Get_Cost_in_UAN()) == search_ || product[i].Get_Department() == search_ || product[i].Get_Description() == search_ || product[i].Get_Manufacturing_plant() == search_ || product[i].Get_Products_Name() == search_ || to_string(product[i].Get_Quantity_in_stock()) == search_)
			{
				write_block_database(product, i);
			}
		}
		system("pause");
	}
	void W_W_D::Del_Product(Product *&product, unsigned short &Quantity_Products)
	{
		string departament;
		system("cls");
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
		cin.sync();
		getline(std::cin, search_name_product);
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
			cout << char(7);
			cout << "Product-> " << search_name_product << " not foud in the " << departament << " !!!please check input data\n";
			for (unsigned short i = 0; i < 4; i++)
			{
				cout << ".";
				Sleep(1000);
			}
			system("cls");
			return;
		}
		else if (check_name == false && check_departament == true)
		{
			cout << char(7);
			cout << "This product-> " << search_name_product << " not part of the " << departament << " !!!please check input data\n";
			for (unsigned short i = 0; i < 4; i++)
			{
				cout << ".";
				Sleep(1000);
			}
			system("cls");
			return;
		}
		cout << "Realy delete this product?\n\t\t(y/n)\n";
		for (unsigned short i = iteratorr; i < 1; i++)
		{
			write_block_database(product, i);
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
			write_block_database(product, i);
		}
		system("pause");
	}
	void W_W_D::write_down_data(Product *&product, unsigned short &Quantity_Products)
	{
		system("cls");
		unsigned short var = 0;
		string path = "database.txt";
		if (Quantity_Products == 0)
		{
			system("cls");
			cout << char(7);
			cout << "\t\tWARNING!!!\nYour local database is empty.!";
			Sleep(3000);
			return;
		}
		const unsigned short size = 3;
		string menu[size]{ "Use standard file","Use another file","Exit" };
		var = template_menu(menu, size);
		if (var == 3)
		{
			return;
		}
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
		const unsigned short size2 = 3;
		string menu2[size2]{ "Clean file and write your locate database","Add your locate database to file","Exit"};
		var = template_menu(menu2, size2);
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
		write_file.close();
		}
	}
	void W_W_D::upload_data(Product *&product, unsigned short &Quantity_Products)
	{
		system("cls");
		unsigned short var = 0;
		string path = "database.txt";
		const unsigned short size = 3;
		string menu[size]{ "Use standard file","Use another file","Exit" };
		var = template_menu(menu, size);
		if (var == 2)
		{
			cout << "Enter path> ";
			cin >> path;
		}
		else if (var == 3)
		{
			return;
		}
		system("cls");
		const unsigned short size2 = 3;
		string menu2[size2]{ "Del all data and write new database","Add data to data base","Exit" };
		var = template_menu(menu2, size2);
		if (var == 3)
		{
			return;
		}
		if (Quantity_Products == 0 && var != 1)
		{
			system("cls");
			cout << char(7);
			cout << "Error your local database is empty!\n";
			for (unsigned short i = 0; i < 4; i++)
			{
				cout << ".";
				Sleep(1000);
			}
			return;
		}
		system("cls");
		string data;
		ifstream read_file;
		unsigned short i = 0;
		read_file.open(path);
		bool flag_1 = false;
		bool flag_2 = false;
		bool flag_3 = true;
		while (read_file.eof() == 0)
		{
			getline(read_file, data);
			if (data != ".#")
			{
				flag_2 = true;
			}
			else if (data == ".#")
			{
				flag_2 = false;
				if (data != "~"&&flag_3==true)
				{
					flag_1 = true;
				}
				break;
			}
			if (data != "~")
			{
				flag_1 = true;
			}
			else if (data == "~")
			{
				flag_1 = false;
				flag_3 = false;
			}
		}
		if (flag_2==true)
		{
			cout << char(7);
			cout << "Error, end of database not found\n";
			for (unsigned short i = 0; i < 4; i++)
			{
				cout << ".";
				Sleep(1000);
			}
			return;
		}
		else if (flag_1 == true)
		{
			system("cls");
			cout << char(7);
			cout << "Error, Database block not found\n";
			for (unsigned short i = 0; i < 4; i++)
			{
				cout << ".";
				Sleep(1000);
			}
			return;
		}
		read_file.close();
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
	}