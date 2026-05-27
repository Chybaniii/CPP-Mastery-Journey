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

enum enWhatToCoun {CapitalLetters = 1, SmallLetters = 2, Length = 3 };

short CountLetters(string S1, enWhatToCoun WhatToCount = enWhatToCoun::Length)
{
	short Counter = 0;


	if (WhatToCount == enWhatToCoun::Length)
	{
		return S1.length();
	}


		for (int i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == enWhatToCoun::CapitalLetters && isupper(S1[i]))
			{
				Counter++;
			}



			if (WhatToCount == enWhatToCoun::SmallLetters && islower(S1[i]))
			{

				Counter++;
			}
	}


	

	return Counter;
}

int CountSmallLetters(string S1)
{
	short CountSmall = 0;

	for (int i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
		{
			CountSmall++;
		}
	}
		
	return CountSmall;
}



int CountCapitalLetters(string S1)
{
	short CountCapital = 0;

	for (int i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
		{
			CountCapital++;
		}
	}

	return CountCapital;
}


int main()
{
	 string S1 = ReadString();

	 cout << "\nString length = " << S1.length() << endl;
	 cout << "Capital letters count = " << CountCapitalLetters(S1) << endl;
	 cout << "Small letters count = " << CountSmallLetters(S1) << endl;


	cout << "\n\nMethode 2\n";


	cout << "\nString length = " << CountLetters(S1) << endl;
	cout << "Capital letters count = " << CountLetters(S1, enWhatToCoun::CapitalLetters) << endl;
	cout << "Small letters count = " << CountLetters(S1, enWhatToCoun::SmallLetters) << endl;
	system("pause>0");

	system("pause>0");
	return 0;

}
