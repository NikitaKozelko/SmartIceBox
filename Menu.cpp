#include "Menu.h"
#include "IceBox.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std; 

void waitenter();

Menu::Menu()
{
}

void Menu::salute()
{
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	cout << endl;
	cout << "                                ¶¶¶¶¶¶¶¶\n";
	cout << "		                ¶¶¶______¶¶\n";
	cout << "	                         ¶¶¶_______¶¶\n";
	cout << "		                  ¶¶_________¶¶\n";
	cout << " 		                   ¶¶_________¶    ¶¶¶¶¶¶\n";
	cout << "		                   ¶¶________¶¶_¶¶¶¶¶3333¶¶¶\n";
	cout << "		 Hello!             ¶¶¶_______¶¶¶¶33333333¶¶¶\n";
	cout << "		                     ¶¶¶______¶¶333333333333¶¶\n";
	cout << "		                      ¶¶¶¶¶¶¶¶¶¶¶33333333333¶¶¶\n";
	cout << "		                       ¶¶¶¶11111¶¶¶¶33333¶¶¶¶¶¶\n";
	cout << "		                       ¶¶11111111111¶¶33¶¶¶¶¶¶¶¶¶¶¶\n";
	cout << "		                     ¶¶1111111111111¶¶¶¶88888888¶¶¶¶\n";
	cout << "		Smart IceBox         ¶111111111111111¶888888888888¶¶¶\n";
	cout << "		Óìíûé õîëîäèëüíèê    ¶¶11111111111¶¶¶¶¶888888888888¶¶\n";
	cout << "		                      ¶¶¶11111111¶¶___¶¶888888888¶¶¶\n         ";
	cout << "                              ¶¶¶¶¶¶111¶¶_____¶¶888888¶¶¶¶\n";
	cout << "		                        ¶¶__¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_¶¶\n";
	cout << "		                        ¶¶¶_¶¶__¶¶____¶¶¶¶¶¶¶___¶¶\n";
	cout << "		                         ¶¶¶¶¶¶¶¶__¶__¶¶¶_¶¶¶¶_¶¶\n";
	cout << "		                          ¶¶_¶_¶¶____¶¶¶¶¶¶__¶¶¶\n";
	cout << "		                           ¶____¶¶¶¶¶¶__¶¶¶¶¶_¶\n";
	cout << "		                           ¶¶_____¶¶¶______¶_¶¶\n";
	cout << "		                            ¶¶______¶¶___¶¶¶¶¶\n";
	cout << "		                             ¶¶______¶¶¶¶¶¶¶¶\n";
	cout << "		                              ¶¶____¶¶____¶¶\n";
	cout << "		                               ¶¶¶¶¶¶¶¶¶_¶¶¶\n";
	cout << "		by Nikita Kozelko              ¶¶¶¶____¶¶¶¶\n";
	cout << "		                                ¶¶_____¶¶¶\n";
	cout << "		                                 ¶¶¶_¶_¶¶\n";
	cout << "		                                  ¶¶¶¶¶¶¶\n\n                   ";
	waitenter();
}

void Menu::showmenu(int x)
{
	system("cls");
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 15);

	cout << "        Ìåíþ\n";
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
			cout << "1. Ïîêàçàòü ñïèñîê ïðîäóêòîâ â õîëîäèëüíèêå";
			break;
		}
		case 2: 
		{
			cout << "2. Ïîëîæèòü ïðîäóêò â õîëîäèëüíèê"; 
			break; 
		}
		case 3:
		{
			cout << "3. Äîñòàòü ïðîäóêò èç õîëîäèëüíèêà"; 
			break; 
		}
		case 4:
		{
			cout << "4. Ñîðòèðîâêà ïðîäóêòîâ ïî ïàðàìåòðàì";
			break;
		}
		case 5:
		{
			cout << "5. Ïîèñê ïðîäóêòà"; 
			break; 
		}
		case 6:
		{
			cout << "6. Ïîêàçàòü èñòîðèþ";
			break; 
		}
		case 7:
		{
			cout << "7. Àâòîìàòè÷åñêèé ñïèñîê ïðîäóêòîâ";
			break; 
		}
		case 8: 
		{
			cout << "8. Íàñòðîéêè";
			break;
		}
		case 9:
		{
			cout << "9. Âûõîä";
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
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "        Ïîèñê ïî êðèòåðèþ\n";
	for (int i = 1; i <= 3; i++)
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
			cout << "1. Ïîèñê ïî íàçâàíèè";
			break;
		}
		case 2:
		{
			cout << "2. Ïîèñê ïî òèïó(åäà/íàïèòîê)";
			break;
		}
		case 3:
		{
			cout << "3. Ïîèñê ïî ñðîêó ãîäíîñòè";
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
		case 27:
		{
			option = 0;
			ifexit = false; 
			break;
		}
		}
	}
	return option;
}

