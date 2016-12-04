#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::setDate(int m, int d, int y)
{
	day = d;
	month = m;
	year = y;
}

bool operator==(const Date &thi, const Date &tha)
{
	return thi.day == tha.day && thi.month == tha.month && thi.year == tha.year;
}

bool operator!=(const Date &thi, const Date &tha)
{
	return !operator==(tha,thi);
}

bool operator>(const Date &thi, const Date &tha)
{
	if (thi.year != tha.year)
		return thi.year > tha.year;
	else if (thi.month != tha.month)
		return thi.month > tha.month;
	else if (thi.day != tha.day)
		return thi.day > tha.day;
	return false;
}
bool operator<(const Date &thi, const Date &tha)
{
	return !operator>(thi, tha) && thi != tha;
}
bool operator>=(const Date &thi, const Date &tha)
{
	return operator==(thi, tha) || operator>(thi, tha);
}
bool operator<=(const Date &thi, const Date &tha)
{
	return operator==(thi, tha) || operator<(thi, tha);
}

ostream& operator<<(ostream& out, Date &date)
//Printing the Date to the file-->Not needed
//and printing the Date to standard output-->Yes
{
    out << setfill('0') << setw(2) << date.month << '/' << setfill('0') << setw(2) << date.day << '/' << date.year;
	return out;
}

istream &operator>>(istream &in, Date &date) {
    //For inputting the Date from the file to the inventory
    //also for entering the Date manually
    string input;
    in >> input;
    string tempMonth = input.substr(0, 2);
    string tempDay = input.substr(3, 2);
    string tempYear = input.substr(6, 4);
    date.month = atoi(tempMonth.c_str());
    date.day = atoi(tempDay.c_str());
    date.year = atoi(tempYear.c_str());
	return in;
}
