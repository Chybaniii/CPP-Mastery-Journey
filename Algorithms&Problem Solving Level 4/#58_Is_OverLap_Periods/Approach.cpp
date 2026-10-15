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

int main()
{
	cout << "\nEnter period one:\n";

	stPeriod Period1 = ReadPeriod();

	cout << "\nEnter period two:\n";
	stPeriod Period2 = ReadPeriod();


	if (IsOverLapPeriods(Period1, Period2))
		cout << "\nYes, is overlap.\n";
	else
		cout << "\nNo, is NOT overlap.\n";

	system("pause>0");
	return 0;

}

