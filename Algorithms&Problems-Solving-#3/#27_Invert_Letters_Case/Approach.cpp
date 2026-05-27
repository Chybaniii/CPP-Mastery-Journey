#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

char ReadChar()
{
	char Chr1;
	cout << "\nPlease enter your Char ?\n";
	cin >> Chr1;


	return Chr1;
}

char ConvertLettersCase(char Char)
{
	return isupper(Char) ? tolower(Char) : toupper(Char);
}



int main()
{
	char Char1 = ReadChar();

	Char1 = ConvertLettersCase(Char1);
	cout << "\nChar after converting case: \n";
	cout << Char1 << endl;

	system("pause>0");

	return 0;

}



