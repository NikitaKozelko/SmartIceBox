#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include <iostream>
#include "Date.h"
#include "Forlist.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <windows.h>

using namespace std; 

Product::Product()
{
}

Product::Product(char n[30], int t, int m, int c, char l[30], int x) : type(t), mass(m), count(c)
{
	int i = 0;
	while (n[i] != '\n')
	{
		name[i] = n[i];
		i++;
	}
	name[i] = '\n';

	for (int j = 0; j <= 7; j++)
	{
		shelflife[j] = l[j];
	}

	if (x == 1)
	{
		ifstream infile("automaticlist.txt", ios::binary);
		double day;
		infile.seekg(0, ios::end);
		int en = infile.tellg();
		infile.seekg(0, ios::beg);
		int a = infile.tellg();
		Date d;
		i = -1; Forlist f[1000];
		while ((infile) && (!infile.eof()) && ((en - a) > 2))
		{
			i++;
			char n[30], l[10]; 
			infile.read(reinterpret_cast<char*>(&n), sizeof(char[30]));
			infile.read(reinterpret_cast<char*>(&day), sizeof(double));
			infile.read(reinterpret_cast<char*>(&l), sizeof(char[10]));
			f[i] = Forlist(n, day, l);
			a = infile.tellg();
		}
		infile.close();
		bool b = true;
		for (int j = 0; j <= i; j++)
		{
			if (f[j].isequal(name))
			{
				b = false;
				day = day + d.dateraznost(l);
				day = day / 2;
				f[j].setlastcustom(l);
			}
		}

		if (b)
		{
			i++;
			f[i].setname(name);
			f[i].day = 0;
			char buffer[80];
			time_t seconds = time(NULL);
			tm* timeinfo = localtime(&seconds);
			char* format = "%d.%m.%Y";
			strftime(buffer, 80, format, timeinfo);
			buffer[6] = buffer[8]; buffer[7] = buffer[9];
			f[i].setlastcustom(buffer);
		}

		ofstream outfile("automaticlist.txt", ios::binary | ios::trunc);
		//char* name; char* life; int type, mass, count;
		for (int j = 0; j <= i; j++)
		{
			n = f[j].name;
			day = f[j].day;
			l = f[j].lastcustom;
			outfile.write(reinterpret_cast<char*>(n), sizeof(char[30]));
			outfile.write(reinterpret_cast<char*>(&day), sizeof(double));
			outfile.write(reinterpret_cast<char*>(l), sizeof(char[10]));
		}
		outfile.close();

		ofstream outfile1("history.txt", ios::binary | ios::app);

		outfile1.write(reinterpret_cast<char*>(n), sizeof(char[30]));
		outfile1.write(reinterpret_cast<char*>(&t), sizeof(int));
		outfile1.write(reinterpret_cast<char*>(&m), sizeof(int));
		outfile1.write(reinterpret_cast<char*>(&c), sizeof(int));
		outfile1.write(reinterpret_cast<char*>(l), sizeof(char[10]));
		outfile1.close();
	}
}

void Product::show()
{
	Date d; 
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = d.dateraznost(shelflife);
	SetConsoleTextAttribute(h, 15);
	//cout << a<<endl; 
	if (a > 3)
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	if (a < 0) {
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	}
	cout << "Название - ";
	int i = 0;
	while (name[i]!='\n')
	{
		cout << name[i]; i++;
	}
	cout << ";";
	if (type == 1) { cout << "обьёмом - " << mass << "; "; }
	else { cout << "массой - " << mass << "; "; }
	cout << "в количестве - " << count << ";";
	cout << "со сроком годности: ";  
	for (i = 0; i <= 7; i++)
	{
		cout << shelflife[i]; 
	}
	cout << ";"<<endl;
	SetConsoleTextAttribute(h, 15);
}

bool Product::isequal(char n[30])
{
	bool answer = true;
	int i = 0;
	while (1)
	{
		if ((n[i] == '\n')&&(name[i] == '\n')) { break; }
		if ((n[i] == '\n') || (name[i] == '\n')) { answer = false; break; }
		if (n[i] != name[i]) { answer = false; break; }
		i++; 
	}
	return answer; 
}

bool Product::isequaltype(int a)
{
	bool answer = true; 
	if (a != type) { answer = false;  }
	return answer; 
}

bool Product::isequaldate(char l[10])
{
	Date d; 
	bool answer = d.isequal(shelflife, l);
	return answer; 
}

char* Product::getname()
{
	return name;
}

int Product::gettype()
{
	return type;
}

int Product::getmass()
{
	return mass; 
}

int Product::getcount()
{
	return count; 
}

char* Product::getdate()
{
	return shelflife;
}

void Product::dimincount(int a)
{
	count = count - a; 
}

Product::~Product()
{
}
