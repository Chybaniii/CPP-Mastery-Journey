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

void PrintIntresetedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Col)
{
	
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			for (short k = 0; k < Rows; k++)
			{
				for (short l = 0; l < Col; l++)
					if (Matrix1[i][j] == Matrix2[k][l])
					{
						cout << Matrix1[i][j] << "   ";
					}
			}
				
		}

	}
}

int main()
{

	srand((unsigned)time(NULL));

	int Matrix1[3][3] = { {77,5,12}, {22,20,1}, {1,0,9} };
	int Matrix2[3][3] = { {5,80,90}, {22,77,1}, {10,8,33} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
    
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nIntersected Numbers are:\n";
	PrintIntresetedNumbers(Matrix1, Matrix2, 3, 3);

	system("pause>0");

}