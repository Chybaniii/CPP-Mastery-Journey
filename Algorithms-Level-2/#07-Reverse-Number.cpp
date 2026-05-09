#include <string>
#include <iostream>
using namespace std;

int ReadPositiveNumbers(string message)
{
	int Number = 0;

	do
	{
		cout << message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}
int ReverseNumber(int Number)
{
	int Number2 = 0, Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + Remainder;
	}

	return Number2;
}

int main()
{
	int Number = ReadPositiveNumbers("Please enter a positive number ?");
	cout << "\n";

	cout << "Revers Digits Order = ";
	cout << ReverseNumber(Number) << endl;

	return 0;

}
