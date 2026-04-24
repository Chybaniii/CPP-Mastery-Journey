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
		
		case enCharType::Digit:
        {
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

int main()
{
	srand((unsigned)time(NULL));

	cout << GetRandomCharacter(enCharType::CapitalLetter) << endl;
	cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
	cout << GetRandomCharacter(enCharType::Digit) << endl;
	cout << GetRandomCharacter(enCharType::SpcialCharacter) << endl;

}