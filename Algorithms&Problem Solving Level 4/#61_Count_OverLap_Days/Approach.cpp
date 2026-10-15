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

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
};

stDate ReadFullDays()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

stPeriod ReadPeriod()
{
	stPeriod Period;

	cout << "\nEnter Start Date: \n";
	Period.StartDate = ReadFullDays();

	cout << "\nEnter End Date: \n";
	Period.EndDate = ReadFullDays();

	return Period;
}

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}


bool IsDate1EqualsDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;


}


bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforDate2(Date1, Date2) && !IsDate1EqualsDate2(Date1, Date2));
}


enum enCompareDates { Befor = -1, After = 1, Equal = 0 };

enCompareDates ComparDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforDate2(Date1, Date2))
		return enCompareDates::Befor;

	if (IsDate1AfterDate2(Date1, Date2))
		return enCompareDates::After;

	return enCompareDates::Equal;
}

bool IsDateInPeriod(stDate Date, stPeriod Period)
{

	return	!(ComparDates(Date, Period.StartDate) == enCompareDates::Befor
		||
		ComparDates(Date, Period.EndDate) == enCompareDates::After);

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

	return Days;
}


bool IsOverLapPeriods(stPeriod Period1, stPeriod Period2)
{
	if (
		ComparDates(Period2.EndDate, Period1.StartDate) == enCompareDates::Befor
		||
		ComparDates(Period2.StartDate, Period1.EndDate) == enCompareDates::After
		)
		return false;
	else
		return true;

}


int PeriodLengthInDays(stPeriod Period, bool IncludEndDay = false)
{
	return GetDiffrenceInDays(Period.StartDate, Period.EndDate, IncludEndDay);
}

int OverLapDays(stPeriod Period1, stPeriod Period2)
{
	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);
	int OverLapDays = 0;

	if (!IsOverLapPeriods(Period1, Period2))
		return 0;

	if (Period1Length < Period2Length)
	{
		while (IsDate1BeforDate2(Period1.StartDate,Period1.EndDate))
		{
			if (IsDateInPeriod(Period1.StartDate, Period2))
			OverLapDays++;

			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}
	}

	else
	{
		while (IsDate1BeforDate2(Period2.StartDate, Period2.EndDate))
		{
			if (IsDateInPeriod(Period2.StartDate, Period1))
			OverLapDays++;

			Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
		}
	}

	return OverLapDays;
}


int main()
{
	cout << "\nEnter Period 1:\n";

	stPeriod Period1 = ReadPeriod();

	cout << "\nEnter Period 2:\n\n";
	stPeriod Period2 = ReadPeriod();
	
	cout << "\nOver Lap Days is : " << OverLapDays(Period1, Period2);
	system("pause>0");
}