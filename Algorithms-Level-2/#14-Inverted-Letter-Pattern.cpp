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

void PrintInvertedLettersPattern(int Number)
{
	cout << "\n";

	for (int i = 65 + Number - 1; i >= 65; i--)
	{
		for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
		{
			cout << char(i);
		}
		cout << "\n";
	}
}

int main()
{
	PrintInvertedLettersPattern(ReadPositiveNumbers("Please enter a number?"));

	return 0;
}
