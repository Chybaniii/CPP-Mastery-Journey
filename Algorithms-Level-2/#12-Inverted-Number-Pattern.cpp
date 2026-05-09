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

void PrintInvertedNumberPattern(int Number)
{
	cout << "\n";

	for (int i = Number; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << "\n";
	}
}

int main()
{
	PrintInvertedNumberPattern(ReadPositiveNumbers("Please enter a number?"));

	return 0;
}
