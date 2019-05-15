#include"work_with_database.h"
#include<conio.h>
#include<iostream>

	unsigned short Menu_database::menu_db(Product *&product, unsigned short &Quantity_Products)
	{
		W_W_D work_with_database_;
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
		return work_with_database_.template_menu(menu, size);

	}
	unsigned short Menu_database::Get_menu_db(Product *&product, unsigned short &Quantity_Products)
	{
		return menu_db(product, Quantity_Products);
	}