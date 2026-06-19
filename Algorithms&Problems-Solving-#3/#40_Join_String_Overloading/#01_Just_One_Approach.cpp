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

string JoinString(string arr[], int Length, string Sep)
{
	string S1 = "";

	for (int i = 0; i < Length; i++)
	{
		S1 += arr[i] + Sep;
	}

	return S1.substr(0, S1.length() - Sep.length());
}

int main()
{
	vector <string> Vstring = { "Mohammed","Lemin","Lhaje","Abderhamman" }; 

	string arr[] = { "Mohammed","Lemin","Lhaje","Abderhamman" };
	cout << "\nVector after join\n\n";
	cout << JoinString(Vstring, " ");

	cout << "\n\nArray after join\n\n";
	cout << JoinString(arr, 4, " ");

	system("pause>0");

	return 0;
}
