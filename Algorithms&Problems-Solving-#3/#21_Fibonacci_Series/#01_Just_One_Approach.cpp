#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;



void PrintFibonacciUsingLoop(int Length)
{
	int FibNumber = 0;
	int Prev1 = 1, Prev2 = 0;
	cout << "1    ";

	for (short i = 1; i < Length; i++) {

		FibNumber = Prev1 + Prev2;
		cout << FibNumber << "    ";
		Prev2 = Prev1;
		Prev1 = FibNumber;

	}

	
}

int main()
{
	PrintFibonacciUsingLoop(10);

	system("pause>0");

	return 0;

}