/*
 * This is the console executable that makes use of the BullCow class
 * This acts as the view in a MVC pattern, and is responsible for all user interaction.
 * For game logic, see the FBullCowGame class.
 */

#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame(FBullCowGame& BCGame);
FText GetValidGuess(FBullCowGame& BCGame);
bool AskToPlayAgain();
void PrintGameSummery(bool);

FBullCowGame BCGame = FBullCowGame();

int main()
{
    bool bPlayAgain = false;
    do {
        PrintIntro();
        PlayGame(BCGame);
        bPlayAgain = AskToPlayAgain();
    } while (bPlayAgain);

    return 0;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n) " << std::endl;
    FText playAgain = "";
    std::getline(std::cin, playAgain);
    std::cout << "\n\n";
    if (playAgain[0] == 'y' || playAgain[0] == 'Y')
        return true;
    return false;
}

void PrintIntro()
{
    std::cout << "Guess the " << BCGame.GetHiddenWordLength() << " letter word\n\n";
}

void PlayGame(FBullCowGame& BCGame)
{	
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    std::cout << "Max tries = " << MaxTries << std::endl;

    const int32 NUMBER_OF_TURNS = 5;
    int32 i = 0;

    while (BCGame.GetCurrentTry() <= MaxTries && !BCGame.IsGameWon())
    {
        FText Guess = GetValidGuess(BCGame); // TODO: Check for valid guess

        BCGame.SetBullCowCount(BCGame.SubmitGuess(Guess));
        
        //print number of bulls and cows
        std::cout << "Bulls = " << BCGame.GetBullCowCount().Bulls << ". Cows = " << BCGame.GetBullCowCount().Cows << "\n\n";
    }
    
    PrintGameSummery(BCGame.IsGameWon());
}

void PrintGameSummery(bool gameWon)
{
    if (gameWon)
    {
        std::cout << "Congratulations for choosing compare the MARKET.com\n";
    }
    else
    {
        std::cout << "Compare the MEERKAT.com, compare the MARKET.com\n";
    }
}

// loop continually until the user enters a valid guess
FText GetValidGuess(FBullCowGame& BCGame)
{
    while (true) // loop only ends when the user enters a valid status, and the function returns
    {
        // Get a guess from the user
        std::cout << "Try " << BCGame.GetCurrentTry() << std::endl;
        std::cout << "Enter your guess: ";
        FText Guess = "";
        std::getline(std::cin, Guess);

        EGuessStatus Status = BCGame.CheckGuessValid(Guess);
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word\n";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Do not repeat letters\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Guess must be lowercase\n";
                break;
            default:
                return Guess;
        }
        std::cout << std::endl;
    }
}