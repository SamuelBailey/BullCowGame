#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
    Reset();
}

FBullCowGame::~FBullCowGame()
{

}

void FBullCowGame::SetBullCowCount(FBullCowCount BullCowCount)
{
    this->BullCowCount = BullCowCount;
}

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 5;
    const FString HIDDEN_WORD = "ant";

    MyCurrentTry = 1;
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    BullCowCount = FBullCowCount();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return (int32)MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const
{
    if (BullCowCount.Bulls == GetHiddenWordLength())
        return true;
    else 
        return false;
}

EGuessStatus FBullCowGame::CheckGuessValid(FString Guess) const
{
    if (!IsIsogram(Guess)) // if the guess isn't an isogram
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (!IsLowercase(Guess)) // if the guess isn't all lowercase
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK; // TODO actual error checking
    }
}

FBullCowCount FBullCowGame::GetBullCowCount() const
{
    return this->BullCowCount;
}

void FBullCowGame::SubmitGuess()
{
    MyCurrentTry++;
}


// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // increment turn number;
    MyCurrentTry++;
    // setup a return variable
    FBullCowCount bullCowCount;
    // loop thorugh all letters int he guess

    std::string MyHiddenWordCopy = MyHiddenWord;
    std::string GuessCopy = Guess;

    // Check for bulls and remove them from the copies of the hidden word and the guess
    // increment bull count on finding a bull
    for (int32 i = 0; i < MyHiddenWordCopy.length(); i++)
    {
        if (i < GuessCopy.length())
        {
            if (MyHiddenWordCopy[i] == GuessCopy[i])
            {
                bullCowCount.Bulls++;
                MyHiddenWordCopy[i] = ' ';
                GuessCopy[i] = ' ';
            }
        }
    }
    // check for cows and remove them from the copies of the hidden word and the guess
    // increment cow count on finding a cow
    for (int32 i = 0; i < MyHiddenWordCopy.length(); i++)
    {
        for (int32 j = 0; j < GuessCopy.length(); j++)
        {
            if (i != j && MyHiddenWordCopy[i] == GuessCopy[j] && MyHiddenWord[i] != ' ' && GuessCopy[j] != ' ')
            {
                bullCowCount.Cows++;
                MyHiddenWordCopy[i] = ' ';
                GuessCopy[j] = ' ';
            }
        }
    }
    return bullCowCount;
}

bool FBullCowGame::IsIsogram(FString Input)
{
    TMap<char, bool> letterSeen;

    for (char letter : Input)
    {
        letter = tolower(letter);
        if (letterSeen[letter] == true)
            return false;
        else
            letterSeen[letter] = true;
    }
    return true;
}

bool FBullCowGame::IsLowercase(FString Input)
{
    for (char letter : Input)
    {
        if (isupper(letter))
            return false;
    }
    return true;
}
