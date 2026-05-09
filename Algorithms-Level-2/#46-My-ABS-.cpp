#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

float MyABS(float Number)
{
	if (Number > 0)
		return Number;
	else
		return Number * -1;
}

float ReadNumber()
{
	float Num = 0;
	cout << "\nPlease enter a number?\n";
	cin >> Num;

	return Num;
}

int main()
{
	float Number = ReadNumber();
	cout << "My abs Result : " << MyABS(Number) << endl;
	cout << "C++ abs Result: " << abs(Number) << endl;
}
