#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(2) << arr[i][j] << "    ";
		}
		cout << endl;
	}

}

bool IsScalarMatrix(int Matrix1[3][3], short Rows, short Col)
{
	

	int FirstDiagElement = Matrix1[0][0];
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			//check for Diagonal element
			if (i == j && Matrix1[i][j] != FirstDiagElement)
			{
				return false;
			}
			//Check for rest elements.
			else if (i != j && Matrix1[i][j] != 0)
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

	int Matrix1[3][3] = { {9,0,0}, {0,9,0}, {0,0,9} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);


	if (IsScalarMatrix(Matrix1, 3, 3))
		cout << "\nYes: Matrix is Scalar.";
	else
		cout << "\nNo: Matrix is not Scalar.";

	system("pause>0");

	return 0;

}
