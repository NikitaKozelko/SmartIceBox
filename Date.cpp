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

int Date::raznost(char str1[10], char str2[10])
{
	int month1 = (str1[3] - '0') * 10 + (str1[4] - '0');
	int day1 = (str1[0] - '0') * 10 + (str1[1] - '0');
	int year1 = (str1[6] - '0') * 10 + (str1[7] - '0');
	int day2 = (str2[0] - '0') * 10 + (str2[1] - '0');
	int month2 = (str2[3] - '0') * 10 + (str2[4] - '0');
	int year2 = (str2[6] - '0') * 10 + (str2[7] - '0');
	
	int answer;
	if (month1 == month2) { answer = day2 - day1; }
	if ((month2 > month1) && (year1 == year2)) { answer = 31 - day1 + (month2 - month1 - 1) * 31 + day2; }

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
	int year1 = (buffer[6]-'0')*10 + (buffer[7] - '0');
	int day2 = (str2[0] - '0') * 10 + (str2[1]-'0');
	int month2 = (str2[3] - '0') * 10 + (str2[4] - '0');
	int year2 = (str2[6] - '0') * 10 + (str2[7] - '0'); 

	int answer; 
	if (month1 == month2) { answer = day2 - day1; }
	if ((month2 > month1) && (year1 == year2)) { answer = 31 - day1 + (month2 - month1 - 1) * 31 + day2; }
	if ((month2 > month1) && (year1 > year2)) { answer = -(day1 + (month1 - 1) * 31 + (13 - month2 - 1) * 31 + (31 - day2)); }
	if ((month2 < month1) && (year1 == year2)) { answer = -(day1 + (month1 - month2 - 1) * 31 + (31 - day2)); }
	if ((month2 < month1) && (year1 < year2)) { answer = day2 + (month2 -1)*31 + (13-month1 - 1) * 31 + (31 - day1); }

	return answer;
}

bool Date::compare(char s1[10], char s2[10])
{
	int month1 = (s1[3] - '0') * 10 + (s1[4] - '0');
	int day1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	int year1 = (s1[6] - '0') * 10 + (s1[7] - '0');
	int day2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	int month2 = (s2[3] - '0') * 10 + (s2[4] - '0');
	int year2 = (s2[6] - '0') * 10 + (s2[7] - '0');

	bool anwer = true; 
	if (year1 > year2) { return true; }
	if (year1 < year2) { return false; }
	if (month1 > month2) { return true; }
	if (month1 < month2) { return false; }
	if (day1 > day2) { return true; }
	else { return false; }
}

Date::~Date()
{
}
