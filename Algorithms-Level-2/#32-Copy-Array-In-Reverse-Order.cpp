#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int random = 0;
	random = rand() % (To - From + 1) + From;

	return random;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
	cout << "\nEnter number of elements:\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
		arr[i] = RandomNumber(1, 100);
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}


void CopyArrayInReverseOrder(int arrSource[100], int arrLength, int arrDestinition[100])
{

	for (int i = 0; i < arrLength; i++)
	{
		arrDestinition[i] = arrSource[arrLength - 1 - i];
	}

}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength;

	FillArrayWithRandomNumber(arr, arrLength);

	int arr2[100];
	CopyArrayInReverseOrder(arr, arrLength, arr2);


	cout << "\nArray 1 elements:\n";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 elements after Copying array 1 in reversed order:\n";
	PrintArray(arr2, arrLength);


	return 0;
}
