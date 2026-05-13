#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	int random = 0;
	random = rand() % (To - From + 1) + From;
	return random;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
			arr[i][j] = RandomNumber(1, 100);
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << endl;
	}

}


int ColSum(int arr[3][3], short Rows, short ColsNumber)
{
	int Sum = 0;
	for (short i = 0; i <= Rows - 1; i++)
	{
		Sum += arr[i][ColsNumber];
	}
	return Sum;
}

void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
	for (short ColsNumber = 0; ColsNumber < Cols; ColsNumber++)
	{
		arrSum[ColsNumber] = ColSum(arr, Rows, ColsNumber);
	}
}

void PrintEachColsSumArray(int arrSum[3], short Length)
{
	cout << "\nThe following are the sum of each Column in the matrix:\n";

	for (short j = 0; j < Length; j++)
	{
		cout << "Cols " << j + 1 << " Sum = " << arrSum[j] << endl;
	}

}


int main()
{
	//Seeds the random number generator in C++, called only once.
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrSum[3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\n The following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	SumMatrixColsInArray(arr, arrSum, 3, 3);

	PrintEachColsSumArray(arrSum, 3);
	system("pause>0");

	return 0;

}
