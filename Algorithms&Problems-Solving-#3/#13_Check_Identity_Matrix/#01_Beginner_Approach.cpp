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
			arr[i][j] = RandomNumber(0, 1);

	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(2) <<  arr[i][j] << "    ";
		}
		cout << endl;
	}

}

int IsIdentityMatrix(int Matrix1[3][3], short ElementWhoWant, short Rows, short Col)
{
	 short Count = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (i == 0 && j == 0)
			{
				if (Matrix1[i][j] == ElementWhoWant)
					Count++;
			}
	
			if ( i == 1 && j == 1)
			{
				if (Matrix1[i][j] == ElementWhoWant)
					Count++;
			}

			if ((i == Rows - 1) && (j == Col - 1))
			{
				if (Matrix1[i][j] == ElementWhoWant)
					Count++;
			}
				

		}
	}

	return Count;
}

int main()
{

	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	short ElementWhoWant = 1;

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);


	if (IsIdentityMatrix(Matrix1, ElementWhoWant, 3, 3) == 3)
		cout << "\nYes: Matrix is identity.";
	else
		cout << "\nNo: Matrix is not identity.";

	system("pause>0");

	return 0;

}

