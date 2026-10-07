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

stDate increaseDateByXDays(short Days,stDate Date)
{
	for (short i = 1; i <= Days; i++) {

		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	

	for (short i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

stDate IncreaseDateByXWeeks(short Weeks, stDate Date)
{

	for (int i = 1; i <= Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	//Last check day in date should not exceed max days in the current month
	//example if date is 31/1/2022 increasing one month should  not be 31/2/2022, it should
	// be 28/2/2022
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMounth(Date.Month, Date.Day);

	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

stDate IncreaseDateByXMonth(short Month, stDate Date)
{
	
	for (int i = 1; i <= Month; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}

stDate IncreaseDateByXYear(short Years, stDate Date)
{
	

	for (int i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	} 
	
	return Date;
}


stDate IncreaseDateByXYearFasterWay(short Years, stDate Date)
{
	Date.Year += Years;

	return Date;
}


stDate IncreaseDateByOneDecade(stDate Date)
{
	//Priod of 10 years
	Date.Year += 10;
	return Date;
}


stDate IncreaseDateByXDecade(short Decade ,stDate Date)
{

	for (int i = 1; i <= Decade * 10; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreaseDateByXDecadeFaster(short Decade, stDate Date)
{
	Date.Year += Decade * 10;

	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	//Priod of 100 years
	Date.Year += 100;
	return Date;
}

stDate IncreaseDateByOneMillinnium(stDate Date)
{
    //priod of 1000 years
	Date.Year += 1000;
	return Date;
}

int main()
{

	stDate Date = ReadFullDays();

	Date = IncreaseDateByOneDay(Date);

	cout << "\nDate After: \n"; 

	cout << "\n01 - Adding one day is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


	 Date = increaseDateByXDays(10, Date);

	cout << "\n02 - Adding 10 days is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneWeek(Date);


	cout << "\n03 - Aadding one week is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

     Date = IncreaseDateByXWeeks(10, Date);


	cout << "\n04 - Adding 10 weeks is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


	 Date = IncreaseDateByOneMonth(Date);


	cout << "\n05 - Adding one month is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	 Date = IncreaseDateByXMonth(5, Date);


	cout << "\n06 - Adding 5 month is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	 Date = IncreaseDateByOneYear(Date);


	cout << "\n07 - Adding one year is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	 Date = IncreaseDateByXYear(10, Date);

	cout << "\n08 - Adding 10 years is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	 Date = IncreaseDateByXYearFasterWay(10, Date);

	cout << "\n09 - Adding 10 years (Faster) is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	 Date = IncreaseDateByOneDecade(Date);

	cout << "\n10 - Adding One Decade is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	 Date = IncreaseDateByXDecade(10, Date);

	cout << "\n11 - Adding 10 Decades is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	 Date = IncreaseDateByXDecadeFaster(10, Date);

	cout << "\n12 - Adding 10 Decades (Faster) is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
	
	 Date = IncreaseDateByOneCentury(Date);

	cout << "\n13 - Adding One century is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


	 Date = IncreaseDateByOneMillinnium(Date);

	cout << "\n14 - Adding One Millennium is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;



}