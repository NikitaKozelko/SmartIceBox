#include "Forlist.h"

Forlist::Forlist()
{
}

Forlist::Forlist(char n[30], double d, char l[30]) : day(d)
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
		lastcustom[j] = l[j];
	}
}

bool Forlist::isequal(char n[30])
{
	bool answer = true;
	int i = 0;
	while (1)
	{
		if ((n[i] == '\n') && (name[i] == '\n')) { break; }
		if ((n[i] == '\n') || (name[i] == '\n')) { answer = false; break; }
		if (n[i] != name[i]) { answer = false; break; }
		i++;
	}
	return answer;
}

void Forlist::setname(char n[30])
{
	int i = -1;
	while (n[i] != '\n')
	{
		i++;
		name[i] = n[i]; 
	}
}

void Forlist::setlastcustom(char l[10])
{
	for (int j = 0; j <= 7; j++)
	{
		lastcustom[j] = l[j];
	}
}

Forlist::~Forlist()
{
}
