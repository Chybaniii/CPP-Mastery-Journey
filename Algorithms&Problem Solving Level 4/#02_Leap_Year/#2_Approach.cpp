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
	if (Number % 400 == 0)
		return true;
	if (Number % 4 == 0 && Number % 100 != 0)
		return true;
	else
		return false;
}

void PrintLeapYearOrNot(int Number)
{
	if (CheckIfLeapYear(Number))
		cout << "\nYes " << Number << " is leap year.\n\n";
	else
		cout << "\nNo " << Number << " is not leap year.\n\n";
}

int main()
{
	int Number = ReadNumber();

	PrintLeapYearOrNot(Number);

	system("pause");
}

