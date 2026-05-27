#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

string ReadString()
{
	string S1;
	cout << "\nPlease enter your String ?\n";
	getline(cin, S1);


	return S1;
}

char ReadChar()
{
	char Char1;
	cout << "\nPlease enter a caracter ?\n";
	cin >> Char1;

	return Char1;
}


int CountLetter(string S1, char Char1)
{
	short Counter = 0;

	for (int i = 0; i < S1.length(); i++)
	{
		if (Char1 == S1[i])
			Counter++;
	}

	return Counter;
}


int main()
{
	 string S1 = ReadString();
	 char Char1 = ReadChar();
	 
	 cout << "\nLetter '" << Char1 << "' Count = " << CountLetter(S1, Char1) << endl;


	
	system("pause>0");
	return 0;

}



