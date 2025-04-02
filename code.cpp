#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

struct ResultGame {
	int PlayerWins;
	int ComputerWins;
	int Draws;
	string FinalWiner;
};

enum enmSt_Pa_Sci
{
	Stone = 1,
	Paper = 2,
	Scissors = 3
};

enum enmRoundWinner
{
	Player = 1,
	Computer = 2,
	Draw = 3
};


enmSt_Pa_Sci Player_Selection(int Number) {

	switch (Number)
	{
	case 1:
		return Stone;
	case 2:
		return Paper;
	case 3:
		return Scissors;
	}
}
enmRoundWinner GetRoundWinner(enmSt_Pa_Sci player_Choice, enmSt_Pa_Sci computer_Choice) {

	if (player_Choice == computer_Choice) {
		return Draw;
	}
	else if (player_Choice == Paper && computer_Choice == Stone) {
		return Player;
	}
	else if (player_Choice == Stone && computer_Choice == Scissors) {
		return Player;
	}
	else if (player_Choice == Scissors && computer_Choice == Paper) {
		return Player;
	}
	else {
		return Computer;
	}
}
string GetChoice(enmSt_Pa_Sci Choice) {

	switch (Choice)
	{
	case Stone:
		return "Stone";
	case Paper:
		return "Paper";
	case Scissors:
		return "Scissors";
	}
}
string GetChoiceWinner(enmRoundWinner Choice) {

	switch (Choice)
	{
	case Player:
		return "Player";
	case Computer:
		return "Computer";
	case Draw:
		return "Draw";
	}
}

int PlayerChoiceNumber(string message) {
	int Number;
	do {
		cout << message;
		cin >> Number;
	} while (Number < 1 || Number > 3);

	return Number;
}
int RedPositiveNumber(string message) {
	int Number;
	do {
		cout << message;
		cin >> Number;
	} while (Number < 0);

	return Number;
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void PrintRoundResult(enmSt_Pa_Sci player_Choice, enmSt_Pa_Sci computer_Choice, enmRoundWinner Winner,int Counter) {

	cout << "\n";
	cout << "==============================================================" << endl;
	cout << "  Round[" << Counter << "] : " << endl;
	cout << "  Player Choice : " << GetChoice(player_Choice) << endl;
	cout << "  Computer Choice : " << GetChoice(computer_Choice) << endl;
	cout << "  Round Winner : " << GetChoiceWinner(Winner) << endl;
	cout << "==============================================================" << endl;
	cout << "\n";
}
string GetFinalWinner(int PlayerWins, int ComputerWins) {

	if (PlayerWins == ComputerWins)
		return "Draw";
	else if (PlayerWins < ComputerWins)
		return "Computer";
	else
		return "Player";
}

void PrintFinalResult(ResultGame Game) {

	int PlayerWins = Game.PlayerWins;
	int ComputerWins = Game.ComputerWins;
	int Draws = Game.Draws;

	string finalWinner = GetFinalWinner(PlayerWins, ComputerWins);

	cout << "\n";
	cout << "-------------------------[End Game]---------------------------" << endl;
	cout << "  Player Wins : " << PlayerWins << endl;
	cout << "  Computer Wins : " << ComputerWins << endl;
	cout << "  Draws : " << Draws << endl;
	cout << "  Final Winer : " << finalWinner << endl; 
	cout << "-------------------------[End Game]---------------------------" << endl;
	cout << "\n";
}

void GetColorOfScreen(enmRoundWinner Winner){

	if (Winner == Player) {
		system("color 2F");
	}
	else if (Winner == Computer) {
		system("color 4F");
	}
	else {
		system("color 6F");
	}
}

void GetResultOfRound(int player_Choice_Number, int computer_Choice_Number, int Counter, ResultGame &Game) {

	enmSt_Pa_Sci player_Choice = Player_Selection(player_Choice_Number);
	enmSt_Pa_Sci computer_Choice = Player_Selection(computer_Choice_Number);
	enmRoundWinner Winner = GetRoundWinner(player_Choice, computer_Choice);

	PrintRoundResult(player_Choice, computer_Choice, Winner, Counter);

	GetColorOfScreen(Winner);

	if (Counter == 1) {
		Game.PlayerWins = 0;
		Game.ComputerWins = 0;
		Game.Draws = 0;
	}

	if (Winner == Player) {
		Game.PlayerWins++;
	}
	else if (Winner == Computer) {
		Game.ComputerWins++;
	}
	else {
		Game.Draws++;
	}

}

void GameRound(int Counter, ResultGame &Game) {

	cout << "\n";
	cout << "----------------------------------------------------------------" << endl;
	cout << " Round [" << Counter << "] Begins: " << endl;
	int player_Choice = PlayerChoiceNumber(" your Choice : [1]: Stone, [2]: Paper, [3]: Scissors :");
	int computer_Choice = RandomNumber(1, 3);
	GetResultOfRound(player_Choice, computer_Choice, Counter,Game);
}

void PlayRounds(ResultGame &Game) {
	cout << "\n";
	cout << "----------------------------------------------------------------" << endl;
	int Rounds = RedPositiveNumber(" How many Rounds do you want to plays : ");
	cout << endl;
	for (int Counter = 1; Counter <= Rounds; Counter++) {
		GameRound(Counter, Game);
	}

}
bool isAgreeToPlay(int Number) {

	if (Number == 1)
		return true;
	else
		return false;
}
void StartGame() {
	ResultGame Game;
	int Number;
	do
	{
		PlayRounds(Game);
		PrintFinalResult(Game);
		Number = RedPositiveNumber("Do you Want to play Again : [0] ==> No , [1] ==> Yes : ");
	} while (isAgreeToPlay(Number));
	
}

<<<<<<< HEAD
int main() {
	srand((unsigned)time(NULL));

	StartGame();
}
=======
}
>>>>>>> 267f980729803c1573cd5b92e949270b0b477138
