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

int ReadNumber(string message)
{
	short Number = 0;

	cout << message << endl;
	cin >> Number;

	return Number;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{

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

void SumOf2Array(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arrSum[i] = arr1[i] + arr2[i];
}

int main()
{
	srand((unsigned)time(NULL));

	int arr1[100], arr2[100], arrSum[100];
	int arrLength = ReadNumber("How many elements ?\n");

	FillArrayWithRandomNumber(arr1, arrLength);
	FillArrayWithRandomNumber(arr2, arrLength);

	SumOf2Array(arr1, arr2, arrSum, arrLength);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr1, arrLength);

	cout << "\nArray 2 elements:\n";
	PrintArray(arr2, arrLength);

	cout << "\nSum of array1 and array2 elements:\n";
	PrintArray(arrSum, arrLength);

	return 0;
}
