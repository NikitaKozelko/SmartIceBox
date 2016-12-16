#include "IceBox.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Menu.h"
#include "Date.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std; 

template<typename T>
T fromString(const std::string& s)
{
	std::istringstream iss(s);
	T res;
	iss >> res;
	return res;
}

void waitenter()
{
	fflush(stdin);
	cout << "Нажмите enter"; 
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

void IceBox::showlistcolorON()
{
	system("cls");
	cout << "        Список продуктов\n";
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << ". "; 
		arr[i].showcolorON();
	}
	waitenter();
}

void IceBox::showlistcolorOFF()
{
	system("cls");
	cout << "        Список продуктов\n";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". ";
		arr[i].showcolorOFF();
	}
	waitenter();
}

void IceBox::add()
{
	system("cls");
	cout << "Введите название продукта - ";
	char ch, charr[30];
	int t = -1, m, c;
	string mm, cc;
	fflush(stdin);
	cin.get(ch);
	while (ch == '\n')
		cin.get(ch);
	while (ch != '\n')
	{
		t++;
		charr[t] = ch;
		cin.get(ch);
	}
	while (charr[t] == ' ')
	{
		t--; 
	}
	t++; charr[t] = '\n';
	cout << "Тип продукта (0 - еда, 1 - напиток) - "; 
	cin >> t; 
	cin.ignore();
	if (t == 1) 
		{  
			bool b = false;
			while (!b)
			{
				b = true;
				cout << "Введите обьём (в милилитрах) - "; 
				getline(cin, mm, '\n');
				for (int i = 0; i < mm.size(); i++)
				{
					if (mm[i]<'0' || mm[i]>'9')
					{
						b = false;
						cout << "Некорректный ввод данных. Требуется ввести целое число." << endl;
						break;
					}
				}
			}
			m = fromString<int>(mm);
		}
	else { 
			bool b = false;
			while (!b)
			{
				b = true;
				cout << "Введите массу(в граммах) - "; 
				fflush(stdin);
				getline(cin, mm, '\n');
				if (mm.size() <= 1)
				{
					b = false;
				}
				for (int i = 0; i < mm.size(); i++)
				{
					
					if (mm[i]<'0' || mm[i]>'9')
					{
						b = false; 
						cout << "Некорректный ввод данных. Требуется ввести целое число." << endl;
						break;
					}
				}
			}
			m = fromString<int>(mm);
		 }

	bool b = false;
	while (!b)
	{
		b = true;
		cout << "Введите количество - ";
		getline(cin, cc, '\n');
		for (int i = 0; i < cc.size(); i++)
		{
			if (cc[i]<'0' || cc[i]>'9')
			{
				b = false;
				cout << "Некорректный ввод данных. Требуется ввести целое число." << endl;
				break; 
			}
		}
	}
	c = fromString<int>(cc);
	
	char life[10];
	cout << "Введите дату, когда истекает срок годности (ДД.ММ.ГГ):";
	fflush(stdin);

	ch = cin.get();
	if (ch == '\n')
	{
		for (int i = 0; i <= 7; i++)
		{
			cin.get(life[i]);
		}
	}
	else
	{
		life[0] = ch;
		for (int i = 1; i <= 7; i++)
		{
			cin.get(life[i]);
		}
	}

	arr[size] = Product(charr, t, m, c, life, 1);

	size++;
}

