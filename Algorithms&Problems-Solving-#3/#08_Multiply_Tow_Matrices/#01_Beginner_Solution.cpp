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
			arr[i][j] = RandomNumber(1, 10);
			
	}
}

void FillMatrix_2_WithRandomNumbers(int arr2[3][3], short Rows, short Cols)
{
	short Counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j <= Cols - 1; j++)
			arr2[i][j] = RandomNumber(1, 10);
			
	}
}

void Multiplay_2_Matrices(int arr[3][3], int arr2[3][3], int arrMulti[3][3], short RowsNumber, short Cols)
{
	
	for (int i = 0; i <= RowsNumber- 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arrMulti[i][j] = arr[i][j] * arr2[i][j];
		}
	}
}

void PrintMultiplyMatrices(int arrMulti[3][3], short Length)
{
	for (int i = 0; i <= Length - 1; i++)
	{
		for (int j = 0; j < Length; j++)
		{
			cout << setw(2) << setfill('0') << arrMulti[i][j] << "     ";
		}
		cout << endl;
	}
	
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(2) << setfill('0') <<  arr[i][j] << "     ";
		}
		cout << endl;
	}

}

int main()
{

	srand((unsigned)time(NULL));

	int arr[3][3], arr2[3][3], arrMulti[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(arr, 3, 3);

	FillMatrix_2_WithRandomNumbers(arr2, 3, 3);
	cout << "\n\nMatrix2:\n";
	PrintMatrix(arr2, 3, 3);

	Multiplay_2_Matrices(arr, arr2, arrMulti, 3, 3);
	cout << "\n\nResults:\n";
	PrintMultiplyMatrices(arrMulti, 3);

	system("pause>0");

	return 0;

}
