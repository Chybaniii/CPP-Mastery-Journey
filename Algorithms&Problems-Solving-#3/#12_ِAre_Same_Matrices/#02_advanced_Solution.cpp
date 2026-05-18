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

bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Col)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
			{
				return false;
			}
		}
	}

	return true;
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



	if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
		cout << "\nYes: both matrices are Typical.";
	else
		cout << "\nNo: matrices are not Typical.";

	system("pause>0");

	return 0;

}
