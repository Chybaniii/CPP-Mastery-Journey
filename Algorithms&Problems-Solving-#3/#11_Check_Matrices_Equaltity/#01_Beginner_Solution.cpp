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

int SumMatrix(int arr[3][3], short Rows, short Cols)
{
	int SumAllMatrix = 0;
	for (short i = 0; i <= Rows - 1; i++)
	{
		for (short j = 0; j < Cols; j++)
			SumAllMatrix += arr[i][j];
	}

	return SumAllMatrix;
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

bool CompareTheTwoSumOfMatrices(int SumMatrix1[3][3], int SumMatrix2[3][3], short Rows, short Col)
{
	return SumMatrix(SumMatrix1, Rows, Col) == SumMatrix(SumMatrix2, Rows, Col);
}

void PrintTheCompareResults(int Sum1[3][3], int Sum2[3][3], short Rows, short Col)
{
	if (!CompareTheTwoSumOfMatrices(Sum1, Sum2, Rows, Col))
	{
		cout << "\n\nNo: matrices are not equal.\n";
	}
	else
	{
		cout << "\nYes: both matrices are equal.\n";
	}

	
}

int main()
{

	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	PrintTheCompareResults(Matrix1, Matrix2, 3, 3);

	system("pause>0");

	return 0;

}