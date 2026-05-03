#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

float ReadNumber()
{
	float Number = 0;

	cout << "\nPlease enter a number?\n";
	cin >> Number;

	return Number;
}

int MySqrt(float Number)
{
	return pow(Number, 0.5);
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy Sqrt function: " << MySqrt(Number) << endl;
	cout << "C++ sqrt function: " << sqrt(Number) << endl;
}

