/*��������� ������� - ���� �������� � �������.
����'������ ������: ������ ������� ��� ������ (����, ���� � ���. � �.�., ������� �� �����, ����� ����) .���������� ������� ������:
���������� ���� �����
�������� ��� �����
���������� ���� ����� ����� �������
��������� �� ���� �����
������������� �� �����: ��� ������, ����
�����: ������ �������-�������� ��
������: ����� �� ����� �� ���� Y; ������, ���� �� ����� ���������� ����� 5 ����
��������: ���� ���� � �������, � ��'���� � ����� ����� ������
��������� ���: ���������� ��� ������; ������������� �� �����(������ - �������, ����, ����� ����)
�������� ������: �������� �� �������� ���� ������ (������� ���� ����� 0 ���.), � ����� �� ��, ��� ���� � ���. ��������� ��� � �.�.
��� ������� ����� ������������ ��������� ������� ��������� �� ��������� ���������� ����.*/

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include"work_with_database.h"
using namespace std;

int main()
{
	menu Menu;
	Product *product = nullptr;
	unsigned short Quantity_Products = 0;
	W_W_D work_with_database;
	bool var = true;
	while (var)
	{
		system("cls");
		cout << "[ Show ALL Products ]\nAdd item Data base\nSet product size\nDelete product\nRedact product\nSearch product\nUpload data with file\nWrite down your local database to file\nExit\n";
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