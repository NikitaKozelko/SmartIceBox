#include "Menu.h"
#include <iostream>
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
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 1; i < 5; i++)
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
			cout << "1";
			break;
		}
		case 2: 
		{
			cout << "2"; 
			break; 
		}
		case 3:
		{
			cout << "3"; 
			break; 
		}
		case 4:
		{
			cout << "4"; 
			break; 
		}
		}
		SetConsoleTextAttribute(h, 15);
		cout << endl; 
	}
	system("pause");
}

Menu::~Menu()
{
}
