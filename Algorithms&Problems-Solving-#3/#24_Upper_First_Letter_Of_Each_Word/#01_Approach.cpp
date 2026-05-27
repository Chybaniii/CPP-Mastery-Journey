#include <iostream>
#include <cstdlib>
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

string UpperFirstLetterOfEachWord(string S1)
{
	bool IsFirstLetter = true;

	cout << "\nFirst Letters of this string: \n";

	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && IsFirstLetter)
		{
			S1[i] = toupper(S1[i]);
		}
		
		IsFirstLetter = (S1[i] == ' ' ? true : false);
	}

	return S1;

}



int main()
{
	string S1 = ReadString();
	cout << "\String after conersion: \n";

	S1 = UpperFirstLetterOfEachWord(S1);
	cout << S1 << endl;

	system("pause>0");

	return 0;

}
