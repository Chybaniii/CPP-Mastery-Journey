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

void PrintLetterPattern(int Number)
{
	cout << "\n";

	for (int i = 65; i <= Number + 65 - 1; i++)
	{
		for (int j = 1; j <= i - 65 + 1; j++)
		{
			cout << char(i);
		}
		cout << "\n";
	}
}

int main()
{
	PrintLetterPattern(ReadPositiveNumbers("Please enter a number?"));

	return 0;
}
