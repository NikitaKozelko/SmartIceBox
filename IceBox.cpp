#include "IceBox.h"
#include <iostream>
#include <conio.h>

using namespace std; 

IceBox::IceBox()
{
}

void IceBox::showlist()
{
	system("cls");
	cout << "        —писок продуктов\n";
	for (int i = 0; i < size; i++)
	{
		cout << i << ". "; 
		arr[i].show();
	}
}

void IceBox::add()
{
	system("cls");
	cout << "¬ведите название продукта - ";
	char ch, charr[30];
	int t=-1, m, c; 
	cin.get(ch);
	while (ch != '\n')
	{
		t++; 
		charr[t] = ch;
		cin.get(ch);
	}
	cout << "“ип продукта (0 - еда, 1 - напиток) - "; 
	cin >> t; 
	if (t == 1) { cout << "¬ведите обьЄм - "; cin >> m; }
	else { cout << "¬ведите массу - "; cin >> m;  }
	cout << "¬ведите количество - "; 
	cin >> c; 
	
	size++; 
	arr[size] = Product(charr, t, m, c);
}

void IceBox::del()
{

}

IceBox::~IceBox()
{
}
