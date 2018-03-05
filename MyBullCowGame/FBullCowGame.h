#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame();
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValid(std::string guess);

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
	bool IsIsogram(std::string something);
};