void IceBox::del()
{
	system("cls");
	fflush(stdin);
	cout << "Введите название продукта: ";
	char ch, charr[30]; int t = -1;
	cin.get(ch);
	while (ch == '\n')
	{
		cin.get(ch);
	}
	while (ch != '\n')
	{
		t++;
		charr[t] = ch;
		cin.get(ch);
	}
	while (charr[t] == ' ')
	{
		t--;
	}
	t++; charr[t] = '\n';
	int a; bool fin=false; 
	for (int i = 0; i < size; i++)
	{
		if (arr[i].isequal(charr))
		{
			fin = true;
			cout << "В каком количестве(в граммах/милилитрах)? \n"; 
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
	if (fin == false) { cout << "Этот продукт не найден\n"; waitenter(); }
}

void IceBox::sort()
{
	Menu menu;
	int pick = menu.sortscreen();
	system("cls");
	switch (pick)
	{
	case 0:
	{
		break; 
	}
	case 1:
	{
		Product p; 
		
		int step = size-1; 
		double fakt = 1.2473309;

		while (step > 1)
		{
			for (int i = 0; i + step < size; i++)
			{
				string s1 = arr[i].getname();
				string s2 = arr[i + step].getname();
				if (s1 > s2)
				{
					p = arr[i]; arr[i] = arr[i+step]; arr[i+step] = p;
				}
			}
			step = step / fakt; 
		}
		
		for (int i = 0; i < size - 1; i++)
		{
			bool swapped = false;
			for (int j = 0; j < size - i - 1; j++)
			{
				string s1 = arr[j].getname();
				string s2 = arr[j + 1].getname();
				if (s1 > s2)
				{
					p = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = p;
					swapped = true; 
				}
			}
			if (!swapped) break; 
		}
		break;
	}
	case 2:
	{
		Product p;

		int step = size - 1;
		double fakt = 1.2473309;

		while (step > 1)
		{
			for (int i = 0; i + step < size; i++)
			{
				int a1 = arr[i].gettype();
				int a2 = arr[i + step].gettype();
				if (a1 > a2)
				{
					p = arr[i]; arr[i] = arr[i + step]; arr[i + step] = p;
				}
			}
			step = step / fakt;
		}

		for (int i = 0; i < size - 1; i++)
		{
			bool swapped = false;
			for (int j = 0; j < size - i - 1; j++)
			{
				int a1 = arr[j].gettype();
				int a2 = arr[j + 1].gettype();
				if (a1 > a2)
				{
					p = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = p;
					swapped = true;
				}
			}
			if (!swapped) break;
		}
		break;
	}
	case 3:
	{
		Product p; Date d; 

		int step = size - 1;
		double fakt = 1.2473309;

		while (step > 1)
		{
			for (int i = 0; i + step < size; i++)
			{
				char* s1 = arr[i].getdate();
				char* s2 = arr[i + step].getdate();
				if (d.compare(s1, s2))
				{
					p = arr[i]; arr[i] = arr[i + step]; arr[i + step] = p;
				}
			}
			step = step / fakt;
		}

		for (int i = 0; i < size - 1; i++)
		{
			bool swapped = false;
			for (int j = 0; j < size - i - 1; j++)
			{
				char* s1 = arr[j].getdate();
				char* s2 = arr[j + 1].getdate();
				if (d.compare(s1, s2))
				{
					p = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = p;
					swapped = true;
				}
			}
			if (!swapped) break;
		}
		break;
	}
	default:
		break;
	}
	if (pick!=0){
		cout << "Сортировка по заданному параметру произведена" << endl;
		waitenter();
	}	
}

void IceBox::find()
{
	Menu menu; 
	int pick = menu.findscreen();
	system("cls");
	switch (pick)
	{
	case 0:
	{
		break; 
	}
	case 1:
	{
		cout << "Введите название интересующего товара - ";
		char ch, charr[30]; int i = -1;
		fflush(stdin);
		cin.get(ch); 
		while (ch == '\n')
			cin.get(ch);
		while (ch != '\n')
		{			
			i++; 
			charr[i] = ch; 
			cin.get(ch);
		} 
		while (charr[i] == ' ')
		{
			i--;
		}
		i++; charr[i] = '\n'; 
		bool b = true;
		for (i = 0; i < size; i++)
		{
			if (arr[i].isequal(charr))
			{
				arr[i].showcolorON();
				b = false; 
			}
		}
		if (b) { cout << "Данный продукт не найден\n"; }
		waitenter();
		break;
	}
	case 2: 
	{
		int a;
		cout << "Введите интересующий вас тип(еда(0)/напиток(1)) - ";
		fflush(stdin);
		cin >> a; 
		bool b = true; 
		for (int i = 0; i < size; i++)
		{
			if (arr[i].isequaltype(a))
			{
				arr[i].showcolorON();
				b = false;
			}
		}
		
		if (b) { cout << "Данный продукт не найден\n"; }
		waitenter();
		break; 
	}
	case 3: 
	{
		char life[10], ch;
		cout << "Введите интересующую дату, когда истекает срок годности (ДД.ММ.ГГ):";
		fflush(stdin);
		ch = cin.get();
		if (ch == '\n')
		{
			for (int i = 0; i <= 7; i++)
			{
				cin.get(life[i]);
			}
		}
		else 
		{
			life[0] = ch;
			for (int i = 1; i <= 7; i++)
			{
				cin.get(life[i]);
			}
		}
		bool b = true;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].isequaldate(life))
			{
				arr[i].showcolorOFF();
				b = false;
			}
		}
		if (b) { cout << "Данный продукт не найден\n"; }
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
	while ((infile)&&(!infile.eof())&&((en-a)>2))
	{
		i++;
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
	system("cls");
	ifstream infile("automaticlist.txt", ios::binary);
	char name[30], life[10]; double day;
	infile.seekg(0, ios::end);
	int en = infile.tellg();
	infile.seekg(0, ios::beg);
	int a = infile.tellg();
	Date d;  bool bb = true;
	while ((infile) && (!infile.eof()) && ((en - a)>2))
	{
		infile.read(reinterpret_cast<char*>(&name), sizeof(char[30]));
		infile.read(reinterpret_cast<char*>(&day), sizeof(double));
		infile.read(reinterpret_cast<char*>(&life), sizeof(char[10]));
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
			if (bb == true) { cout << "     Список продуктов\n"; }
			cout << " - ";
			int j=0; 
			bb = false;
			while (name[j] != '\n')
			{
				cout << name[j];
				j++;
			}
			cout << endl;
		}
		a = infile.tellg();
	}
	if (bb) { cout << "Малое количество продуктов лежали в этом холодильнике, чтобы вам помочь." << endl; }
	waitenter();
	infile.close();
}

void IceBox::watchhistory()
{
	system("cls");
	ifstream infile("history.txt", ios::binary);
	char name[30], shelflife[10]; int type, mass, count, i = -1;
	infile.seekg(0, ios::end);
	int en = infile.tellg();
	infile.seekg(0, ios::beg);
	int a = infile.tellg();
	Product ar; bool b = true; 
	while ((infile) && (!infile.eof()) && ((en - a)>2))
	{
		i++;
		if (b) { b = false; cout << "     История" << endl; } 
		infile.read(reinterpret_cast<char*>(&name), sizeof(char[30]));
		infile.read(reinterpret_cast<char*>(&type), sizeof(int));
		infile.read(reinterpret_cast<char*>(&mass), sizeof(int));
		infile.read(reinterpret_cast<char*>(&count), sizeof(int));
		infile.read(reinterpret_cast<char*>(&shelflife), sizeof(char[10]));
		ar = Product(name, type, mass, count, shelflife, 0);
		ar.showcolorOFF();
		a = infile.tellg();
	}
	if (b) { cout << "История хранения продуктов - пуста." << endl; }
	infile.close();
	waitenter();
}

void IceBox::setting()
{
	Menu m;
	int a = m.settingscreen();

	switch (a)
	{
	case 1: 
	{
		ofstream outfile("history.txt", ios::trunc);
		outfile.close();
		break;
	}
	case 2:
	{
		ofstream outfile("automaticlist.txt", ios::binary | ios::trunc);
		outfile.close();
		break;
	}
	case 3: 
	{
		ofstream outfile("activebox.txt", ios::trunc);
		outfile.close();
		size = 0; 
		break;
	}
	case 4:
	{
		break; 
	}
	default:
		break;
	}
}

IceBox::~IceBox()
{
	delete arr; 
}
