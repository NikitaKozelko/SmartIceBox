#pragma once
class Product
{
private:
	char name[30];
	int type;	//0 - food, 1 - drink
	int mass;	//or volume for drink
	int count; 
	char shelflife[10]; 
public:
	Product();
	Product(char*, int, int, int, char*);
	void show();
	bool isequal(char*);
	int getcount();
	void dimincount(int);
	~Product();
};

