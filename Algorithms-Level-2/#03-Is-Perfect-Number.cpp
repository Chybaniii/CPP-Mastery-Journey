#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float ReadPositiveNumber(string message)
{
	int Num = 0;
	do
	{
		cout << message << endl;
		cin >> Num;
	} while (Num < 0);

	return Num;
}


int IsPerfectNumber(int Number)
{
	int Sum = 0;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
		{
			Sum += i;
		}
	}

	return Number == Sum;

}

void PrintPerfectNumber(int Number)
{

	if (IsPerfectNumber(Number))
	{
		cout << endl << Number << " Is perfect " << endl;
	}
	else
		cout << Number << " Is not perfect\n";
}


int main()
{
	PrintPerfectNumber(ReadPositiveNumber("Please enter a positive number"));

	return 0;
}
