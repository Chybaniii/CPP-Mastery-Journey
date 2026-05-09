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

void CopyArray(int arrSource[100], int arrDestinition[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arrDestinition[i] = arrSource[i];
	
}


int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength;

	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray Elements : ";
	PrintArray(arr, arrLength);

	int arr2[100];
	CopyArray(arr, arr2, arrLength);
	
	cout << "\nArray 1 elements:\n ";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 elements:\n ";
	PrintArray(arr2, arrLength);

	
}
