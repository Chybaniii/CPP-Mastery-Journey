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
int CountFrequncyNumber(int Number, short Frequncy)
{
	int Remainder = 0, freqCount = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;

		if (Frequncy == Remainder)
			freqCount++;
	}

	return freqCount;
}

int main()
{
	int Number = ReadPositiveNumbers("Please enter the main number ?");
	int DigitToCheck = ReadPositiveNumbers("Please enter one digit to check?");


	cout << "\nDigit " << DigitToCheck << " Frequncy is "
		<< CountFrequncyNumber(Number, DigitToCheck) << " Time(s).\n";

	return 0;

}
