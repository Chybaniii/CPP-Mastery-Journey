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

void InputUserNumbersInArray(int arr[100], int& arrLength)
{
	bool AddMore = true;

	do
	{
		AddArrayElements(ReadNumber(), arr, arrLength);

		cout << "\nDo you want to add more numbers? [0]:No, [1]:Yes? ";
		cin >> AddMore;

	} while (AddMore);
}

int main()
{

	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0;
	InputUserNumbersInArray(arr, arrLength);

	cout << "\nArray Length: " << arrLength << endl;
	cout << "Array elements: ";
	PrintArray(arr, arrLength);

}
