
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

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}

bool IslastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMounth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IslastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}

	else
	{
		Date.Day++;
	}

	return Date;
}

void SwapDates(stDate& Date1, stDate& Date2)
{
	stDate SwapDates;

	SwapDates.Year = Date1.Year;
	SwapDates.Month = Date1.Month;
	SwapDates.Day = Date1.Day;

	Date1.Year = Date2.Year;
	Date1.Month = Date2.Month;
	Date1.Day = Date2.Day;

	Date2.Year = SwapDates.Year;
	Date2.Month = SwapDates.Month;
	Date2.Day = SwapDates.Day;
}

int GetDiffrenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	short SwapVlagValue = 1;

	if (!IsDate1BeforDate2(Date1, Date2))
	{
		SwapDates(Date1, Date2);
		SwapVlagValue = -1;
	}

	while (IsDate1BeforDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return (IncludeEndDay ? ++Days * SwapVlagValue : Days * SwapVlagValue);

}
int main()
{

	stDate Date1 = ReadFullDays();
	cout << "\n";
	stDate Date2 = ReadFullDays();



	cout << "\nDiffrence is: ";
	cout << GetDiffrenceInDays(Date1, Date2) << " Day(s). ";


	cout << "\nDiffrence (inclding End day) is: ";
	cout << GetDiffrenceInDays(Date1, Date2, true) << " Day(s). ";


	system("pause>0");
	return 0;
}