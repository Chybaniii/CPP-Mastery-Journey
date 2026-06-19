#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


string ReadString()
{
	string S1;
	cout << "\nPlease enter your string ?\n";
	getline(cin, S1);

	return S1;
}

void PrintEachWord(string S1)
{
	string S2;
	for (int i = 0; i < S1.length(); i++)
	{
		S2 += S1[i];

		if (isspace(S1[i]))
		{
			cout << S2 << endl;
			S2 = "";
		}

		if (i + 1 == S1.length())
		{
			cout << S2 << endl;
		}



	}

}


int main()
{
	string S1 = ReadString();

	cout << "\nYour string words are:\n\n";
	PrintEachWord(S1);


	system("pause>0");
	return 0;
}


