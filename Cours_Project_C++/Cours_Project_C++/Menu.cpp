#include"work_with_database.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

	void menu::Menu_Private(W_W_D &work_with_database, Product *&product, unsigned short &Quantity_Products, bool &var)
	{
		unsigned short choise = 1;
		char Control_Symbol{};
		const unsigned short size = 9;
		string menu[size]
		{
			"Show ALL Products",
			"Add item Data base",
			"Sampling products",
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
			system("cls");
			cout << "In developing";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
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
	void menu::Menu(W_W_D &work_with_database, Product *&product, unsigned short &Quantity_Products, bool &var)
	{
		Menu_Private(work_with_database, product, Quantity_Products, var);
	}
