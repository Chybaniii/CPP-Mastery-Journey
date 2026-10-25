
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};



enum enMainMenueOptions {
    eQuickWithDrow = 1, eNormalWithDrow = 2, Deposit = 3,
    eCheckBalance = 4, eExit = 5
};



const string ClientsFileName = "Clients.txt";
sClient CurrentClient;


void ShowNormalWithDrowScreen();
void ShowQuickWithDrowScreen();
void ShowMainMenue();
void Login();

vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}


sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double


    return Client;

}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{

    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return vClients;

}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }

    return vClients;

}


void AddDataLineToFile(string FileName, string  stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }

}


bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient>& vClients)
{
    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }

        }

        return false;

    }

    return false;
}

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();
}


short ReadQuickWithDrowAmount()
{
    cout << "Choose what do you want to do? [1 to 9]? ";

    short Choice = 0;
    cin >> Choice;
    while (Choice <= 0 || Choice > 9)
    {
        cout << "Choose what do you want to do? [1 to 9]? ";
        cin >> Choice;
    }

    return Choice;
}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 5]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

short GetQuickWithDrowAmount(short QuickWithDrowQAmount)
{

    switch (QuickWithDrowQAmount)
    {
    case 1:
        return 20;
    case 2:
        return 50;
    case 3:
        return 100;
    case 4:
        return 200;
    case 5:
        return 400;
    case 6:
        return 600;
    case 7:
        return 800;
    case 8:
        return 1000;
    default :
        return 0;
    }

}

void PerformQuickWithDrow(short QuickWithDrow)
{
    if (QuickWithDrow == 9)
        return;

    short QuickWithDrowAmount = GetQuickWithDrowAmount(QuickWithDrow);

    if (QuickWithDrowAmount > CurrentClient.AccountBalance)
    {
        cout << "\nThe amount exeeds your balance, make another choice.\n";
        cout << "Press Any Key to continue... ";
        system("pause>0");
        ShowQuickWithDrowScreen();
        return;
    }

    vector <sClient> vclients = LoadCleintsDataFromFile(ClientsFileName);
    if(DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, QuickWithDrowAmount * -1, vclients))
    CurrentClient.AccountBalance -= QuickWithDrowAmount;
}


int ReadNormalWithDrow()
{
    int Amount = 0;
    cout << "\nEnter an amount multiple of 5's ";

    cin >> Amount;
    while (Amount <= 0 || Amount % 5 != 0)
    {
        cout << "\nEnter an amount multiple of 5's ? ";
        cin >> Amount;
    }

    return Amount;
}


void ShowQuickWithDrowScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tQuickWithDrow\n";
    cout << "===========================================\n";
    cout << "\t[1] 20\t\t[2] 50\n";
    cout << "\t[3] 100\t\t[4] 200\n";
    cout << "\t[5] 400\t\t[6] 600\n";
    cout << "\t[7] 800\t\t[8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "Your balance is " << CurrentClient.AccountBalance << endl;
    PerformQuickWithDrow(ReadQuickWithDrowAmount());

}

void PerformNormalWithDrow()
{
    int NormalWithDrow = ReadNormalWithDrow();

    if (NormalWithDrow > CurrentClient.AccountBalance)
    {
        cout << "\nThe amount exeeds your balance, make another choice.\n";
        cout << "Press Any Key to continue... ";
        system("pause>0");
        ShowNormalWithDrowScreen();
        return;
    }

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    if (DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, NormalWithDrow * -1, vClients))
    CurrentClient.AccountBalance -= NormalWithDrow;

}


void ShowNormalWithDrowScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\tNomrmal WithDrow\n";
    cout << "===========================================\n";
    PerformNormalWithDrow();
}



double ReadDepositAmount()
{
    double Amount = 0;
    cout << "\nEnter an amount grater than 0. ";
    cin >> Amount;

    while (Amount <= 0)
    {
        cout << "\nEnter an amount grater than 0. ";
        cin >> Amount;
    }

    return Amount;
}

void PerformDeposit()
{
    double DepositAmount = ReadDepositAmount();

    vector <sClient> vclients = LoadCleintsDataFromFile(ClientsFileName);
   if (DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, DepositAmount, vclients))
    CurrentClient.AccountBalance += DepositAmount;

}

void ShowDepositScreen()
{

    system("cls");
    cout << "===========================================\n";
    cout << "\tDeposit Screen\n";
    cout << "===========================================\n";
    PerformDeposit();
}
void ShowBalanceScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\tCheck Balance Screen\n";
    cout << "===========================================\n";
    cout << CurrentClient.AccountBalance << endl;
}



void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
        case enMainMenueOptions::eQuickWithDrow:
    {
        system("cls");
       ShowQuickWithDrowScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eNormalWithDrow:
        system("cls");
        ShowNormalWithDrowScreen();
        GoBackToMainMenue();
        break;

        case enMainMenueOptions::Deposit:
        system("cls");
        ShowDepositScreen();
        GoBackToMainMenue();
        break;

        case enMainMenueOptions::eCheckBalance:
        system("cls");
        ShowBalanceScreen();
        GoBackToMainMenue();
        break;

        case enMainMenueOptions::eExit:
        system("cls");
        Login();
        break;

    }

}

void ShowMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tATM Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick WithDrow.\n";
    cout << "\t[2] Normal WithDrow.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";


    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}


bool FindClientByAccontNumberAndPinCode(string AccountNumber, string PinCode, sClient& Client)
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
        {
            Client = C;
            return true;
        }
    }

    return false;
}
bool  LoadClientInfo(string AccountNumber, string PinCode)
{

    if (FindClientByAccontNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
        return true;
    else
        return false;

}

void Login()
{
    bool LoginFaild = false;

    string AccountNumber, PinCode;
    do
    {
        system("cls");

        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (LoginFaild)
        {
            cout << "Invlaid AccountNumber/PinCode !\n";
        }

        cout << "Enter AccountNumber? ";
        cin >> AccountNumber;

        cout << "Enter Pincode? ";
        cin >> PinCode;

        LoginFaild = !LoadClientInfo(AccountNumber, PinCode);

    } while (LoginFaild);

    ShowMainMenue();

}

int main()

{
    Login();
    system("pause>0");
    return 0;
}