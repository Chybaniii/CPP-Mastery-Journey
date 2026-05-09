#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

float GetFractionsPart(float Number)
{
	return Number - int(Number);
}

int MyFloor(float Number)
{
	int IntPart;
	IntPart = int(Number);

	float FractionPart = GetFractionsPart(Number);


	if (Number > 0)
		return IntPart;
	else
		return --IntPart;


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

	cout << "\nMy Floor Function: " << MyFloor(Number) << endl;
	cout << "C++ floor Function:  " << floor(Number) << endl;

}
