#include <iostream>
#include "Menu.h"
#include "IceBox.h"
#include <conio.h>
using namespace std; 

int main()
{
	setlocale(LC_ALL, "Russian");
	IceBox box;
	//box.activebox();
	Menu menu; 
	menu.salute();
	int pick = menu.mainscreen(); 
	switch (pick)
	{
	case 1:
	{
		box.showlist();
		break; 
	}
	case 2: 
	{
		box.add();
		break;
	}
	case 3:
	{
		box.del();
		break;
	}
	default:
	{
		system("cls");
		cout << "Произошла ошибка. Запрос неизвестной операции.\nНажмите ENTER чтобы вернуться в главное меню или ESC для выхода";
		bool ifexit = true; 
		while (ifexit)
		{
			int inpush;
			inpush = _getch();
			switch (inpush)
			{
			case 13: 
			{
				ifexit = false; 
				break; 
			}
			case 27:
			{
				ifexit = false; 
				exit; 
			}
			}
		}
	}
	}
	system("pause");
}