#include <iostream>
#include <string>
using namespace std;

string ReadPassword()
{
	string Password = "";

	cout << "Please enter a 3-letter password (all capital)" << endl;
	cin >> Password;

	return Password;
}

bool GeussPassword(string OriginalPassord)
{
	cout << "\n";

	string word = "";
	int Counter = 0;
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				Counter++;

				word = word + char(i);
				word = word + char(j);
				word = word + char(k);

				cout << "Trial {" << Counter << "} : " << word << endl;

				if (word == OriginalPassord)
				{
					cout << " \nPassword is " << word << endl;
					cout << "found after " << Counter << " trial(s) " << endl;
					return true;
				}
				word = "";
			}
		}

	}
	return false;
}

int main()
{
	GeussPassword(ReadPassword());


}
