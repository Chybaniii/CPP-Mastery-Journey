
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

void TheMiddleRows(int arr[3][3], int arrMid[3], short Rows, short Cols)
{
	for (short i = 0; i <= Rows- 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (i == 1)
				arrMid[j] = arr[i][j];
		}
	}

}

void TheMiddleCols(int arr[3][3], int arrMid[3], short Rows, short Cols)
{
	for (short i = 0; i <= Cols - 1; i++)
	{
		for (int j = 0; j < Rows; j++)
		{
			if (i == 1)
				arrMid[j] = arr[j][i];
		}
	}

}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf(" %0*d    ", 2, arr[i][j]);
		}
		cout << endl;
	}

}

void PrintTheMiddle(int arr2[3], short Rows)
{
	for (int i = 0; i < Rows; i++)
	{
		printf(" %0*d    ", 2, arr2[i]);
	}

}

int main()
{

	srand((unsigned)time(NULL));

	int arr[3][3], arrMidRows[3], arrMidCols[3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\nMatrix1:\n";
	PrintMatrix(arr, 3, 3);

	TheMiddleRows(arr, arrMidRows, 3, 3);
	cout << "\n Row Middel of the matrix is:\n";
	PrintTheMiddle(arrMidRows, 3);

	TheMiddleCols(arr, arrMidCols, 3, 3);
	cout << "\n\nCols Middel of the matrix is:\n"; 
	PrintTheMiddle(arrMidCols, 3);


	system("pause>0");

	return 0;

}
