#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess(FBullCowGame& BCGame);
bool AskToPlayAgain();

int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) " << std::endl;
	std::string playAgain = "";
	std::getline(std::cin, playAgain);
	if (playAgain[0] == 'y' || playAgain[0] == 'Y')
		return true;
	return false;
}

void PrintIntro()
{
	const int WORD_LENGTH = 9;
	std::cout << "Guess the " << WORD_LENGTH << " letter word\n\n";
}

void PlayGame()
{
	FBullCowGame BCGame = FBullCowGame();
	int MaxTries = BCGame.GetMaxTries();
	std::cout << "Max tries = " << MaxTries << std::endl;

	const int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		std::string Guess = GetGuess(BCGame);
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;

	}
}

std::string GetGuess(FBullCowGame& BCGame)
{
	std::cout << "Try " << BCGame.GetCurrentTry() << std::endl;
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}