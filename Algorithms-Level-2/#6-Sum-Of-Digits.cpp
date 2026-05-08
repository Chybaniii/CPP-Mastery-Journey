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
int SumOfDigits(int Number)
{
	int Sum = 0;

	while (Number > 0)
	{
		Sum += Number % 10;
		Number = Number / 10;
	}

	return Sum;
}

int main()
{
	int Number = ReadPositiveNumbers("Please enter a positive number ?");
	cout << "\n";

	cout << "Sum of digits = ";
	cout << SumOfDigits(Number) << endl;

	return 0;

}