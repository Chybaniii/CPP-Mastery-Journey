
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

int ReadNumber(string message)
{
	short Number = 0;
		cout << message;
		cin >> Number;

	return Number;
}

int CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Col)
{
	
	short Count = 0;
	
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Number == Matrix1[i][j])
				Count++;
		}

	}

	return Count;
}

int main()
{

	srand((unsigned)time(NULL));

	int Matrix1[3][3] = { {9,1,12}, {0,9,1}, {0,9,9} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	short Number = ReadNumber("\nEnter the number to count in matrix ?");

	cout << "\n\nNumber " << Number << " Count in matrix is " 
		<< CountNumberInMatrix(Matrix1, Number, 3, 3) << endl;

	system("pause>0");



}