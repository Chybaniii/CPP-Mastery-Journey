#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int random = rand() % (To - From + 1) + From;
	return random;
}

int ReadHowMnyNum(string message)
{
	int Num = 0;
	do
	{
		cout << message << endl;
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{

	cout << "\nEnter number of elements:\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
		arr[i] = RandomNumber(1, 100);

}

void PrintArr(int arr[100], int Num)
{

	for (int i = 0; i < Num; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n";
}



int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength;

	FillArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray Elements: ";
	PrintArr(arr, arrLength);

	


	return 0;
}