#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

string ReadChar()
{
	string S1;
	cout << "\nPlease enter your Char ?\n";
	getline(cin, S1);


	return S1;
}

char InvertLettersCase(char Char)
{
	return isupper(Char) ? tolower(Char) : toupper(Char);
}

string InvertAllStringLettersCase(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertLettersCase(S1[i]);
	}
		
	return S1;
}


int main()
{
	 string S1 = ReadChar();

	cout << "\nString after converting All letters case: \n";
	S1 = InvertAllStringLettersCase(S1);
	cout << S1 << endl;

	system("pause>0");

	return 0;

}


