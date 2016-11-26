#pragma once
class Product
{
private:
	char name[30];
	int type;	//0 - food, 1 - drink
	int mass;	//or volume for drink
	int count; 
public:
	Product();
	Product(char*, int, int, int);
	void show();
	~Product();
};

