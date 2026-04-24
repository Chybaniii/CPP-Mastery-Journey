#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
enum enCharType { SmallLetter = 1, CapitalLetter = 2, Digit = 3, SpcialCharacter = 4 };

int RandomNumber(int From, int To)
{
	int random = rand() % (To - From + 1) + From;
	return random;
}

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::CapitalLetter:
	{

		return char(RandomNumber(65, 90));
		break;
	}

	case enCharType::SmallLetter:
	{

		return char(RandomNumber(97, 122));
		break;
	}
	{
	case enCharType::Digit:

		return char(RandomNumber(48, 57));
		break;
	}
	case enCharType::SpcialCharacter:
	{
		return char(RandomNumber(33, 47));
		break;
	}

	}

}

int ReadPositiveNumber(string message)
{
	int Number = 0;
	do
	{
		cout << message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

string GenerateWord(enCharType CharType, short Length)
{
	string Word;
	for (int i = 1; i <= Length; i++)
	{
		Word = Word + GetRandomCharacter(CharType);
	}
	return Word;
}
string GenerateKey()
{
	string Key;
	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4);

	return Key;
}

void GenerateKeys(short NumberOfKey)
{
	for (int i = 1; i <= NumberOfKey; i++)
	{
		cout << "Key [" << i << "] :" << GenerateKey() << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	GenerateKeys(ReadPositiveNumber("Please enter how many number you generate?"));
}