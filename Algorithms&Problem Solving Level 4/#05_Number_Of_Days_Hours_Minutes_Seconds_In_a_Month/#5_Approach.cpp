#include <iostream>

using namespace std;

int ReadYear()
{
	int number;
	cout << "Enter a year: ";
	cin >> number;
	return number;
}

int ReadMounth()
{
	int number;
	cout << "Enter a Mounth: ";
	cin >> number;
	return number;
}

bool CheckIfLeapYear(int Number)
{
	return (Number % 4 == 0 && Number % 100 != 0 || (Number % 400 == 0));

}

short NumberOfDaysInAMounth(short Mounth, short Year)
{
	if (Mounth < 1 || Mounth > 12)
		return 0;

	if (Mounth == 2)
	{
		return CheckIfLeapYear(Year) ? 29 : 28;
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

short NumberOfHoursInAMounth(short Mounth, short Year)
{
	return NumberOfDaysInAMounth(Mounth, Year) * 24;
}

int NumberOfMinuitsInAMounth(short Mounth, short Year)
{
	return NumberOfHoursInAMounth(Mounth, Year) * 60;
}

int NumberOfSecondsInAMounth(short Mounth, short Year)
{
	return NumberOfMinuitsInAMounth(Mounth, Year) * 60;
}

int main()
{
	short Year = ReadYear();
	short Mounth = ReadMounth();

	cout << "\nNumber Of Days     in Mounth [" << Mounth << "] is "
		<< NumberOfDaysInAMounth(Mounth, Year);

	cout << "\nNumber Of Hours    in Mounth [" << Mounth << "] is "
		<< NumberOfHoursInAMounth(Mounth, Year);


	cout << "\nNumber Of Minuits  in Mounth [" << Mounth << "] is "
		<< NumberOfMinuitsInAMounth(Mounth, Year);


	cout << "\nNumber Of Seconds  in Mounth [" << Mounth << "] is "
		<< NumberOfSecondsInAMounth(Mounth, Year);


	system("pause");
	return 0;

}
