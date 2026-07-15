#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;


struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double accountBalance;
};

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

sClient ConvertLinToRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector <string> vClientData;

	vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.accountBalance = stod(vClientData[4]);

	return Client;

}

void PrintClientData(sClient Client)
{
	cout << "\n\nThe folowing is the extracted client record:\n";

	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPinCode       : " << Client.PinCode;
	cout << "\nName          : " << Client.Name;
	cout << "\nPhone         : " << Client.Phone;
	cout << "\nAccount Balanc: " << Client.accountBalance;
}


int main()
{
	string stLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#07000#//#5000";

	cout << "\nLine record is:\n";
	cout << stLine;
	sClient Client = ConvertLinToRecord(stLine);


	PrintClientData(Client);

	system("pause>0");
}