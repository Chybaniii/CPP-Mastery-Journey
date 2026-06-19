#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please enter your string\n";
	getline(cin, S1);

	return S1;
}


vector <string> SplitString(string S1, string delim)
{
	vector <string> vString;
	string sWord;
	short pos = 0;


	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + delim.length());
	}

	if (S1 != "");
	{
		vString.push_back(S1);
	}

	return vString;
}

int main()
{
	vector <string> vString;
	vString = SplitString(ReadString(), " ");

	cout << "\nTokens = ";
	cout << vString.size();
	cout << "\n\n";

	for (string& S : vString)
	{
		cout << S << endl;
	}

	system("pause>0");

	return 0;
}
