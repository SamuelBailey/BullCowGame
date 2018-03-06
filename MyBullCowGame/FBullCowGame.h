#pragma once
#include <string>
#include <iostream>


using FString = std::string;
using int32 = int;

// Bulls and Cows are initialised to 0
struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus
{
    OK,
    Not_Isogram,
    Not_Lowercase,
    Wrong_Length
};

class FBullCowGame
{
public:
    FBullCowGame();
    ~FBullCowGame();

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    EGuessStatus CheckGuessValid(FString Guess) const;
    FBullCowCount GetBullCowCount() const;

    void SetBullCowCount(FBullCowCount BullCowCount);
    void Reset();    
    void SubmitGuess();

    // counts bulls and cows and increments try no. assuming valid guess
    FBullCowCount SubmitGuess(FString Guess);

private:
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FBullCowCount BullCowCount;
    FString MyHiddenWord;
    
    static bool IsIsogram(FString Input);
    static bool IsLowercase(FString Input);
};