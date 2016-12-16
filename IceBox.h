#pragma once
#include "Product.h"

class IceBox
{
private: 
	Product arr[10000];
	int size; 
public:
	IceBox();
	void showlistcolorON();
	void showlistcolorOFF();
	void add();
	void del();
	void sort(); 
	void find();
	void downloadactivebox();
	void saveactivebox();
	void watchhistory();
	void automaticlist();
	void setting();
	~IceBox();
};