void Menu::showsort(int x)
{
	system("cls");
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "        Ñîðòèðîâêà ïî ïàðàìåòðó\n";
	for (int i = 1; i <= 3; i++)
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
			cout << "1. Ñîðòèðîâêà ïî íàçâàíèþ";
			break;
		}
		case 2:
		{
			cout << "2. Ñîðòèðîâêà ïî òèïó(åäà/íàïèòîê)";
			break;
		}
		case 3:
		{
			cout << "3. Ñîðòèðîâêà ïî ñðîêó ãîäíîñòè";
			break;
		}
		}
		SetConsoleTextAttribute(h, 15);
		cout << endl;
	}
}

int Menu::sortscreen()
{
	int inpush;

	int option = 1;
	showsort(option);
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
			showsort(option);
			break;
		}
		case 72:		//down
		{
			option--;
			if (option < 1) { option = 3; }
			showsort(option);
			break;
		}
		case 13:		//enter
		{
			ifexit = false;
			break;
		}
		case 27:
		{
			option = 0; 
			ifexit = false;
			break;
		}
		}
	}
	return option;
}

void Menu::showsetting(int x)
{
	system("cls");
	HANDLE h;
	cout << "        Íàñòðîéêè\n";
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 1; i <= 3; i++)
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
			cout << "1. Î÷èñòèòü èñòîðèþ ïîêóïîê";
			break;
		}
		case 2:
		{
			cout << "2. Î÷èñòèòü ÷àñòîòó îòäåëüíûõ ïîêóïîê";
			break;
		}
		case 3:
		{
			cout << "3. Î÷èñòèòü òåêóùèé õîëîäèëüíèê";
			break;
		}
		case 4:
		{
			cout << "4. Âåðíóòüñÿ â ãëàâíîå ìåíþ";
			break;
		}
		}
		SetConsoleTextAttribute(h, 15);
		cout << endl;
	}
}

int Menu::settingscreen()
{
	int inpush;

	int option = 1;
	showsetting(option);
	bool ifexit = true;

	while (ifexit)
	{
		inpush = _getch();
		switch (inpush)
		{
		case 80:		// up
		{
			option++;
			if (option > 4) { option = 1; }
			showsetting(option);
			break;
		}
		case 72:		//down
		{
			option--;
			if (option < 1) { option = 4; }
			showsetting(option);
			break;
		}
		case 13:		//enter
		{
			ifexit = false;
			break;
		}
		case 27:
		{
			option = 4;
			ifexit = false;
			break;
		}
		}
	}
	return option;
}

void Menu::bye()
{
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	cout << endl;
	cout << "                                ¶¶¶¶¶¶¶¶\n";
	cout << "		                ¶¶¶______¶¶\n";
	cout << "	                         ¶¶¶_______¶¶\n";
	cout << "		                  ¶¶_________¶¶\n";
	cout << " 		                   ¶¶_________¶    ¶¶¶¶¶¶\n";
	cout << "		                   ¶¶________¶¶_¶¶¶¶¶3333¶¶¶\n";
	cout << "		                    ¶¶¶_______¶¶¶¶33333333¶¶¶\n";
	cout << "		 Goodbye!            ¶¶¶______¶¶333333333333¶¶\n";
	cout << "		                      ¶¶¶¶¶¶¶¶¶¶¶33333333333¶¶¶\n";
	cout << "		                       ¶¶¶¶11111¶¶¶¶33333¶¶¶¶¶¶\n";
	cout << "		                       ¶¶11111111111¶¶33¶¶¶¶¶¶¶¶¶¶¶\n";
	cout << "		                     ¶¶1111111111111¶¶¶¶88888888¶¶¶¶\n";
	cout << "		Smart IceBox         ¶111111111111111¶888888888888¶¶¶\n";
	cout << "		Óìíûé õîëîäèëüíèê    ¶¶11111111111¶¶¶¶¶888888888888¶¶\n";
	cout << "		                      ¶¶¶11111111¶¶___¶¶888888888¶¶¶\n         ";
	cout << "                              ¶¶¶¶¶¶111¶¶_____¶¶888888¶¶¶¶\n";
	cout << "		                        ¶¶__¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_¶¶\n";
	cout << "		                        ¶¶¶_¶¶__¶¶____¶¶¶¶¶¶¶___¶¶\n";
	cout << "		                         ¶¶¶¶¶¶¶¶__¶__¶¶¶_¶¶¶¶_¶¶\n";
	cout << "		                          ¶¶_¶_¶¶____¶¶¶¶¶¶__¶¶¶\n";
	cout << "		                           ¶____¶¶¶¶¶¶__¶¶¶¶¶_¶\n";
	cout << "		                           ¶¶_____¶¶¶______¶_¶¶\n";
	cout << "		                            ¶¶______¶¶___¶¶¶¶¶\n";
	cout << "		                             ¶¶______¶¶¶¶¶¶¶¶\n";
	cout << "		                              ¶¶____¶¶____¶¶\n";
	cout << "		                               ¶¶¶¶¶¶¶¶¶_¶¶¶\n";
	cout << "		by Nikita Kozelko              ¶¶¶¶____¶¶¶¶\n";
	cout << "		                                ¶¶_____¶¶¶\n";
	cout << "		                                 ¶¶¶_¶_¶¶\n";
	cout << "		                                  ¶¶¶¶¶¶¶\n\n                   ";
	waitenter();
	exit; 
}

Menu::~Menu()
{
}
