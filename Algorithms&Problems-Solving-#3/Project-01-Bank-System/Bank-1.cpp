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
	bool MarkForDelete = false;
};

void ShowMainMenue();


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

void PrintClientRecord(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.accountBalance;
}

void PrintAllClientsData(vector <sClient> vClients)
{
	cout << "\n\t\t\t\t\tClients List (" << vClients.size() << ") Client(s). ";
	cout << "\n__________________________________________________________________________________________________\n";

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n__________________________________________________________________________________________________\n";

	for (sClient Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}

	cout << "\n__________________________________________________________________________________________________" << endl;

}



bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in); //read mode.

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLinToRecord(Line);
			if (Client.AccountNumber == AccountNumber)
			{
				MyFile.close();
				return true;
			}

			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return false;

}


sClient ReadnewClient()
{
	sClient Client;

	cout << "Enter Account number? ";
	getline(cin >> ws, Client.AccountNumber);

	while (ClientExistsByAccountNumber(Client.AccountNumber, ClietnsFileName))
	{
		cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another AccountNumber ? ";
		getline(cin >> ws, Client.AccountNumber);

	}

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.accountBalance;

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

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;

		MyFile.close();
	}
}

void PrintClientRecordLine(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.accountBalance;
}

void ShowAllClientsScreen()
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClietnsFileName);

	cout << "\n\t\t\t\t\tClients List (" << vClients.size() << ") Client(s). ";
	cout << "\n__________________________________________________________________________________________________\n";
	cout << "-----------------------------------------------------------------------------\n";

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n__________________________________________________________________________________________________\n";
	cout << "-----------------------------------------------------------------------------\n";

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo clients available In the system!";
	else 

	for (sClient Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}

	cout << "\n__________________________________________________________________________________________________" << endl;
	cout << "-----------------------------------------------------------------------------\n";

}

void AddNewClient()
{
	sClient Client;
	Client = ReadnewClient();
	AddDataLineToFile(ClietnsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
	char AddMore = 'Y';

	do
	{
		//system("cls");
		cout << "Adding new client: \n\n";

		AddNewClient();
		cout << "\nClient added secssusfuly, Do you want to add more client? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

void ShowAddNewClientsScreen()
{
	cout << "\n---------------------------------\n";
	cout << "\tAdd New Client Screen";
	cout << "\n---------------------------------\n";

	AddNewClients();
}

enum enMainMenueOptions
{
	eListClients = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eExit = 6
};
short ReadMainMenueOption()
{
	cout << "Chose what do you want to do? [1 to 6]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;

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

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want delete this client y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccontNumber(AccountNumber, vClients);
			SaveClientDataToFile(ClietnsFileName, vClients);

			//Refresh Clients.
			vClients = LoadClientsDataFromFile(ClietnsFileName);

			cout << "\n\nClient deleted successfully.";
			return true;
		}
	}

	else
	{
		cout << "\n\nClient with account number (" << AccountNumber << ") is not found!\n";
		return false;
	}

}



string ReadClientAccountNumber()
{
	string AccountNumber = "";
	cout << "Please enter account number? ";
	cin >> AccountNumber;

	return AccountNumber;
}

void showDeleteClientScreen()
{
	cout << "\n---------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n---------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClietnsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
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


			SaveClientDataToFile(ClietnsFileName, vClients);
/*
			//Refresh Clients.
			vClients = LoadClientsDataFromFile(ClietnsFileName);*/

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


void ShowUpdateClientScreen()
{
	cout << "\n---------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n---------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClietnsFileName);
	string AccountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{
	cout << "\n---------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n---------------------------------\n";

	vector <sClient> vClients = LoadClientsDataFromFile(ClietnsFileName);
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		PrintClientCard(Client);
	else
		cout << "\nClient with account Number [" << AccountNumber << "] is not found!"; 

}

void ShowEndScreen()
{
	cout << "\n---------------------------------\n";
	cout << "\tProgramme End :-)";
	cout << "\n---------------------------------\n";
}

void GoBackToMainMenue()
{
	cout << "\n\nPrees any key to go back to main menue...";
	system("pause");
	ShowMainMenue();

}

void PerformMainMenueOptions(enMainMenueOptions MainMenueOption)
{
	switch (MainMenueOption)
	{
	case enMainMenueOptions::eListClients:
	{
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenue();
		break;
	}
	case enMainMenueOptions::eAddNewClient:
	{
		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainMenue();
		break;
	}
	case enMainMenueOptions::eDeleteClient:
	{
		system("cls");
		showDeleteClientScreen();
		GoBackToMainMenue();
		break;
	}
	case enMainMenueOptions::eUpdateClient:
	{
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenue();
		break;
	}
	case enMainMenueOptions::eFindClient:
	{
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenue();
		break;
	}
	case enMainMenueOptions::eExit:
	{
		system("cls");
		ShowEndScreen();
		break;
	}
	}
}

void ShowMainMenue()
{
	system("cls");
	cout << "===================================================\n";
	cout << "\t\tMain Menue Screen\n";
	cout << "===================================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Exit.\n";
	cout << "===================================================\n";
	PerformMainMenueOptions((enMainMenueOptions)ReadMainMenueOption());

}

int main()
{
	ShowMainMenue();
	system("pause>0");
	return 0;
}
