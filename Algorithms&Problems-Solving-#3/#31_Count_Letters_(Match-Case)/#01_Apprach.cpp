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

char InvertLettersCase(char Char)
{
	return isupper(Char) ? tolower(Char) : toupper(Char);
}


int CountLetter(string S1, char Letter, bool MatchCase = true)
{
	short Counter = 0;

	for (int i = 0; i < S1.length(); i++)
	{
		if (MatchCase)
		{
			if (S1[i] == Letter)
				Counter++;
		}

		else
		{
			if (tolower(S1[i]) == tolower(Letter))
				Counter++;
		}
			
	}

	return Counter;
}



int main()
{
	string S1 = ReadString();
	char Char1 = ReadChar();


	cout << "\nLetter '" << Char1 << "' Count = " << CountLetter(S1, Char1) << endl;
	
	cout << "\nLetter \'" << Char1 << "\' ";
	cout << "Or \'" << InvertLettersCase(Char1) << "\' ";
	cout << " Count = " << CountLetter(S1, Char1, false);


	system("pause>0");
	return 0;

}