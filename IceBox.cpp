#include "IceBox.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Menu.h"
#include "Date.h"
#include <fstream>
#include <iostream>
#include <sstream>

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

	arr[size] = Product(charr, t, m, c, life, 1);

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

void IceBox::sort()
{

}

void IceBox::find()
{
	Menu menu; 
	int pick = menu.findscreen();
	system("cls");
	switch (pick)
	{
	case 1:
	{
		cout << "������� �������� ������������� ������ - ";
		char ch, charr[30]; int i = -1;
		cin.ignore(10, '\n');
		cin.get(ch); 
		while (ch != '\n')
		{			
			i++; 
			charr[i] = ch; 
			cin.get(ch);
		} 
		i++; charr[i] = '\n'; 
		bool b = true;
		for (i = 0; i < size; i++)
		{
			if (arr[i].isequal(charr))
			{
				arr[i].show();
				b = false; 
			}
		}
		if (b) { cout << "������ ������� �� ������\n"; }
		waitenter();
		break;
	}
	case 2: 
	{
		int a;
		cout << "������� ������������ ��� ���(���(0)/�������(1)) - ";
		cin >> a; 
		bool b = true; 
		for (int i = 0; i < size; i++)
		{
			if (arr[i].isequaltype(a))
			{
				arr[i].show();
				b = false;
			}
		}
		
		if (b) { cout << "������ ������� �� ������\n"; }
		waitenter();
		break; 
	}
	case 3: 
	{
		char life[10];
		cout << "������� ������������ ����, ����� �������� ���� �������� (��.��.��):";
		cin.ignore(10,'\n');
		for (int i = 0; i <= 7; i++)
		{
			cin.get(life[i]);
		}
		bool b = true;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].isequaldate(life))
			{
				arr[i].show();
				b = false;
			}
		}
		if (b) { cout << "������ ������� �� ������\n"; }
		waitenter();
		break;
	}
	default:
		break;
	}
}

void IceBox::downloadactivebox()
{
	ifstream infile("activebox.txt", ios::binary);
	char name[30], shelflife[10]; int type, mass, count, i=-1;
	infile.seekg(0, ios::end);
	int en = infile.tellg();
	infile.seekg(0, ios::beg);
	int a = infile.tellg();
	cout << a<<endl;
	while ((infile)&&(!infile.eof())&&((en-a)>2))
	{
		i++;
		cout << "asdasd" << endl; 
		infile.read(reinterpret_cast<char*>(&name), sizeof(char[30]));
		infile.read(reinterpret_cast<char*>(&type), sizeof(int));
		infile.read(reinterpret_cast<char*>(&mass), sizeof(int));
		infile.read(reinterpret_cast<char*>(&count), sizeof(int));
		infile.read(reinterpret_cast<char*>(&shelflife), sizeof(char[10]));
		arr[i] = Product(name, type, mass, count, shelflife, 0); 
		a = infile.tellg();
	}
	i++;
	size = i; 
	infile.close();
}

void IceBox::saveactivebox()
{
	ofstream outfile("activebox.txt", ios::binary | ios::trunc);
	char* name; char* life; int type, mass, count;
	for (int i = 0; i < size; i++)
	{
		name = arr[i].getname(); 
		type = arr[i].gettype();
		mass = arr[i].getmass();
		count = arr[i].getcount();
		life = arr[i].getdate();
		outfile.write(reinterpret_cast<char*>(name), sizeof(char[30]));
		outfile.write(reinterpret_cast<char*>(&type), sizeof(int)); 
		outfile.write(reinterpret_cast<char*>(&mass), sizeof(int));
		outfile.write(reinterpret_cast<char*>(&count), sizeof(int));
		outfile.write(reinterpret_cast<char*>(life), sizeof(char[10]));
	}
	outfile.close();
}

void IceBox::automaticlist()
{
	ifstream infile("automaticlist.txt", ios::binary);
	char name[30], life[10]; double day;
	infile.seekg(0, ios::end);
	int en = infile.tellg();
	infile.seekg(0, ios::beg);
	int a = infile.tellg();
	//cout << a << endl;
	Date d; 
	while ((infile) && (!infile.eof()) && ((en - a)>2))
	{
		infile.read(reinterpret_cast<char*>(&name), sizeof(char[30]));
		infile.read(reinterpret_cast<char*>(&day), sizeof(double));
		infile.read(reinterpret_cast<char*>(&life), sizeof(char[10]));
	//	cout << life << endl;
		bool b = false; 
		for (int i = 0; i < size; i++)
		{
			if (arr[i].isequal(name))
			{
				b = true; 
			}
		}
		if ((b == false)&&((d.dateraznost(life) <= day)))
		{
			cout << " - ";
			int j=0; 
			while (name[j] != '\n')
			{
				cout << name[j];
				j++;
			}
			cout << endl;
		}
		a = infile.tellg();
	}
	waitenter();
}

void IceBox::watchhistory()
{

}

IceBox::~IceBox()
{
}
