#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
#include "IceBox.h"
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std; 
//изменить сортировку на быструю 

int main()
{/*
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	cout << "Current Datetime:" << asctime(timeinfo) << endl;  */

	char buffer[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%m %d $%Y";
	strftime(buffer, 80, format, timeinfo);
	cout << "Current Datetime: " << buffer << endl;

	system("pause");

	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	IceBox box;
	box.downloadactivebox();
	Menu menu; 
	//system("mode 100,30");
	menu.salute();
	int pick = menu.mainscreen(); 
	while (pick != 9)
	{
		switch (pick)
		{
		case 1:
		{
			//system("mode 90,15");
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
		case 4:
		{
			box.sort();
			break;
		}
		case 5:
		{
			box.find();
			break;
		}
		case 6: 
		{
			box.watchhistory();
			break;
		}
		case 7:
		{
			box.automaticlist();
			break; 
		}
		case 8: 
		{
			box.setting();
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
		pick = menu.mainscreen();
	}
	box.saveactivebox();
	system("pause");
}