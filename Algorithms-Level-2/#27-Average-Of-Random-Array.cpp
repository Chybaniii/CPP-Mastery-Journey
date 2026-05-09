#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)

{
	int random = rand() % (To - From + 1) + From;

	return random;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
	cout << "\nEnter number of elements ?\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
		arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrlength)
{
	for (int i = 0; i < arrlength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int SumOfArray(int arr[100], int arrLength)
{
	float Sum = 0;

	for (int i = 0; i < arrLength; i++)
	{
		Sum += arr[i];
	}

	return Sum ;
}

float ArrayAverage(int arr[100], int arrLength)
{
	return (float)SumOfArray(arr, arrLength) / arrLength;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength;

	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray Elements : ";
	PrintArray(arr, arrLength);

	cout << "\nSum Of all numbers is : ";
	cout << SumOfArray(arr, arrLength) << endl;

	cout << "\nAverage Of numbers is : ";
	cout << ArrayAverage(arr, arrLength) << endl;
}
