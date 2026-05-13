#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int OrderNumber()
{
	static int Order = 0;
	return	++Order;

}

void FillMatrixWithOrderNumbers(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
			arr[i][j] = OrderNumber();
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

	int arr[3][3];

	FillMatrixWithOrderNumbers(arr, 3, 3);

	cout << "\n The following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	system("pause>0");

	return 0;

}
