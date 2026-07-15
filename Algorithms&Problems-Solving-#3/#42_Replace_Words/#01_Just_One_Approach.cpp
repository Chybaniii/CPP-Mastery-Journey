#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

vector <string> SplitString(string S1, string delim)
{
	vector <string> vString;
	string sWord = "";
	int pos = 0;

	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord != " ")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + delim.length());
	}

	if (S1 != " ")
	{
		vString.push_back(S1);
	}

	return vString;
}

string JoinString(vector <string> vString, string delim)
{
	string S1 = "";

	for (string& s : vString)
	{
		S1 += s + delim;
	}

	return S1.substr(0, S1.length() - delim.length());
}

string LowerAllString(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}

	return S1;
}

string ReplaceWordInStringUsingBuiltInFuncion(string S1, string StringToReplace, string StringReplaceTo)
{
	short pos = S1.find(StringToReplace);

	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), StringReplaceTo);
		pos = S1.find(StringToReplace); //find next
	}

	return S1;
}


int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "Jordan";
	string SReplaceTo = "USA";

	cout << "\n\nOriginal string: ";
	cout << "\n" << S1;


	cout << "\n\nString after replace: ";
	cout << "\n" << ReplaceWordInStringUsingBuiltInFuncion(S1, StringToReplace, SReplaceTo);


	system("pause>0");
}