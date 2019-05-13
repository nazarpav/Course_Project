#include"work_with_database.h"
#include<conio.h>
#include<iostream>

	unsigned short Menu_database::menu_db(Product *&product, unsigned short &Quantity_Products)
	{
		unsigned short choise = 1;
		char Control_Symbol{};
		const unsigned short size = 10;
		std::string menu[size]
		{
			"Bread department",
			"Pastry Department",
			"Dairy department",
			"Meat section",
			"Sausage department",
			"Fish department",
			"Grocery department",
			"Department of drinks",
			"Semi - finished products",
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
					std::cout << "[ " << menu[i] << " ]" << std::endl;
					continue;
				}
				std::cout << menu[i] << std::endl;
			}

		}
		return choise;

	}
	unsigned short Menu_database::Get_menu_db(Product *&product, unsigned short &Quantity_Products)
	{
		return menu_db(product, Quantity_Products);
	}