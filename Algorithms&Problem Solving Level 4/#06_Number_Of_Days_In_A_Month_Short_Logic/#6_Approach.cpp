
#include <iostream>

using namespace std;

int ReadNumber()
{
	int number;
	cout << "Enter a number: ";
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

short NumberOfDaysInAMounth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (Month == 2) ? (CheckIfLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

int main()
{
	short Year = ReadNumber();
	short Mounth = ReadMounth();

	cout << "\nNumber Of Days     in Mounth [" << Mounth << "] is "
		<< NumberOfDaysInAMounth(Mounth, Year);

	cout << "\n";
	system("pause");
	return 0;

}