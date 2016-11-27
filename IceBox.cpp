#include "IceBox.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Menu.h"

using namespace std; 

void waitenter()
{
	cout << "Нажмите enter"; 
	while (1)
	{
		int inpush;
		inpush = _getch();
		if (inpush == 13)
		{
			break;
		}
	}
}

IceBox::IceBox()
{
	size = 0;
}

void IceBox::showlist()
{
	system("cls");
	cout << "        Список продуктов\n";
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << ". "; 
		arr[i].show();
	}
	system("pause");
}

void IceBox::add()
{
	system("cls");
	cout << "Введите название продукта - ";
	char ch, charr[30];
	int t=-1, m, c;
	cin.ignore(0,'\n');
	cin.get(ch);
	do
	{
		if (ch != '\n')
		{
			t++;
			charr[t] = ch;
		}
		cin.get(ch);
	} while (ch != '\n');

	t++; charr[t] = '\n';
	cout << "Тип продукта (0 - еда, 1 - напиток) - "; 
	cin >> t; 
	if (t == 1) { cout << "Введите обьём - "; cin >> m; }
	else { cout << "Введите массу - "; cin >> m;  }
	cout << "Введите количество - "; 
	cin >> c; 
	
	char life[10];
	cout << "Введите дату, когда истекает срок годности (ГГ.ММ.ДД):";
	cin.ignore(1,'\n');
	for (int i = 0; i <= 7; i++)
	{
		cin.get(life[i]);
	}

	arr[size] = Product(charr, t, m, c, life);
	size++;
}

void IceBox::del()
{
	system("cls");
	cout << "Введите название продукта: ";
	cin.ignore(1, '\n');
	char ch, charr[30]; int t=-1;
	cin.get(ch);
	while (ch != '\n')
	{
		t++;
		charr[t] = ch;
		cin.get(ch);
	}
	t++; charr[t] = '\n';
	int a; bool fin=false; 
	for (int i = 0; i < size; i++)
	{
		if (arr[i].isequal(charr))
		{
			fin = true;
			cout << "В каком количестве? \n"; 
			cin >> a; 
			if (a >= arr[i].getcount())
			{
				arr[i] = arr[size-1];
				size--;
			}
			else 
			{
				arr[i].dimincount(a);
			}
			break; 
		}
	}
	if (fin == false) { cout << "Этот продукт не найден\n"; waitenter(); }
}

void IceBox::find()
{
	Menu menu; 
	int pick = menu.findscreen();

}

IceBox::~IceBox()
{
}
