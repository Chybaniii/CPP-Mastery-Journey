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

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
	cout << "\nPlease enter number of elements ?\n";
	cin >> arrLength;
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
int ReadPositiveNumber(string message)
{
	int Number = 0;
	do {


		cout << message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
	//This fnction will search for a number in arrayand return its index,
	//or return -1 if it does not exists

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
			return i;  //This will break the function and return the index.
	}

	//if you reached here, this means the number is not found.

	return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
	return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

int main()
{

	srand((unsigned)time(NULL));

	int arr[100], arrLength;

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);

	int Num = ReadPositiveNumber("Please enter number to search for ?");

	cout << "\nNumber you are loking for is: " << Num << endl;

	
		if (!IsNumberInArray(Num, arr, arrLength))
			cout << "No, The Number not found :-(\n";
		else
		{
			cout << "Yes it is found :-)\n";
		}

	return 0;
}

