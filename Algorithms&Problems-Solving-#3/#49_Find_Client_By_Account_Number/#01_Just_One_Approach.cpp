#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string ClietnsFileName = "Clients.txt";
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

vector <sClient> LoadClientsDataFromFile(string FileName)
{
	vector <sClient> vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in);


	if (MyFile.is_open())
	{
		sClient Client;
		string Line;

		while (getline(MyFile, Line))
		{
			Client = ConvertLinToRecord(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}

string ReadAccountNumber()
{
	string AccountNumber = "";
	cout << "Please enter account number? ";
	cin >> AccountNumber;

	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, sClient& Client)
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClietnsFileName);
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}

	return false;
}

void PrintClientCard(sClient Client)
{
	cout << "\n\nClient Card\n";

	cout << "__________________________________________\n";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPinCode       : " << Client.PinCode;
	cout << "\nName          : " << Client.Name;		
	cout << "\nPhone         : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.accountBalance;
	cout << "\n\n";
	cout << "__________________________________________\n";
}

int main()
{
	sClient Client;
	string AccountNumber = ReadAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\n\nClient with account number (" << AccountNumber << ") is not found!\n";
	}

	system("pause>0");
	return 0;
}


