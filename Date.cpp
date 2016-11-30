#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <ctime>
#include <iostream>

using namespace std;

Date::Date()
{
}

bool Date::isequal(char str1[10], char str2[10])
{
	bool answer = true; 
	for (int i=0; i<=7; i++)
		if (str1[i]!=str2[i])
		{
			answer = false; 
		}
	return answer; 
}

int Date::dateraznost(char str2[10])
{
	char buffer[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%d.%m.%Y";
	strftime(buffer, 80, format, timeinfo);
	int month1 = (buffer[3] - '0') * 10 + (buffer[4] - '0');
	int day1 = (buffer[0] - '0') * 10 + (buffer[1] - '0');
	int day2 = (str2[0] - '0') * 10 + (str2[1]-'0');
	int month2 = (str2[3] - '0') * 10 + (str2[4] - '0');

	int answer; 
	if (month1 == month2) { answer = day2 - day1; }
	if (month1 < month2) { answer = 31 - day1 + day2+(month2-month1-1)*31; }
	if (month1 > month2) { answer = 31 - day1 + (12 - month1 - 1) * 31 + (month2 - 1) * 31 + day2; }
	return answer; 
}

Date::~Date()
{
}
