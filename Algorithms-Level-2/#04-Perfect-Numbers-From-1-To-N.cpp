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

	for (int i = 1; i < Number; i++)
	{
		if (IsPerfectNumber(i))
		{
			cout << i << endl;
		}
	}

}


int main()
{
	PrintPerfectNumber(ReadPositiveNumber("Please enter a positive number"));

	return 0;
}
