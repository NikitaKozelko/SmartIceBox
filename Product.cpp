#include "Product.h"
#include <iostream>

using namespace std; 

Product::Product()
{
}

Product::Product(char n[30], int t, int m, int c) : type(t), mass(m), count(c)
{
	int i = 0;
	while (n[i] != '\n')
	{
		name[i] = n[i];
	}
}

void Product::show()
{
	cout << "Название - " << name << "; ";
	if (type == 1) { cout << "обьёмом - " << mass << "; "; }
	else { cout << "массой - " << mass << "; "; }
	cout << "в количестве - " << count << ";"<< endl;
}

Product::~Product()
{
}
