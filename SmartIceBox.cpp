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
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	IceBox box;
	box.downloadactivebox();
	Menu menu; 
	system("mode 80,33");
	menu.salute();
	system("mode 50,11");
	int pick = menu.mainscreen(); 
	while (pick != 9)
	{
		switch (pick)
		{
		case 1:
		{
			system("mode 100,15");
			COORD crd = { 90, 100 };
			SMALL_RECT src = { 0, 0, crd.X, crd.Y };
			SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			box.showlist();
			break;
		}
		case 2:
		{
			system("mode 70,15");
			box.add();
			break;
		}
		case 3:
		{
			system("mode 70,15");
			box.del();
			break;
		}
		case 4:
		{
			system("mode 46,10");
			box.sort();
			break;
		}
		case 5:
		{
			system("mode 90,10");
			box.find();
			break;
		}
		case 6: 
		{
			system("mode 90,15");
			COORD crd = { 90, 100 };
			SMALL_RECT src = { 0, 0, crd.X, crd.Y };
			SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			box.watchhistory();
			break;
		}
		case 7:
		{
			system("mode 73,10");
			box.automaticlist();
			break; 
		}
		case 8: 
		{
			system("mode 46,10");
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
		system("mode 50,11");
		pick = menu.mainscreen();
	}
	box.saveactivebox();

	system("mode 80,33");
	menu.bye();
	//system("pause");
}