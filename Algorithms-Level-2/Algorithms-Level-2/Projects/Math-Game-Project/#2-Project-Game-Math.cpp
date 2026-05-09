#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

enum enQuestionLevel {EasyLevel = 1, MidLevel = 2, HardLevel = 3, Mix = 4};
enum enOperationType {Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5};

struct stQuestion
{
	short Number1 = 0;
	short Number2 = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	short CorrectAnswer = 0;
	short PlayerAnswer = 0;
	bool AnswerResult = false;

};

struct stQuizz
{    
	stQuestion QuestionList[100];
	short NumberOfQeution = 0;
	short NumOfRigthAnswers = 0;
	short NumOfWrongAnswers = 0;
	enQuestionLevel QuetionLevel;
	enOperationType OpType;
	bool IsPass = false;
};

short RandomNumber(short From, short To)
{
	int random = 0;
	random = rand() % (To - From + 1) + From;
	return random;
}

void SetColorScreen(bool Right)
{
	if (!Right)
      {
	      system("color 4F");
	      cout << "\a";
       }
    else
         system("color 2F");
}

short SimpleCalculator(short Number1, short Number2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Mul:
		return Number1 * Number2;
	case enOperationType::Sub:
		return Number1 - Number2;
	case enOperationType::Div:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

enOperationType GetRandomOperationType()
{
	short Op = RandomNumber(1, 4);
	return (enOperationType)Op;
}

string GetOpTypeSymbol(enOperationType OpType)
{
	if (OpType == enOperationType::Add)
		return "+";
	else if (OpType == enOperationType::Div)
		return "/";
	else if (OpType == enOperationType::Mul)
		return "*";
	else if (OpType == enOperationType::Sub)
		return "-";
	else
		return "Mix";
}
string GetQuestionLevelText(enQuestionLevel QuestionLevel)
{
	string arrNameLevel[4] = { "Easy", "Mid", "Hard", "Mix" };
	return arrNameLevel[QuestionLevel - 1];
}

short ReadHowManyQeutions()
{
	short NumberOfQuestin = 0;

	do
	{
		cout << "\nHow many qeutions do you want to answer ?";
		cin >> NumberOfQuestin;

	} while (NumberOfQuestin < 1 || NumberOfQuestin > 10);

	return NumberOfQuestin;
}

enQuestionLevel ReadQuestionLevel()
{
	short QuestionLevel = 0;
	do
	{
		cout << "\nEnter qeution level [1]: Easy, [2]: Mid, [3]: Hard, [4]: Mix ?";
		cin >> QuestionLevel;

	} while (QuestionLevel < 1 || QuestionLevel > 4);

	return (enQuestionLevel)QuestionLevel;
}

enOperationType ReadOperationType()
{
	short OperationType = 0;
	do
	{
		cout << "\nEnter operation type [1]: Add, [2]: Sub, [3]: Mul, [4]: Div, [5]: Mix";
		cin >> OperationType;

	} while (OperationType < 1 || OperationType > 5);

	return (enOperationType)OperationType;
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OpType)
{
	stQuestion Question;

	if (QuestionLevel == enQuestionLevel::Mix)
	{
		QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
	}

	if (OpType == enOperationType::MixOp)
	{
		OpType = GetRandomOperationType();
	}

	Question.OperationType = OpType;

	switch (QuestionLevel)
	{
	case enQuestionLevel::EasyLevel:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;


	case enQuestionLevel::MidLevel:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;

	case enQuestionLevel::HardLevel: 
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;


	}

	return Question;

}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
	for (short Question = 0; Question < Quizz.NumberOfQeution; Question++)
	{
		Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuetionLevel, Quizz.OpType);
	}
}

short ReadQuestionAnswer()
{
	short Answer = 0;
	cin >> Answer;
	return Answer;
}

void PrintTheQuestion(stQuizz& Quizz, short Questionumber)
{
	cout << "\n";
	cout << "Question [" << Questionumber + 1 << "/" << Quizz.NumberOfQeution << "] \n\n";
	cout << Quizz.QuestionList[Questionumber].Number1 << endl;
	cout << Quizz.QuestionList[Questionumber].Number2 << " ";
	cout << GetOpTypeSymbol(Quizz.QuestionList[Questionumber].OperationType);
	cout << "\n_______" << endl;
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
	if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = false;
		Quizz.NumOfWrongAnswers++;

		cout << "Wrong Answer :-( \n";
		cout << "The right answer is: ";
		cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}

	else
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = true;
		Quizz.NumOfRigthAnswers++;

		cout << "Right answer :-) \n";
	}

	cout << endl;

	SetColorScreen(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQeution; QuestionNumber++)
	{
		PrintTheQuestion(Quizz, QuestionNumber);
		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
		CorrectTheQuestionAnswer(Quizz, QuestionNumber);
	}

	Quizz.IsPass = (Quizz.NumOfRigthAnswers >= Quizz.NumOfWrongAnswers);

// if (Quizz.NumberOfRigthAnswers >= Quizz.NumOfWrongAnswers)
//       Quizz.IsPass = true;
// else 
//       Quizz.IsPass = false;   

}

string GetFinalReultsText(bool Pass)
{
	if (Pass)
		return "Pass :-)";
	else
		return "Fail :-(";
}

void PrintQuizzResults(stQuizz Quizz)
{
	cout << "\n";
	cout << "________________________________\n\n";
	cout << "  Final Results is " << GetFinalReultsText(Quizz.IsPass);
	cout << "\n________________________________\n\n";

	cout << "Number of Questions: " << Quizz.NumberOfQeution << endl;
	cout << "Question Level     : " << GetQuestionLevelText(Quizz.QuetionLevel) << endl;
	cout << "Operation Type     : " << GetOpTypeSymbol(Quizz.OpType) << endl;
	cout << "Number of rigth answers: " << Quizz.NumOfRigthAnswers << endl;
	cout << "Number of wrong answers: " << Quizz.NumOfWrongAnswers << endl;
	cout << "________________________________\n";
}

void PlayMathGame()
{
	stQuizz Quizz;
	Quizz.NumberOfQeution = ReadHowManyQeutions();
	Quizz.QuetionLevel = ReadQuestionLevel();
	Quizz.OpType = ReadOperationType();

	GenerateQuizzQuestions(Quizz);
	AskAndCorrectQuestionListAnswers(Quizz);

	PrintQuizzResults(Quizz);
}

void ResetScreen()
{
	system("color 0F");
	system("cls");
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		PlayMathGame();

		cout << endl << "Do you want to play again Y/N ?";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
