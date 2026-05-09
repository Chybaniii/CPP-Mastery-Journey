#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int RandomNumber(int From, int To)
{
	int random = 0;
	random = rand() % (To - From + 1) + From;

	return random;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "\nEnter how many numbers do you need?\n";
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
void AddArrayElements(int Number, int arr[100], int& arrLength)
{
	//Its a new element so we need to add the length by 1.
	arrLength++;
	arr[arrLength - 1] = Number;
}

void CopyOddNumbersArrayUsingAddArrayElements(int arrSource[100], int arrDestinition[100], int arrLength, int& arrDestinitionLength)
{
	for (int i = 0; i < arrLength; i++)
		if (arrSource[i] % 2 != 0)
			AddArrayElements(arrSource[i], arrDestinition, arrDestinitionLength);

}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0, arr2Length = 0;

	FillArrayWithRandomNumbers(arr, arrLength);

	int arr2[100];
	CopyOddNumbersArrayUsingAddArrayElements(arr, arr2, arrLength, arr2Length);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 elements after copy:\n";
	PrintArray(arr2, arr2Length);



	return 0;
}


