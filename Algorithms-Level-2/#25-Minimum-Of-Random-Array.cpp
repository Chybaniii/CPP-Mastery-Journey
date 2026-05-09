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

int MinNumberInArray(int arr[100], int arrLength)
{
	int Min = 0;
	Min = arr[0];
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] < Min)
		{
			Min = arr[i];
		}
	}

	return Min;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength;

	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray Elements : ";
	PrintArray(arr, arrLength);

	cout << "Minimum Array is : ";
	cout << MinNumberInArray(arr, arrLength) << endl;
}
