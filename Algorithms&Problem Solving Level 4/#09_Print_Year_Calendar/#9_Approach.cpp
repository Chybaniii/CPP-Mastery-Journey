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

string MonthShortNaame(short Month)
{
	string arrMonths[12] = { "Jan", "Feb", "Mar",
							"Apr", "May", "Jun",
							"Jul", "Aug", "Sep",
							"Oct", "Nov", "Dec"

	};

	return (arrMonths[Month - 1]);
}

void PrintMonthCalendar(short Month, short Year)
{
	int NumberOfDays;

	// Index of the day from 0 to 6
	int current = DayOfWeekOrder(Year, Month, 1);

	NumberOfDays = NumberOfDaysInAMounth(Month, Year);

	//Print the current month name.
	printf("\n  ______________%s________________\n\n",
		MonthShortNaame(Month).c_str());

	//Print the columns
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// print appropriate spaces
	int i;
	for (i = 0; i < current; i++)
		printf("     ");

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);


		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}

	printf("\n  ________________________________\n");

}

void PrintYearCalendar(short Year)
{
	printf("\n  __________________________________\n\n");
	printf("            Calendar - %d\n", Year);
	printf("  __________________________________\n");



	for (short Month = 1; Month <= 12; Month++)
	{
		PrintMonthCalendar(Month, Year);
	}
}

int main()
{
	short Year = ReadYear();

	PrintYearCalendar(Year);

	system("pause>0");
	return 0;
}