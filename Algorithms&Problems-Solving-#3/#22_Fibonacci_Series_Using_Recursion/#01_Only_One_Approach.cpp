#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;



void PrintFibonacciUsingRecurssion(short Number, int Prev1, int Prev2)
{
	int FibNumber = 0;
	if (Number > 0)
	{
		FibNumber = Prev1 + Prev2;
		cout << FibNumber << "    ";
		Prev2 = Prev1;
		Prev1 = FibNumber;

		PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2 );
	}
		

}

int main()
{
	PrintFibonacciUsingRecurssion(10, 0, 1);

	system("pause>0");

	return 0;

}