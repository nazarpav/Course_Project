<<<<<<< HEAD
/*��������� ������� - ���� �������� � ��������.
����'������� ������: ������ ������� ��� ������ (����, ���� � ���. � �.�., ������� �� �����, ����� ����) .���������� �������� ������:
���������� ���� �����
�������� ��� �����
���������� ���� ����� ����� �������
��������� �� ���� �����
������������� �� �����: ��� ������, ����
�����: ������ �������-�������� ��
������: �������� �� ����� �� ���� Y; ������, ���� �� ����� ���������� ����� 5 ����
��������: ���� ���� � �������, � ��'���� � ����� ����� ������
��������� ���: ���������� ��� ������; ������������� �� �����(������ - �������, ����, ����� ����)
�������� ������: �������� �� �������� ���� ������ (������� ���� ����� 0 ���.), � ����� �� ��, ��� ���� � ���. ��������� ���� � �.�.
��� ������� ����� ������������ ��������� ������� ��������� �� ��������� ���������� ����.*/
=======
﻿/*Предметна область - відділ продуктів в магазині.
Розв'язувані задачі: видача зведень про товари (опис, ціна в грн. і у.о., кількість на складі, марка тощо) .Реалізувати наступні сервіси:
Заповнення бази даних
Перегляд усіх даних
Доповнення бази даних новим записом
Видалення із бази даних
Упорядкування по полях: тип товару, ціна
Пошук: товару фабрика-виробник ХХ
Вибірка: овочі за ціною не більш Y; товари, яких на складі залишилося менше 5 штук
Корекція: зміна ціни в гривнях, у зв'язку зі зміною курсу долара
Табличний звіт: інформація про товари; упорядкування по типах(окремо - ковбаси, риба, овочі тощо)
Додаткові вимоги: перевірка на введення ціни товару (повинна бути більше 0 грн.), а також на те, щоб ціна в грн. відповідала ціні в у.о.
Для обробки даних скористатися динамічним масивом покажчиків на структури відповідного типу.*/
>>>>>>> work_with_file

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