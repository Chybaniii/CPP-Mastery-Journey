#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

enum enGameChoice {Stone =1, Paper = 2, Scissors = 3};
enum enWinner {Player1 = 1, Computer = 2, Drow = 3};

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

struct stGameResults
{        
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short Computer2WinTimes = 0;
	short DrowTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";  
};

int RandomNumber(int From, int To)
{
	short random = 0;
	random = rand() % (To - From + 1) + From;
	return random;
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1" , "Computer" , "No Winner" };
	return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::Drow;
	}

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;
		}
		break;

	}

	//If you reach here then player1 is the winner.
	return enWinner::Player1;
}

string ChoiceName(enGameChoice Choice)
{
	string arrGameChoices[3] = { "Stone" , "Paper", "Scissors" };
	return arrGameChoices[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F"); //turn screen to Green.
		break;

	case enWinner::Computer:
		system("color 4F"); //turn screen to Red
		cout << "\a";
		break;
	default:
		system("color 6F"); //turn screen to Yellow
		break;
	}
} 

void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n_______________Round [" << RoundInfo.RoundNumber << "]___________\n\n";
	cout << "Player1 choice : " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round winner   : [" << RoundInfo.WinnerName << "] \n";
	cout << "___________________________________\n" << endl;

	SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (ComputerWinTimes > Player1WinTimes)
		return enWinner::Computer;
	else
		return enWinner::Drow;
}

stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrowTimes)
{
	stGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.Computer2WinTimes = ComputerWinTimes;
	GameResults.DrowTimes = DrowTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

enGameChoice ReadPlayer1Choice()
{
	short Choice = 1;

	do
	{
		cout << "\nYour choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Choice;

	} while (Choice < 1 || Choice > 3);

	return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

stGameResults PlayGame(short HowMnyRounds)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrowTimes = 0;

	for (short GameRound = 1; GameRound <= HowMnyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);


		//increase win/drow counters.
		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrowTimes++;

		PrintRoundResults(RoundInfo);
	}

	return FillGameResults(HowMnyRounds, Player1WinTimes, ComputerWinTimes, DrowTimes);
}

string Tabs(short NumberOfTabs)
{
	string t = "";

	for (int i = 1; i < NumberOfTabs; i++)
	{
		t = t + "\t";
		//cout << t;
	}

	return t;
}

void ShowGameOverOnScreen()
{
	cout << Tabs(2) << "_______________________________________________________________\n\n";
	cout << Tabs(2) << "                      +++ G a m e  O v e r +++\n";
	cout << Tabs(2) << "_______________________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "_______________________ [ Game Results ] _______________________\n\n";
	cout << Tabs(2) << "Game Rounds         : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 won times   : " << GameResults.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer won times  : " << GameResults.Computer2WinTimes << endl;
	cout << Tabs(2) << "Drow times          : " << GameResults.DrowTimes << endl;
	cout << Tabs(2) << "Final winner        : " << GameResults.WinnerName << endl;
	cout << Tabs(2) << "________________________________________________________________\n\n";

	SetWinnerScreenColor(GameResults.GameWinner);
}

short ReadHowManyRounds()
{
	short GameRounds = 1;
	
	do
	{

		cout << "How many rounds 1 to 10 ? \n";
		cin >> GameRounds;

	} while (GameRounds < 1 || GameRounds > 10);

	return GameRounds;
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameReaults = PlayGame(ReadHowManyRounds());
		ShowGameOverOnScreen();
		ShowFinalGameResults(GameReaults);

		cout << endl << Tabs(4) << "Do you want play again?  Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	//Seeds the random number generator in C++, called only once.
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
