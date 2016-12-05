#pragma once
class Menu
{
public:
	Menu();
	void salute();
	void showmenu(int); 
	int mainscreen(); 
	void showfind(int); 
	int findscreen();
	int sortscreen();
	void showsort(int);
	void showsetting(int);
	int settingscreen();
	void bye();
	~Menu();
};

