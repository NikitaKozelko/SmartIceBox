#define _CRT_SECURE_NO_WARNINGS
#include "Forlist.h"
#include <ctime>

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

void Forlist::setlastcustom()
{
	char buffer[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%d.%m.%Y";
	strftime(buffer, 80, format, timeinfo);
	buffer[6] = buffer[8]; buffer[7] = buffer[9];
	for (int j = 0; j <= 7; j++)
	{
		lastcustom[j] = buffer[j];
	}
}

Forlist::~Forlist()
{
}
