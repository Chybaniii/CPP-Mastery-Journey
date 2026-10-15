
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

stDate DecreaseDateByOneDay(stDate Date)
{

	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Year--;
			Date.Month = 12;
			Date.Day = NumberOfDaysInAMounth(Date.Month, Date.Year);
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInAMounth(Date.Month, Date.Year);
		}
	}
	else
	{
		Date.Day--;
	}

	return Date;
}

stDate DecraseDateByXDays(short Days, stDate Date)
{
	for (short i = 1; i <= Days; i++) {

		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{


	for (short i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{

	for (int i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	//Last check day in date should not exceed max days in the current month
	//example if date is 31/1/2022 Decreasing one month should  not be 31/2/2022, it should
	// be 28/2/2022
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMounth(Date.Month, Date.Year);

	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

stDate DecreaseDateByXMonth(short Month, stDate Date)
{

	for (int i = 1; i <= Month; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;
	return Date;
}

stDate DecreaseDateByXYear(short Years, stDate Date)
{


	for (int i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}


stDate DecreaseDateByXYearFasterWay(short Years, stDate Date)
{
	Date.Year -= Years;

	return Date;
}


stDate DecreaseDateByOneDecade(stDate Date)
{
	//Priod of -10 years
	Date.Year -= 10;
	return Date;
}


stDate DecreaseDateByXDecade(short Decade, stDate Date)
{

	for (int i = 1; i <= Decade * 10; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}

stDate DecreaseDateByXDecadeFaster(short Decade, stDate Date)
{
	Date.Year -= Decade * 10;

	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
	//Priod of 100 years
	Date.Year -= 100;
	return Date;
}

stDate DecreaseDateByOneMillinnium(stDate Date)
{
	Date.Year -= 1000;
	return Date;
}

int main()
{

	stDate Date = ReadFullDays();

	Date = DecreaseDateByOneDay(Date);

	cout << "\nDate After: \n";

	cout << "\n01 - Substracting one day is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecraseDateByXDays(10, Date);

	cout << "\n02 - Substracting 10 days is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneWeek(Date);


	cout << "\n03 - Substracting one week is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXWeeks(10, Date);


	cout << "\n04 - Substracting 10 weeks is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecreaseDateByOneMonth(Date);


	cout << "\n05 - Substracting one month is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXMonth(5, Date);


	cout << "\n06 - Substracting 5 month is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneYear(Date);


	cout << "\n07 - Substracting one year is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXYear(10, Date);

	cout << "\n08 - Substracting 10 years is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXYearFasterWay(10, Date);

	cout << "\n09 - Substracting 10 years (Faster) is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneDecade(Date);

	cout << "\n10 - Substracting One Decade is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXDecade(10, Date);

	cout << "\n11 - Substracting 10 Decades is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXDecadeFaster(10, Date);

	cout << "\n12 - Substracting 10 Decades (Faster) is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneCentury(Date);

	cout << "\n13 - Adding One century is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecreaseDateByOneMillinnium(Date);

	cout << "\n14 - Adding One Millennium is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;

}