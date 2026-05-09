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

int ReadNumber()
{
	int Num = 0;
	do
	{
		cout << "\nEnter a number?\n";
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

void FillArray(int arr[100], int& arrLength)
{
	arrLength = 10;
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 70;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;

}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
	//This fnction will search for a number in arrayand return its index,
//	or return -1 if it does not exists. 

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

void AddArrayElements(int Number, int arr[100], int& arrLength)
{
	//Its a new element so we need to add the length by 1.
	arrLength++;
	arr[arrLength - 1] = Number;
}

void CopyDistinctNumbersInArray(int arrSource[100], int arrDestinition[100], int arrSourceLength, int& arrDestinitionLength)
{
	for (int i = 0; i < arrSourceLength; i++)
	{
		if (!IsNumberInArray(arrSource[i], arrDestinition, arrDestinitionLength))
		{
			AddArrayElements(arrSource[i], arrDestinition, arrDestinitionLength);
		}
	}


}

int main()
{
	int arrSource[100], SourceLength = 0, arrDestination[100], DestinationLength = 0;

	FillArray(arrSource, SourceLength);

	cout << "\nArray 1 elements: \n";
	PrintArray(arrSource, SourceLength);

	CopyDistinctNumbersInArray(arrSource, arrDestination, SourceLength, DestinationLength);

	cout << "\nArray 2 distinct elements: \n";
	PrintArray(arrDestination, DestinationLength);


	return 0;
}
