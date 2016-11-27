#include "Product.h"
#include <iostream>

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

int Product::getcount()
{
	return count; 
}

void Product::dimincount(int a)
{
	count = count - a; 
}

Product::~Product()
{
}
