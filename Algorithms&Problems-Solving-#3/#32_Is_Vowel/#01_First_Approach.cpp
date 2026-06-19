#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

char ReadChar()
{
	char Char1;
	cout << "\nPlease enter a caracter ?\n";
	cin >> Char1;

	return Char1;
}

bool AreVowels(char Letter)
{


	for (int i = 0; i < 5; i++)
	{
		if (Letter == 'a' || Letter == 'A')
			return true;
		else if (Letter == 'e' || Letter == 'E')
			return true;
		else if (Letter == 'i' || Letter == 'I')
			return true;
		else if (Letter == 'o' || Letter == 'O')
			return true;
		else if (Letter == 'u' || Letter == 'U')
			return true;

	}

	return false;

}

int main()
{
	char Char1 = ReadChar();

	if (AreVowels(Char1))
		cout << "\nYES Letter " << Char1 << " is vowel\n";
	else
		cout << "\nNO Letter " << Char1 << " is not vowel\n";


	system("pause>0");
	return 0;
}


