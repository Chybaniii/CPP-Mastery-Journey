#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string message)
{
	int Number = 0;
	do
	{ 
	cout << message << endl;
	cin >> Number  ;
	} while (Number <= 0);
	return Number;
}

void ReadArray(int Arr[100], int &ArrLength)
{
	cout << "\nEnter number of elememts ?\n";
	cin >> ArrLength;

	cout << "\nEnter array element\n";
	for (int i = 0; i < ArrLength; i++)
	{
		cout << "Element[" << i + 1 << "] ";
		cin >> Arr[i];
	}
	cout << endl;
}

void PrintArray(int arry[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arry[i] << " ";
}
int TimesRepeted(int Number, int arr[100], int arrLength)
{
	int Count = 0;
	for (int i = 0; i <= arrLength - 1; i++)
	{
		if (Number == arr[i])
		{
			Count++;
		}
		
	}
	return Count;
}

int main()
{
	int arr[100], arrLength, NumberToCheck;

	ReadArray(arr, arrLength);

	NumberToCheck = ReadPositiveNumber("Enter the number you want to check:");

	cout << "\nOrginal array: ";
	PrintArray(arr, arrLength);

	cout << "\nNumber " << NumberToCheck;
	cout << " is repeted ";
	cout << TimesRepeted(NumberToCheck, arr, arrLength) << " Time(s)\n";
}
