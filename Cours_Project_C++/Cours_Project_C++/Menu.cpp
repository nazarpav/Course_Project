#include"work_with_database.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

	void menu::Menu_Private(W_W_D &work_with_database_, Product *&product, unsigned short &Quantity_Products, bool &var)
	{
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
		switch (work_with_database_.template_menu(menu, size))
		{
		case 1:
			work_with_database_.Show_Product(product, Quantity_Products);
			break;
		case 2:
			work_with_database_.Add_item_Data_Product(product, Quantity_Products);
			break;
		case 3:
			work_with_database_.Sampling_products(product, Quantity_Products);
			break;
		case 4:
			work_with_database_.Del_Product(product, Quantity_Products);
			break;
		case 5:
			work_with_database_.reduct_product(product, Quantity_Products);
			break;
		case 6:
			work_with_database_.search_product(product, Quantity_Products);
			break;
		case 7:
			work_with_database_.upload_data(product, Quantity_Products);
			break;
		case 8:
			work_with_database_.write_down_data(product, Quantity_Products);
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
