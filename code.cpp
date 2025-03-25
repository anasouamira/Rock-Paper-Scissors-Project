#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;


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


enmSt_Pa_Sci Player_Selection(int Number){

	switch (Number)
	{
	case 1:
		return enmSt_Pa_Sci::Stone;
	case 2:
		return enmSt_Pa_Sci::Paper;
	case 3:
		return enmSt_Pa_Sci::Scissors;
	}
}
enmRoundWinner RoundWinner(int player_Choice_Number,int computer_Choice_Number) {

	enmSt_Pa_Sci player_Choice = Player_Selection(player_Choice_Number);
	enmSt_Pa_Sci computer_Choice = Player_Selection(computer_Choice_Number);

	if (player_Choice == computer_Choice){
		return enmRoundWinner::Draw;
	}
	else if (player_Choice == enmSt_Pa_Sci::Paper && computer_Choice == enmSt_Pa_Sci::Stone) {
		return enmRoundWinner::Player;
	}
	else if (player_Choice == enmSt_Pa_Sci::Stone && computer_Choice == enmSt_Pa_Sci::Scissors) {
		return enmRoundWinner::Player;
	}
	else if (player_Choice == enmSt_Pa_Sci::Scissors && computer_Choice == enmSt_Pa_Sci::Paper) {
		return enmRoundWinner::Player;
	}
	else {
		return enmRoundWinner::Computer;
	}
}

int ComputerChoiceNumber(){

	return RandomNumber(1, 3);
}
int PlayerChoiceNumber(string message){
	int Number;
	do {
		cout << message;
		cin >> Number;
	} while (Number>= 1 && Number <= 3);

	return Number;
}

int RandomNumber(int From, int To)
{
	// Generate a random number in the range [From, To]
	int randNum = rand() % (To - From + 1) + From;
	return randNum;  // Return the generated random number
}

void GetResultOfRound(int player_Choice, int computer_Choice, int Counter) {


}


void Round(int Counter) {

	cout << "Round ["<< Counter <<"] Begins: " << endl;
	int player_Choice = PlayerChoiceNumber("your Choice : [1]: Stone, [2]: Paper, [3]: Scissors :");
	int computer_Choice = ComputerChoiceNumber();



}