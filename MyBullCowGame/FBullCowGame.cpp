#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{

}

void FBullCowGame::Reset()
{

}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon()
{
	return true;
}

bool FBullCowGame::CheckGuessValid(std::string guess)
{
	return true;
}

void FBullCowGame::SubmitGuess(std::string)
{
	MyCurrentTry++;
}
