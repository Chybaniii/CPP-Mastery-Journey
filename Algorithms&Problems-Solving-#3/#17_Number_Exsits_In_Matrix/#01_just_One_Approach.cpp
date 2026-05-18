
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
short ReadNumber(string message)
{
	short IsExistsInMatrix = 0;
	cout << message;
	cin >> IsExistsInMatrix;

	return IsExistsInMatrix;
}

bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Col)
{
	
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Number == Matrix1[i][j])
				return true;
		}

	}

	return false;
}

int main()
{

	srand((unsigned)time(NULL));

	int Matrix1[3][3] = { {77,5,12}, {22,20,1}, {1,0,9} };  

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	short Number = ReadNumber("\nPlease enter a number to look for in matrix?");

	if (IsNumberInMatrix(Matrix1, Number, 3, 3))
		cout << "\nYes: It's there.";
	else
		cout << "\nNo: It's NOT there.";
	       
 
	system("pause>0");

}


