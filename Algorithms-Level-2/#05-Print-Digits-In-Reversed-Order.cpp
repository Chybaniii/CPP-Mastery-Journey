#include <string>
#include <iostream>
using namespace std;

int ReadPositiveNumber(string message)
{
	int Num = 0;
	do
	{
		cout << message << endl;
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

void PrintReverseDigits(int Num)
{
	while (Num > 0)
	{
		cout << Num % 10 << endl;
		Num /= 10;
	}
}
int main()
{
	PrintReverseDigits(ReadPositiveNumber("Please enter a Number ?"));

	return 0;
}
