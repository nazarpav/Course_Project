#pragma once
#include <string>
using namespace std;
class  Product
{
private:
	const unsigned short Rate_of_conventional_units = 20;
	float Cost_in_UAN;
	std::string Department;
	std::string Manufacturing_plant;
	std::string Description;
	std::string Products_Name;
	unsigned short Quantity_in_stock;
	float Cost_in_CU;
public:
	void Set_UAN();
	void Set_Department(string new_Department);
	void Set_Quantity_in_stock(int new_Quantity_in_stock);;
	void Set_Cost_in_CU(float new_Cost_in_CU);
	void Set_Manufacturing_plant(std::string new_Manufacturing_plant);
	void Set_Description(std::string new_Description);
	void Set_Products_Name(std::string new_Products_Name);
	unsigned short Get_Quantity_in_stock();
	float Get_Cost_in_CU();
	float Get_Cost_in_UAN();
	std::string Get_Department();
	std::string Get_Manufacturing_plant();
	std::string Get_Description();
	std::string Get_Products_Name();
};
class Menu_database
{
	unsigned short menu_db(Product *&product, unsigned short &Quantity_Products);
public:
	unsigned short Get_menu_db(Product *&product, unsigned short &Quantity_Products);
};
class W_W_D
{
	Menu_database menu_DB;
public:
	void Get_Memory(Product *&product, unsigned short &Quantity_Products);
	void Add_item_Data_Product(Product *&product, unsigned short &Quantity_Products);
	void reduct_product(Product *&product, unsigned short &Quantity_Products);
	void search_product(Product *& product, unsigned short & Quantity_Products);
	void Del_Product(Product *&product, unsigned short &Quantity_Products);
	void Show_Product(Product *&product, unsigned short &Quantity_Products);
	void write_down_data(Product *&product, unsigned short &Quantity_Products);
	void upload_data(Product *&product, unsigned short &Quantity_Products);
};

class menu
{
protected:
	Menu_database menu_DB_;
	unsigned short departament = 0;
	void Menu_Private(W_W_D &work_with_database, Product *&product, unsigned short &Quantity_Products, bool &var);
public:
	void Menu(W_W_D &work_with_database, Product *&product, unsigned short &Quantity_Products, bool &var);
};
