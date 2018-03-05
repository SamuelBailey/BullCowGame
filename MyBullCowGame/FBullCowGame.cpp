#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{

}

void FBullCowGame::Reset()
{

}

int FBullCowGame::GetMaxTries()
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry()
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
