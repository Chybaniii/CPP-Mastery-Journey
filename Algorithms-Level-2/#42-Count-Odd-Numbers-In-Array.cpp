#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int RandomNumbers(int From, int To)
{
	int random = 0;

	random = rand() % (To - From + 1) + From;

	return random;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "\nEnter how many numbers do you want?\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
		arr[i] = RandomNumbers(1, 100);


}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int CountOddNumberInArray(int arr[100], int arrLength)
{
	int Counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] % 2 != 0)
		{
			Counter++;
		}

	}

	return Counter;
}

int main()
{

	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0, arr2[100];

	FillArrayWithRandomNumbers(arr, arrLength);

	cout << "\nArray elements: ";
	PrintArray(arr, arrLength);



	cout << "\nOdd Numbers count is: ";
	cout << CountOddNumberInArray(arr, arrLength) << endl;

}
