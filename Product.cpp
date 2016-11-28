#include "Product.h"
#include <iostream>
#include "Date.h"

using namespace std; 

Product::Product()
{
}

Product::Product(char n[30], int t, int m, int c, char l[30]) : type(t), mass(m), count(c)
{
	int i = 0;
	while (n[i] != '\n')
	{
		name[i] = n[i];
		i++;
		//cout << "f"; 
	}
	name[i] = '\n';

	for (int j = 0; j <= 7; j++)
	{
		shelflife[j] = l[j];
	}
}

void Product::show()
{
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
