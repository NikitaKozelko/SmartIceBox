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
	cout << "        ������ ���������\n";
	for (int i = 0; i < size; i++)
	{
		cout << i << ". "; 
		arr[i].show();
	}
}

void IceBox::add()
{
	system("cls");
	cout << "������� �������� �������� - ";
	char ch, charr[30];
	int t=-1, m, c; 
	cin.get(ch);
	while (ch != '\n')
	{
		t++; 
		charr[t] = ch;
		cin.get(ch);
	}
	cout << "��� �������� (0 - ���, 1 - �������) - "; 
	cin >> t; 
	if (t == 1) { cout << "������� ����� - "; cin >> m; }
	else { cout << "������� ����� - "; cin >> m;  }
	cout << "������� ���������� - "; 
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
