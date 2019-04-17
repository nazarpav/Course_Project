/*C++
��������� ������� - ���� �������� � �������.
����'������ ������: ������ ������� ��� ������ (����, ���� � ���. � �.�., ������� �� �����, ����� ����) .���������� ������� ������:
���������� ���� �����
�������� ��� �����
���������� ���� ����� ����� �������
��������� �� ���� �����
������������� �� �����: ��� ������, ����
�����: ������ �������-�������� ��
������: �������� �� ����� �� ���� Y; ������, ���� �� ����� ���������� ����� 5 ����
��������: ���� ���� � �������, � ��'���� � ����� ����� ������
��������� ���: ���������� ��� ������; ������������� �� �����(������ - �������, ����, ����� ����)
�������� ������: �������� �� �������� ���� ������ (������� ���� ����� 0 ���.), � ����� �� ��, ��� ���� � ���. ��������� ��� � �.�.
��� ������� ����� ������������ ��������� ������� ��������� �� ��������� ���������� ����. */
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
	int Get_Quantity_in_stock()
	{
		return this->Quantity_in_stock;
	}
	int Get_Cost_in_CU()
	{
		return this->Cost_in_CU;
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
class W_W_D
{
public:
	void Get_Memory(Product *&product, unsigned short &Quantity_Products)
	{
		product = new Product[Quantity_Products];
	}
	void Enter_Data_Product(Product product[], unsigned short &Quantity_Products)
	{
		unsigned short new_Quantity_in_stock;
		unsigned short new_Cost_in_CU;
		string new_Manufacturing_plant;
		string new_Description;
		string new_Products_Name;
		string new_Department;
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			cout << "Enter name product> \n" << product << "\n";
			cin >> new_Products_Name;
			product[i].Set_Products_Name(new_Products_Name);

			cout << "Enter Quantity in stock> ";
			cin >> new_Quantity_in_stock;
			product[i].Set_Quantity_in_stock(new_Quantity_in_stock);

			cout << "Enter Cost in CU> ";
			cin >> new_Cost_in_CU;
			product[i].Set_Cost_in_CU(new_Cost_in_CU);

			cout << "Enter Manufacturingplant> ";
			cin >> new_Manufacturing_plant;
			product[i].Set_Manufacturing_plant(new_Manufacturing_plant);

			cout << "Enter Description product> ";
			cin >> new_Description;
			product[i].Set_Description(new_Description);

			cout << "Enter Department> ";
			cin >> new_Department;
			product[i].Set_Department(new_Department);
		}
	}
	void Del_Product(Product product[], unsigned short &Quantity_Products)
	{
		unsigned short choise = 1;
		char Control_Symbol{}, Control_Button{};
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
			"Department of semi - finished products",
			"fruit and vegetable department"
		};
		while (Control_Symbol != 13)
		{
			Control_Button = _getch();
			Control_Symbol = _getch();
			if (Control_Button == 224)
			{
				Control_Button = NULL;
				Control_Symbol = NULL;
				continue;
			}
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
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		case 10:

			break;
		default:
			cout << "Eror!!!\n";
			break;
		}
	}
	void Show_Product(Product product[], unsigned short &Quantity_Products)
	{
		for (unsigned short i = 0; i < Quantity_Products; i++)
		{
			cout << product << endl;
			cout << "ALL Products>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\nProduct >" << product[i].Get_Products_Name() << "\nCost in CU > " << product[i].Get_Cost_in_CU() << "\nQantity in stok> " << product[i].Get_Quantity_in_stock() << "\nManufacturing plant> " << product[i].Get_Manufacturing_plant() << "\nDescription>" << product[i].Get_Description() << endl;
			system("pause");
		}
	}
};
class menu
{
protected:
	void Menu_Private(W_W_D &work_with_database, Product *&product, unsigned short &Quantity_Products, bool &var)
	{
		unsigned short choise = 1;
		char Control_Symbol{}, Control_Button{};
		const unsigned short size = 6;
		string menu[size]
		{
			"Show ALL Products",
			"Enter ALL Data base",
			"Set product size",
			"______________",
			"______________",
			"Exit"
		};
		while (Control_Symbol != 13)
		{
			Control_Button = _getch();
			Control_Symbol = _getch();
			if (Control_Button==224)
			{
				Control_Button = NULL;
				Control_Symbol = NULL;
				continue;
			}
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
			work_with_database.Enter_Data_Product(product, Quantity_Products);
			break;
		case 3:
			cout << "Enter Quantity Products> ";
			cin >> Quantity_Products;
			work_with_database.Get_Memory(product, Quantity_Products);
			break;
		case 4:
			work_with_database.Del_Product(product, Quantity_Products);
			break;
		case 5:
			cout << "5\n";
			break;
		case 6:
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
		cout << "[ Show ALL Products ]\nEnter ALL Data base\nSet product size\n______________\n______________\nExit\n";
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