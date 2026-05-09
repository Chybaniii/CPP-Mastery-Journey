
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

float GetFractionsPart(float Number)
{
	return Number - int(Number);
}

int MyRound(float Number)
{
	int IntPart;
	IntPart = int(Number);

	float FractionPart = GetFractionsPart(Number);

	if (abs(FractionPart) >= .5)
	{
		if (Number > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
		return IntPart;
}

float ReadNumber()
{
	float Num = 0;

	cout << "\nPLease enter a number?\n";
	cin >> Num;

	return Num;
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy Round Function: " << MyRound(Number) << endl;
	cout << "C++ Round Function:  " << round(Number) << endl;

}
