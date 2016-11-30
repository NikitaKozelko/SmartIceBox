#pragma once
#include "Product.h"

class IceBox
{
private: 
	Product arr[10000];
	int size; 
public:
	IceBox();
	void showlist();
	void add();
	void del();
	void sort(); 
	void find();
	void downloadactivebox();
	void saveactivebox();
	void watchhistory();
	void automaticlist();
	~IceBox();
};

