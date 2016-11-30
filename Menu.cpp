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
	cout << "        ����\n"; 
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
			cout << "1. �������� ������ ��������� � ������������";
			break;
		}
		case 2: 
		{
			cout << "2. �������� ������� � �����������"; 
			break; 
		}
		case 3:
		{
			cout << "3. ������� ������� �� ������������"; 
			break; 
		}
		case 4:
		{
			cout << "4. ���������� ��������� �� ����������";
			break;
		}
		case 5:
		{
			cout << "5. ����� ��������"; 
			break; 
		}
		case 6:
		{
			cout << "6. �������� �������";
			break; 
		}
		case 7:
		{
			cout << "7. �������������� ������ ���������";
			break; 
		}
		case 8: 
		{
			cout << "8. ������";
			break;
		}
		case 9:
		{
			cout << "9. �����";
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
	cout << "        ����\n";
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
			cout << "1. ����� �� ��������";
			break;
		}
		case 2:
		{
			cout << "2. ����� �� ����(���/�������)";
			break;
		}
		case 3:
		{
			cout << "3. ����� �� ����� ��������";
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
