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
	for (int i = 1; i <= 8; i++)
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
			cout << "4. Поиск продукта"; 
			break; 
		}
		case 5:
		{
			cout << "5. Показать историю";
			break; 
		}
		case 6:
		{
			cout << "6. Автоматический список продуктов";
			break; 
		}
		case 7: 
		{
			cout << "7. Настройки";
			break;
		}
		case 8:
		{
			cout << "8. Выход";
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
			if (option > 8) { option = 1; }
			showmenu(option);
			break;
		}
		case 72:		//down
		{
			option--;
			if (option < 1) { option = 8; }
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

Menu::~Menu()
{
}
