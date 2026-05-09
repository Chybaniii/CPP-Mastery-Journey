#include <iostream>
#include <string>
#include <cmath>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

float ReadPositiveNumber(string message)
{
	int Num = 0;
	do
	{
		cout << message << endl;
		cin >> Num;
	} while (Num < 0);

	return (float)Num;
}



enPrimeNotPrime CheckPrime(int Number)
{

	float M = round(Number / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
			return enPrimeNotPrime::NotPrime;

	}

	return enPrimeNotPrime::Prime;
}

void PrintPrimeNumberFrom1ToN(int Number)
{
	cout << "\n";
	cout << "Prime Number From " << 1 << " To " << Number;
	cout << " are : " << endl;

	for (int i = 1; i <= Number; i++)
	{
		if (CheckPrime(i) == enPrimeNotPrime::Prime)
		{
			cout << i << endl;
		}
	}
}


int main()
{
	int Num = ReadPositiveNumber("Please enter a positive number ?");

	PrintPrimeNumberFrom1ToN(Num);
    
    return 0;
}
