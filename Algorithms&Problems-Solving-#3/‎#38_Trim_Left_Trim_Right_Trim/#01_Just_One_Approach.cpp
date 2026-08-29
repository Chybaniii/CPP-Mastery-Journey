#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please enter your string\n";
	getline(cin, S1);

	return S1;
}

string TrimLeft(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - 1);
			}
	}

	return "";
}


string TrimRight(string S1)
{
	for (int i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
		}
	}
	return "";
}


string Trim(string S1)
{
	return (TrimLeft(TrimRight(S1)));
}


int main()
{
	string S1 = "    Mohammed Lemin Elhaj    ";

	cout << "\nString = " << S1 << endl;
	cout << "\n\nTirm Left = " << TrimLeft(S1) << endl;
	cout << "Tirm Rghit = " << TrimRight(S1) << endl;
	cout << "Tirm " << Trim(S1) << endl;

	system("pause>0");

	return 0;
}
