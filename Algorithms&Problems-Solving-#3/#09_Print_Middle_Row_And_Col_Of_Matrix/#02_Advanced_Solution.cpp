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

void PrintMiddleRowOfMatrix (int arr[3][3], short Rows, short Cols)
{
	short MiddleRow = Rows / 2;

	for (short j = 0; j <= Rows - 1; j++)
	{
		printf(" %0*d   ", 2, arr[MiddleRow][j]);
	}
	cout << "\n";
}

void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
{
	short MiddleCol = Cols / 2;
	for (short j = 0; j <= Cols - 1; j++)
	{
		printf(" %0*d   ", 2, arr[j][MiddleCol]);
	}
	cout << "\n";
}
int main()
{
	//Seeds the random number generator in C++, Called only once
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNumbers(Matrix, 3, 3);

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nMiddel Row of the matrix is:\n";
	PrintMiddleRowOfMatrix(Matrix, 3, 3);

	
	cout << "\nMiddel Col of the matrix is:\n";
	PrintMiddleColOfMatrix(Matrix, 3, 3);



	system("pause>0");

	return 0;

}
