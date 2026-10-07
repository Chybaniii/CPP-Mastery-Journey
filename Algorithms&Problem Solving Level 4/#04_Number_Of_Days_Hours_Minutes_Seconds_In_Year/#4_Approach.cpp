#include <iostream>

using namespace std;

int ReadNumber()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;
	return number;
}

bool CheckIfLeapYear(int Number)
{
	return (Number % 4 == 0 && Number % 100 != 0 || (Number % 400 == 0));

}

short NumberOfDaysInAYear(short Year)
{
	return CheckIfLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInAYear(short Year)
{
	return NumberOfDaysInAYear(Year) * 24;
}

int NumberOfMinuitsInAYear(short Year)
{
	return NumberOfHoursInAYear(Year) * 60;
}

int NumberOfSecondsInAYear(short Year)
{
	return NumberOfMinuitsInAYear(Year) * 60;
}

int main()
{
	short Year = ReadNumber();
	cout << "\nNumber Of Days     in Year [" << Year << "] is "
		<< NumberOfDaysInAYear(Year);

	cout << "\nNumber Of Hours    in year [" << Year << "] is "
		<< NumberOfHoursInAYear(Year);


	cout << "\nNumber Of Minuits  in year [" << Year << "] is "
		<< NumberOfMinuitsInAYear(Year);


	cout << "\nNumber Of Seconds  in year [" << Year << "] is "
		<< NumberOfSecondsInAYear(Year);


	system("pause");
	return 0;

}