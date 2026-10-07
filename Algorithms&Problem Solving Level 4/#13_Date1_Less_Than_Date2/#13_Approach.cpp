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

	cout << "\nPlease enter a day? ";
	cin >> Day;

	return Day;
}


bool IsLeapYear(int Number)
{
	return (Number % 4 == 0 && Number % 100 != 0 || (Number % 400 == 0));

}

short NumberOfDaysInAMounth(short Mounth, short Year)
{
	if (Mounth < 1 || Mounth > 12)
		return 0;

	if (Mounth == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	short arr31Days[7] = { 1,3,5,7,8,10,12 };
	for (short i = 1; i <= 7; i++)
	{
		if (arr31Days[i - 1] == Mounth)
			return 31;
	}

	//if you reach here then it's 30 days.
	return 30;

}

int DaysFromTheBeginningOfYear(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (short i = 1; i < Month; i++)
	{
		TotalDays += NumberOfDaysInAMounth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
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

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	
}

int main()
{

	stDate Date1 = ReadFullDays();
	stDate Date2 = ReadFullDays();

	if (IsDate1BeforDate2(Date1, Date2))
		cout << "\n\nYes, Date1 is lesst than Date2.";
	else
		cout << "\n\nNo, Date1 is'nt Less than Date2.";
	

	system("pause>0");
	return 0;



}