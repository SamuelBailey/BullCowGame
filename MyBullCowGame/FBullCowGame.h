#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValid(std::string guess);
	void SubmitGuess(std::string);

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
	bool IsIsogram(std::string something);
};