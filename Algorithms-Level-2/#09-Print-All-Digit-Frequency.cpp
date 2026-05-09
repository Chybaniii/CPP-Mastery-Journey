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
	int Number2 = Number;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;

		if (Frequncy == Remainder)
			freqCount++;

	}

	return freqCount;
}

void PrintDigitsFrequency(int Number)
{
	cout << endl;
	for (int i = 1; i < 10; i++)
	{
		short DigitFrequency;
	     DigitFrequency = CountFrequncyNumber(Number, i);

		 if (DigitFrequency > 0)
		 {
			 cout << "Digit " << i << " Frequency is "
				 << DigitFrequency << " Time(s).\n";
		 }
	}
}

int main()
{
	int Number = ReadPositiveNumbers("Please enter the main number ?");
	PrintDigitsFrequency(Number);

	return 0;

}
