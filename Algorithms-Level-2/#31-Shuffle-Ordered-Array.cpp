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

void FillArrayWith1ToN(int arr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
		arr[i] = i + 1;
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void Swap(int& A, int& B)
{
	int Temp = 0;

	Temp = A;
	A = B;
	B = Temp;
}

void ShuffleArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);

}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100];
	int arrLength = ReadNumber("How many elements ?\n");

	FillArrayWith1ToN(arr, arrLength);

	cout << "\nArray elemetns befor shuffle:\n";
	PrintArray(arr, arrLength);

	ShuffleArray(arr, arrLength);

	cout << "\nArray elements after shuffle\n";
	PrintArray(arr, arrLength);

	return 0;
}
