
#include <iostream>

using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "Please enter a year? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	short Month;
	do
	{
		cout << "Please enter a month? ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

short ReadDay()
{
	short Day = 0;

	cout << "Please enter a day? ";
	cin >> Day;

	return Day;
}

struct stDate {
	int Year;
	int Month;
	int Day;

};

stDate ReadFullDays()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}


bool CheckIfLeapYear(int Number)
{
	return (Number % 4 == 0 && Number % 100 != 0 || (Number % 400 == 0));

}

short NumberOfDaysInAMounth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (Month == 2) ? (CheckIfLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}


bool IslastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMounth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

int main()
{

	stDate Date = ReadFullDays();

	if (IslastDayInMonth(Date))
		cout << "\nYes, is last day in the month.\n";
	else
		cout << "\nNo, is NOT last day in the month.\n";



	if (IsLastMonthInYear(Date.Month))
		cout << "\Yes, is last month in the year.\n";
	else 
		cout << "No, is NOT last month in the year.\n";

	

	system("pause>0");
	return 0;

}