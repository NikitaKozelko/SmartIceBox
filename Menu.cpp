#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std; 

Menu::Menu()
{
}

void Menu::salute()
{
	cout << "Hello\n Press ENTER\n";
	system("pause");
}

void Menu::showmenu(int x)
{
	system("cls");
	HANDLE h;
	cout << "        Меню\n"; 
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 1; i <= 9; i++)
	{
		if (i == x) 
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << " -> "; 
		}
		else { cout << "    "; }
		switch (i)
		{
		case 1:
		{
			cout << "1. Показать список продуктов в холодильнике";
			break;
		}
		case 2: 
		{
			cout << "2. Положить продукт в холодильник"; 
			break; 
		}
		case 3:
		{
			cout << "3. Достать продукт из холодильника"; 
			break; 
		}
		case 4:
		{
			cout << "4. Сортировка продуктов по параметрам";
			break;
		}
		case 5:
		{
			cout << "5. Поиск продукта"; 
			break; 
		}
		case 6:
		{
			cout << "6. Показать историю";
			break; 
		}
		case 7:
		{
			cout << "7. Автоматический список продуктов";
			break; 
		}
		case 8: 
		{
			cout << "8. Помощь";
			break;
		}
		case 9:
		{
			cout << "9. Выход";
			break;
		}
		}
		SetConsoleTextAttribute(h, 15);
		cout << endl; 
	}
}

int Menu::mainscreen()
{
	int inpush;

	int option=1; 
	showmenu(option);
	bool ifexit=true; 

	while (ifexit)
	{
		inpush = _getch();
		switch (inpush)
		{
		case 80:		// up
		{
			option++;
			if (option > 9) { option = 1; }
			showmenu(option);
			break;
		}
		case 72:		//down
		{
			option--;
			if (option < 1) { option = 9; }
			showmenu(option);
			break;
		}
		case 13:		//enter
		{
			ifexit = false;
			break;
		}
		}
	}
	return option; 
}

void Menu::showfind(int x)
{
	system("cls");
	HANDLE h;
	cout << "        Меню\n";
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 1; i <= 9; i++)
	{
		if (i == x)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << " -> ";
		}
		else { cout << "    "; }
		switch (i)
		{
		case 1:
		{
			cout << "1. Поиск по названии";
			break;
		}
		case 2:
		{
			cout << "2. Поиск по типу(еда/напиток)";
			break;
		}
		case 3:
		{
			cout << "3. Поиск по сроку годности";
			break;
		}
		}
		SetConsoleTextAttribute(h, 15);
		cout << endl;
	}
}

int Menu::findscreen()
{
	int inpush;

	int option = 1;
	showfind(option);
	bool ifexit = true;

	while (ifexit)
	{
		inpush = _getch();
		switch (inpush)
		{
		case 80:		// up
		{
			option++;
			if (option > 3) { option = 1; }
			showfind(option);
			break;
		}
		case 72:		//down
		{
			option--;
			if (option < 1) { option = 3; }
			showfind(option);
			break;
		}
		case 13:		//enter
		{
			ifexit = false;
			break;
		}
		}
	}
	return option;
}

Menu::~Menu()
{
}
