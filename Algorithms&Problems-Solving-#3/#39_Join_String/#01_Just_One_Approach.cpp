#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string> Vstring, string Delim)
{
	string S1 = "";

	for (string& s : Vstring)
	{
		S1 = S1 + s + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
	vector <string> Vstring = { "Mohammed","Lemin","Lhaje","Abderhamman" };

	cout << "\nString after join\n\n";
	cout << JoinString(Vstring, " ");

	system("pause>0");

	return 0;
}
