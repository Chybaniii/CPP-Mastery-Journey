#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
	int random = 0;
	random = rand() % (To - From + 1) + 1;
	return random;
}

void FillDimesionalArray(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		arr[i][j] = RandomNumber(1, 100);
	}
}

void PrintArray(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{  
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillDimesionalArray(arr);
	cout << "\n The following is a 3x3 random matrix:\n";
	PrintArray(arr);

    return 0;
}
