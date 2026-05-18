
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

int MinNumberInArray(int Matrix1[3][3], short Rows, short Cols)
{
	short Min = 0;
	Min = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
			if (Matrix1[i][j] < Min)
				Min = Matrix1[i][j];
	}

	return Min;
}

int MaxNumberInArray(int Matrix1[3][3], short Rows, short Cols)
{
	short Max = 0;
	Max = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
			if (Matrix1[i][j] > Max)
				Max = Matrix1[i][j];
	}

	return Max;
}

int main()
{

	srand((unsigned)time(NULL));

	int Matrix1[3][3] = { {77,5,12}, {22,20,6}, {14,3,9} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMinimum number is: ";
	cout << MinNumberInArray(Matrix1, 3, 3) << endl;

	cout << "\nMaximum number is: ";
	cout << MaxNumberInArray(Matrix1, 3, 3) << endl;

	system("pause>0");

}
