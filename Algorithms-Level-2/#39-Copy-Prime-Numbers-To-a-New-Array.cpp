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

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
			return enPrimeNotPrime::NotPrime;
	}

	return enPrimeNotPrime::Prime;
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

void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestinition[100], int arrLength, int& arrDestinitionLength)
{
	for (int i = 0; i < arrLength; i++)
		if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
			AddArrayElements(arrSource[i], arrDestinition, arrDestinitionLength);
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0, arr2Length = 0;

	FillArrayWithRandomNumbers(arr, arrLength);

	int arr2[100];
	CopyOnlyPrimeNumbers(arr, arr2, arrLength, arr2Length);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 elements Prime number:\n";
	PrintArray(arr2, arr2Length);



	return 0;
}
