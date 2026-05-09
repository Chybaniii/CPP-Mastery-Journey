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

int MyCeil(float Number)
{
	if (Number > 0)
		return int(Number) + 1;
	else
		return int(Number);
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy Ciel Function: " << MyCeil(Number) << endl;
	cout << "C++ Ciel Function: " << ceil(Number) << endl;


	return 0;
}
