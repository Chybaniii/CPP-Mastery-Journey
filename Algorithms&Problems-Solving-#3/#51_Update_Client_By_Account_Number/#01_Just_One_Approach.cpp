#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string ClientsFileName = "Clients.txt";
struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double accountBalance;
	bool MarkForDelete = false;
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


string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.accountBalance);

	return stClientRecord;
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

bool FindClientByAccountNumber(string AccountNumber, vector <sClient>& vClients, sClient& Client)
{
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

bool MarkClientForDeleteByAccontNumber(string AccountNumber, vector <sClient>& vClient)
{
	for (sClient& C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}

	return false;
}


vector <sClient> SaveClientDataToFile(string FileName, vector <sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); //OverWrite

	string DataLine;

	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				//We only write records that are not marked for delete.
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}

		MyFile.close();
	}

	return vClients;

	
}

sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;

	Client.AccountNumber = AccountNumber;

	cout << "\n\nEnter new PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter new Name? ";
	getline(cin, Client.Name);

	cout << "Enter new Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter new Account Balance? ";
	cin >> Client.accountBalance;

	return Client;

}


bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want to updated this client y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}

		
			SaveClientDataToFile(ClientsFileName, vClients);

			//Refresh Clients.
			vClients = LoadClientsDataFromFile(ClientsFileName);

			cout << "\n\nClient updated successfully.";
			return true;
		}
	}

	else
	{
		cout << "\n\nClient with account number (" << AccountNumber << ") is not found!\n";
		return false;
	}
	
}



int main()
{

	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();

	UpdateClientByAccountNumber(AccountNumber, vClients);


	system("pause>0");
	return 0;
}
