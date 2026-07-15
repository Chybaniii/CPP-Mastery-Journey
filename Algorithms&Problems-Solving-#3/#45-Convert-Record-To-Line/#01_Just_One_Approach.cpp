#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct sClient
{
	string Name;
	string AccountNumber;
	string PinCode;
	string Pohne;
	double AccountBalance;
};


sClient ReadnewClient()
{
	sClient Client;

	cout << "Enter Account number? ";
	getline(cin, Client.AccountNumber);

	cout << "\nEnter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "\nEnter Name? ";
	getline(cin, Client.Name);

	cout << "\nEnter Phone? ";
	getline(cin, Client.Pohne);

	cout << "\nEnter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Pohne + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

int main()
{
	sClient Client;
	cout << "Please enter Client data:\n\n";

	Client = ReadnewClient();

	cout << "\nClient record for saving: \n";
	cout << ConvertRecordToLine(Client);

	system("pause>0");
}
  

