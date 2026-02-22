#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct stTaskDuration
{
	int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

int ReadPositiveNumber(string message)
{
	int Number = 0;
	do
	{
		cout << message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

stTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
	stTaskDuration TaskDuration;
	const int NumOfDays = 24 * 60 * 60;
	const int NumOfHours = 60 * 60;
	const int NumOfMinutes = 60;

	int Remainder = 0;
	TaskDuration.NumberOfDays = TotalSeconds / NumOfDays;
	Remainder = TotalSeconds % NumOfDays;
	TaskDuration.NumberOfHours = Remainder / NumOfHours;
	Remainder %= NumOfHours;
	TaskDuration.NumberOfMinutes = Remainder / NumOfMinutes;
	Remainder %= NumOfMinutes;
	TaskDuration.NumberOfSeconds = Remainder;

	return TaskDuration;
}

void PrintTaskDuration(stTaskDuration Task)
{
	cout << Task.NumberOfDays << " : " << Task.NumberOfHours << " : " <<
		Task.NumberOfMinutes << " : " << Task.NumberOfSeconds;
}

int main()
{
	int Result = ReadPositiveNumber("Please enter total seconds ?");
	cout << "\n";

	PrintTaskDuration(SecondsToTaskDuration(Result));

	return 0;
}

