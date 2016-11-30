#pragma once
class Forlist
{
	
public:
	char name[30];
	double day;
	char lastcustom[10];
	Forlist();
	Forlist(char*, double, char*);
	bool isequal(char*);
	void setname(char*);
	void setlastcustom(char*);
	~Forlist();
};

