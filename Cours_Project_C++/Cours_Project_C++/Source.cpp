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

const unsigned short Rate_of_conventional_units = 20;
struct Departaments
{
private:
	unsigned short Quantity_Products = 5;
	void Get_Memory() {
		product = new Product[Quantity_Products];
	}
	Product *product = nullptr;
public:
	void Set_Quantity_Products(unsigned short new_Quantity_Products = 0)
	{
		Quantity_Products = new_Quantity_Products;
		void Get_Memory();
	}
	
};
struct Product
{
protected:
	unsigned short Cost_in_UAN = Cost_in_CU * Rate_of_conventional_units;
private:
	string Manufacturing_plant;
	string Description;
	string Products_Name;
	unsigned short Quantity_in_stock;
	unsigned short Cost_in_CU;
public:
	void Set_Quantity_in_stock(int new_Quantity_in_stock)
	{
		Quantity_in_stock = new_Quantity_in_stock;
	}
	void Set_Cost_in_CU(int new_Cost_in_CU)
	{
		Cost_in_CU = new_Cost_in_CU;
	}
	void Set_Manufacturing_plant(string new_Manufacturing_plant)
	{
		Manufacturing_plant = new_Manufacturing_plant;
	}
	void Set_Description(string new_Description)
	{
		Description = new_Description;
	}
	void Set_Products_Name(string new_Products_Name)
	{
		Products_Name = new_Products_Name;
	}
	int Get_Quantity_in_stock()
	{
		return Quantity_in_stock;
	}
	int Get_Cost_in_CU()
	{
		return Cost_in_CU;
	}
	string Get_Manufacturing_plant()
	{
		return Manufacturing_plant;
	}
	string Get_Description()
	{
		return Description;
	}
	string Get_Products_Name()
	{
		return Products_Name;
	}
};
class menu
{
protected:
	void Menu_Private()
	{
		unsigned short choise = 3;
		char Control_Symbol{};
		const unsigned short size = 6;
		string menu[size]
		{
			"11111111111111",
			"22222222222222",
			"33333333333333",
			"44444444444444",
			"55555555555555",
			"66666666666666"
		};
			while (Control_Symbol != 13)
			{
				Control_Symbol = _getch();
				if (Control_Symbol != 119 && Control_Symbol != 115)
				{
					continue;
				}
				else
				{
					Control_Symbol == 119 ? choise-- : choise++;
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
				cout << "1\n";
				break;
			case 2:
				cout << "2\n";
				break;
			case 3:
				cout << "3\n";
				break;
			case 4:
				cout << "4\n";
				break;
			case 5:
				cout << "5\n";
				break;
			case 6:
				cout << "6\n";
				break;
			default:
				cout << "Eror!!!\n";
				break;
			}
	}
public:
	void Menu()
	{
		Menu_Private();
	}
};
 
int main()
{
	srand(unsigned(time(NULL)));
	menu Menu;
	Menu.Menu();

	
	
	system("pause");
	return 0;
}