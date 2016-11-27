#include "IceBox.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Menu.h"

using namespace std; 

void waitenter()
{
	cout << "������� enter"; 
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
	cout << "        ������ ���������\n";
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
	cout << "������� �������� �������� - ";
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
	cout << "��� �������� (0 - ���, 1 - �������) - "; 
	cin >> t; 
	if (t == 1) { cout << "������� ����� - "; cin >> m; }
	else { cout << "������� ����� - "; cin >> m;  }
	cout << "������� ���������� - "; 
	cin >> c; 
	
	char life[10];
	cout << "������� ����, ����� �������� ���� �������� (��.��.��):";
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
	cout << "������� �������� ��������: ";
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
			cout << "� ����� ����������? \n"; 
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
	if (fin == false) { cout << "���� ������� �� ������\n"; waitenter(); }
}

void IceBox::find()
{
	Menu menu; 
	int pick = menu.findscreen();

}

IceBox::~IceBox()
{
}
