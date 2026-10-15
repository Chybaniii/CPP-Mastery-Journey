
#pragma warning(disable : 4996)

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
	do
	{
		cout << "Please enter a day ";
		cin >> Day;

	} while (Day < 1 || Day > 31);

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

int GetDiffrenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;

	while (IsDate1BeforDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return (IncludeEndDay ? ++Days : Days);

}

stDate GetSystemDate()
{
	stDate Date;

	time_t t = time(0);   // get time now
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
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

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder];
}

short IsEndOfWeek(stDate Date)
{
	return (DayOfWeekOrder(Date) == 6 );
}
bool IsWeekEnd(stDate Date)
{
	// Weekends are sat and sun
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex == 0 || DayIndex == 6);
}

bool  IsbusinessDay(stDate Date)
{
	return (!IsWeekEnd(Date));
}

short DaysUntilTheEndOfWeek(stDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(stDate Date)
{
	stDate EndOfMonthDate;
	EndOfMonthDate.Day = NumberOfDaysInAMounth(Date.Month, Date.Year);
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Year = Date.Year;

	return GetDiffrenceInDays(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(stDate Date)
{
	stDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;

	return GetDiffrenceInDays(Date, EndOfYearDate, true);
}

int main()
{
	stDate Date = GetSystemDate();
	short DayOfweekOrder = DayOfWeekOrder(Date);

	cout << "\nToday is " << DayShortName(DayOfweekOrder) << ", ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	cout << "\n\nIs it End of Week?";
	if (IsEndOfWeek(Date))
	{
		cout << "\nYes it is a end of week\n";
	}
	else
	{
		cout << "\nNo NOT end of wekk\n";
	}

	cout << "\nIs it Weekend?\n";
	if (IsWeekEnd(Date))
	{
		cout << "Yes it is a week end\n";
	}
	else
	{
		cout << "No today is " << DayShortName(DayOfWeekOrder(Date)) << ", Not a weekend\n";
	}

	cout << "\nIs it businees Day?\n";
	if (IsbusinessDay(Date))
	{
		cout << "Yes it is a businees day.\n";
	}
	else
	{
		cout << "No it is NOT a businees day.\n";
	}


	cout << "\nDay until end of week is : "
		<< s(Date);

	cout << "\nDay until end of month : "
		<< DaysUntilTheEndOfMonth(Date);

	cout << "\nDay until end of year : "
		<< DaysUntilTheEndOfYear(Date);

	system("pause>0");
	return 0;
}