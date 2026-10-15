
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

stDate ReadFullDate()
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

int CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
	short DaysCount = 0;

	while (IsDate1BeforDate2(DateFrom, DateTo))
	{

		if (IsbusinessDay(DateFrom))
		{
			DaysCount++;
		}

		DateFrom = IncreaseDateByOneDay(DateFrom);

	}

	return DaysCount;;
}

int main()
{
	cout << "\nVacation Starts: \n";
	stDate DateFrom = ReadFullDate();

	cout << "\nVacation End: \n";
	stDate DateTo = ReadFullDate();



	cout << "\nVacation From " << DayShortName(DayOfWeekOrder(DateFrom)) << ", ";
	cout << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year;

	cout << "\nVacation To " << DayShortName(DayOfWeekOrder(DateTo)) << ", ";
	cout << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year;

	cout << "\n\nActual Vacation Days is: " << CalculateVacationDays(DateFrom, DateTo);

	system("pause>0");
	return 0;
}