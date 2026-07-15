#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please enter your string?\n";
	getline(cin, S1);

	return S1;
}

string RemovePunctFromString(string S1)
{
	string S2 = "";

	for (int i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
			S2 += S1[i];
	}

	return S2;
}

int main()
{
	string S1 = ReadString();

	cout << "\n\nString after remove punctuations: \n";
	cout << RemovePunctFromString(S1);

	cout << "\n\n";

	system("pause>0");
}
