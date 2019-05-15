#include"work_with_database.h"
#include <string>
using namespace std;
	void Product::Set_UAN()
	{
		Cost_in_UAN = Cost_in_CU * Rate_of_conventional_units;
	}
	void Product::Set_Quantity_in_stock(int new_Quantity_in_stock)
	{
		this->Quantity_in_stock = new_Quantity_in_stock;
	}
	void Product::Set_Department(string new_Department)
	{
		this->Department = new_Department;
	}
	void Product::Set_Cost_in_CU(float new_Cost_in_CU)
	{
		if (new_Cost_in_CU <= 0)
		{
			return;
		}
		this->Cost_in_CU = new_Cost_in_CU;
		Set_UAN();
	}
	void Product::Set_Manufacturing_plant(string new_Manufacturing_plant)
	{
		this->Manufacturing_plant = new_Manufacturing_plant;
	}
	void Product::Set_Description(string new_Description)
	{
		this->Description = new_Description;
	}
	void Product::Set_Products_Name(string new_Products_Name)
	{
		this->Products_Name = new_Products_Name;
	}
	unsigned short Product::Get_Quantity_in_stock()
	{
		return this->Quantity_in_stock;
	}
	float Product::Get_Cost_in_CU()
	{
		return this->Cost_in_CU;
	}
	float Product::Get_Cost_in_UAN()
	{
		return this->Cost_in_UAN;
	}
	string Product::Get_Department()
	{
		return this->Department;
	}
	string Product::Get_Manufacturing_plant()
	{
		return this->Manufacturing_plant;
	}
	string Product::Get_Description()
	{
		return this->Description;
	}
	string Product::Get_Products_Name()
	{
		return this->Products_Name;
	}

