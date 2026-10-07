#include <iostream>

using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "\nPlease enter a year? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	short Month;
	do
	{
		cout << "\nPlease enter a month? ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

short ReadDay()
{
	short Day = 0;
	do
	{
		cout << "\nPlease enter a day ";
		cin >> Day;

	} while (Day < 1 || Day > 31);

	return Day;
}

short DayOfWeekOrder(short Year, short Month, short Day)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	//Gregorian:
	//0:Sun, 1:Mon: 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder]; 
}

void PrintDate(short Year, short Month, short Day)
{
	cout << "\nDate       : " << Day << "/" << Month << "/" << Year << endl;
	cout << "Day Order  : " << DayOfWeekOrder(Year, Month, Day) << endl;
	cout << "Day Name   : " << DayShortName(DayOfWeekOrder(Year, Month, Day)) << "\n";
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	PrintDate(Year, Month, Day);

	system("pause>0");
	return 0;
}