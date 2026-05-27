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

string UpperAllStringLetters(string S1)
{
	for (int i = 0; i < S1.length(); i++)
		S1[i] = toupper(S1[i]);
	

	return S1;

}

string LowerAllStringLetters(string S1)
{
	for (int i = 0; i < S1.length(); i++)
		S1[i] = tolower(S1[i]);

	return S1;

}



int main()
{
	string S1 = ReadString();
	cout << "\nString after upper: \n";

	S1 = UpperAllStringLetters(S1);
	cout << S1 << endl;

	S1 = LowerAllStringLetters(S1);
	cout << "\nString after lower\n";
	cout << S1 << endl;

	system("pause>0");

	return 0;

}



