#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void FillMatrixWithOrderNumbers(int arr[3][3], short Rows, short Cols)
{
	int Counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Counter++;
			arr[i][j] = Counter;
		}
			
	}
}

void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j <= Cols - 1; j++)
			arrTransposed[i][j] = arr[j][i];
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

int main()
{

	int arr[3][3], arrTransposed[3][3];

	FillMatrixWithOrderNumbers(arr, 3, 3);

	cout << "\n The following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);


	TransposeMatrix(arr, arrTransposed, 3, 3);

	cout << "\n\nThe following is the transposed matix:\n";
	PrintMatrix(arrTransposed, 3, 3);


	system("pause>0");

	return 0;

}
