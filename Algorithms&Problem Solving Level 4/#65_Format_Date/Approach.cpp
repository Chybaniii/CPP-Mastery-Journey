
#include <iostream>
#include <vector>
#include <string>
using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "Please enter a year? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	short Month;

		cout << "Please enter a month? ";
		cin >> Month;

	return Month;
}

short ReadDay()
{
	short Day = 0;

	cout << "Please enter a day? ";
	cin >> Day;

	return Day;
}


struct stDate {
	int Year;
	int Month;
	int Day;

};

string ReadString()
{
	string Text = "";

	cout << "\nPlease Enter Date dd/mm/yyyy? ";
	getline(cin >> ws, Text);

	return Text;
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

	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

stDate StringToDate(string DateStrng)
{
	stDate Date;
	vector <string> vDate;
	vDate = SplitString(DateStrng, "/");

	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string DateToString(stDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}


int main()
{
	string DateString = ReadString();
	stDate Date = StringToDate(DateString);

	cout << "\nDay: " << Date.Day;
	cout << "\nMonth: " << Date.Month;
	cout << "\nYear: " << Date.Year;

	cout << "\n\nYou Entered: " << DateToString(Date);

	system("pause>0");
}

