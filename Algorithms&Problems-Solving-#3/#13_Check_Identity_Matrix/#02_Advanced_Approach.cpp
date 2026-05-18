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

bool IsIdentityMatrix(int Matrix1[3][3], short Rows, short Col)
{
     //Check Diagonal elements are 1 and rest elements are 0.

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			//check for diagonal element
			if (i == j && Matrix1[i][j] != 1)
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

	int Matrix1[3][3] = { {1,0,0}, {0,1,0}, {0,0,1} };
	
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);


	if (IsIdentityMatrix(Matrix1, 3, 3))
		cout << "\nYes: Matrix is identity.";
	else
		cout << "\nNo: Matrix is not identity.";

	system("pause>0");

	return 0;

}
