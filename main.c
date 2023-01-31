/******************************************************************
This is to certify that this project is my own work, based on my
personal efforts in studying and applying the concepts learned. I
have constructed the functions and their respective algorithms
and corresponding code by myself. The program was run, tested, and
debugged by my own efforts. I further certify that I have not
copied in part or whole or otherwise plagiarized the work of other
students and/or persons.

Angelo Richter L. Dela Cruz, DLSU ID# 12148199
******************************************************************/

/*
     Description:   Doggos, Ladders, Slides and U-turns is a turn-based
                    board game that can be played by 2 to 5 players. The
                    board is a grid of 10x10 tiles numbered from 1 to 100.
                    The game is a simple race game and the objective of
                    the game is to navigate the board from the start
                    (bottom left-most tile, marked 1) to end (top left-most
                    tile, marked 100), while being helped or hindered by
                    the objects on the board. Doggos, ladders, slides and
                    u-turns randomly appear on the board during navigation.
                    Doggos, Ladders, Slides and U-turns is a turn-based
                    board game that can be played by 2 to 5 players.
                    The board is a grid of 10x10 tiles numbered from 1 to 100.
                    The game is a simple race game and the objective of the
                    game is to navigate the board from the start (bottom
                    left-most tile, marked 1) to end (top left-most tile,
                    marked 100), while being helped or hindered by the
                    objects on the board. Doggos, ladders, slides and u-turns
                    randomly appear on the board during navigation.
     Programmed by: Angelo Richter L. Dela Cruz, S12B
     Last modified: February 05, 2022
     Version: 1.0.1
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* This function generates the board and the position of players
@param currentTileOne is the position of the player one.
@param currentTileTwo is the position of the player two.
@param currentTileThree is the position of the player three.
@param currentTileFour is the position of the player four.
@param currentTileFive is the position of the player five. */
void getBoard (int currentTileOne, int currentTileTwo, int currentTileThree, int currentTileFour, int currentTileFive);

/* This function generates the rank of the players.
Precondition: The number of players can't be more than five.
@param currentTileOne is the position of the player one.
@param currentTileTwo is the position of the player two.
@param currentTileThree is the position of the player three.
@param currentTileFour is the position of the player four.
@param currentTileFive is the position of the player five.
@param numberOfPlayers is the number of players. */
void getRank (int currentTileOne, int currentTileTwo, int currentTileThree, int currentTileFour, int currentTileFive, int numberOfPlayers);

/* This function generates the rank of the players.
Precondition: The number of players can't be more than five.
@return the number of players. */
int getNumberOfPlayers (void);

/* This function generates a random number.
Precondition: the sides can't be a negative number.
@param sides is the number of sides of the die.
@return the generated number of the die between 1 to the number of sides. */
int rollDie (int sides);

/* This function generates a random number between from the next number of the given minimum number to 10.
Precondition: the minimumSides can't be a negative number.
@param minimumSides is the minimum number that the user will get.
@return the generated number of the die between the next number of the minimum number to 10. */
int rollGreaterDie (int minimumSides);

/* This function generates a random number between from the given minimum number to 10.
Precondition: the minimumSides can't be a negative number.
@param minimumSides the minimum number that the user will get.
@return the generated number of the die between the minimum number to 10. */
int rollGreaterOrEqualDie (int minimumSides);

/* This function generates a random number between 1 to the given minimum number.
Precondition: the maximumSides can't be a negative number.
@param maximumSides is the maximum number that the user will get.
@return the generated number of the die between 1 to the minimum number. */
int rollLesserDie (int maximumSides);

/* This function generates a random sequence of the players.
Precondition: the numberOfPlayers can't be less than 2 and more than 5.
@param numberOfPlayers is the number of players.
@return the generated sequence. */
int getSequence (int numberOfPlayers);

/* This function generates a new tile if doggo is called.
@param currentTile is the current tile of the player.
@return the new tile of the player. */
int doggo (int currentTile);

/* This function generates a new tile if ladder is called.
@param currentTile is the current tile of the player.
@return the new tile of the player. */
int ladder (int currentTile);

/* This function generates a new tile if slide is called.
@param currentTile is the current tile of the player.
@return the new tile of the player. */
int slide (int currentTile);

/* This function generates a new tile if U-turn is called.
@param currentTile is the current tile of the player.
@param previousTile is the previous tile of the player before their current tile.
@return the new tile of the player. */
int uturn (int currentTile, int previousTile);

/* This function prompts the user to roll the die.
@param playerNumber is the number name of the player e.g. P1, P2, P3, P4, and P5.
@param currentTileNumber is the current tile of a player. */
void printRollDie (int playerNumber, int currentTileNumber);

/* This function determine if the assumed number is the highest
@param assumedHighestNumber is the assumed highest given number.
@param compareNumberOne is the given value to be compared with assumedHighestNumber.
@param compareNumberTwo is the given value to be compared with assumedHighestNumber.
@param compareNumberThree is the given value to be compared with assumedHighestNumber.
@param currentTileNumber is the given value to be compared with assumedHighestNumber.
@return true if the assumedHighestNumber is the highest number. */
int getHighestNumber (int assumedHighestNumber, int compareNumberOne, int compareNumberTwo, int compareNumberThree);

/* This function compiles the results of each roll.
@param playerNumber is the number name of the player e.g. P1, P2, P3, P4, and P5.
@param *previousTileNumber is the previous tile of the player before their current tile.
@param *currentTileNumber is the current tile of the player.
@param *counter is the sequence of the players to determine the next player to roll the die.
@param *doggoNumber is the count of how many doggo has the player encountered.
@param *ladderNumber is the count of how many ladder has the player encountered.
@param *slideNumber is the count of how many slide has the player encountered.
@param *uturnNumber is the count of how many U-turn has the player encountered.
@param *doggoFarthestTileNumber is the total of how many tiles does the doggo took for the specific player.
@param *ladderFarthestTileNumber is the total of how many tiles does the ladder took for the specific player.
@param *slideFarthestTileNumber is the total of how many tiles does the slide took for the specific player.
@param  *uturnFarthestTileNumber is the total of how many tiles does the U-turn took for the specific player.
*/
void getNewTile (int playerNumber, int *previousTileNumber, int *currentTileNumber, int *counter, int *doggoNumber,
                 int *ladderNumber, int *slideNumber, int *uturnNumber, int *doggoFarthestTileNumber,
                 int *ladderFarthestTileNumber, int *slideFarthestTileNumber, int *uturnFarthestTileNumber);


int main (void)
{
    time_t t;
    srand (time (&t));

    char charYesOrNoPlayAgain;
    int numberOfPlayers;

    // Shows the board
    getBoard (0, 0, 0, 0, 0);

    // Prompt the user for the number of players
    numberOfPlayers = getNumberOfPlayers();

    do
    {
        // Player 1
        int currentTileOne = 0;
        int previousTileOne = 0;
        int playerOne = 1;
        int doggoOne = 0;
        int ladderOne = 0;
        int slideOne = 0;
        int uturnOne = 0;
        int doggoFarthestTileOne = 0;
        int ladderFarthestTileOne = 0;
        int slideFarthestTileOne = 0;
        int uturnFarthestTileOne = 0;

        //Player 2
        int currentTileTwo = 0;
        int previousTileTwo = 0;
        int playerTwo = 2;
        int doggoTwo = 0;
        int ladderTwo = 0;
        int slideTwo = 0;
        int uturnTwo = 0;
        int doggoFarthestTileTwo = 0;
        int ladderFarthestTileTwo = 0;
        int slideFarthestTileTwo = 0;
        int uturnFarthestTileTwo = 0;

        // Player 3
        int currentTileThree = 0;
        int previousTileThree = 0;
        int playerThree = 3;
        int doggoThree = 0;
        int ladderThree = 0;
        int slideThree = 0;
        int uturnThree = 0;
        int doggoFarthestTileThree = 0;
        int ladderFarthestTileThree = 0;
        int slideFarthestTileThree = 0;
        int uturnFarthestTileThree = 0;

        // Player 4
        int currentTileFour = 0;
        int previousTileFour = 0;
        int playerFour = 4;
        int doggoFour = 0;
        int ladderFour = 0;
        int slideFour = 0;
        int uturnFour = 0;
        int doggoFarthestTileFour = 0;
        int ladderFarthestTileFour = 0;
        int slideFarthestTileFour = 0;
        int uturnFarthestTileFour = 0;

        // Player 5
        int currentTileFive = 0;
        int previousTileFive = 0;
        int playerFive = 5;
        int doggoFive = 0;
        int ladderFive = 0;
        int slideFive = 0;
        int uturnFive = 0;
        int doggoFarthestTileFive = 0;
        int ladderFarthestTileFive = 0;
        int slideFarthestTileFive = 0;
        int uturnFarthestTileFive = 0;

        int read_sequence;
        int counter;
        int sequenceInReverse;
        int sequenceInReverse_copy;
        char charYesOrNoDisplay;
        char charYesOrNoRanking;

        printf ("Determining sequence of players...");

        // Generates the sequence of players
        sequenceInReverse = getSequence (numberOfPlayers);
        printf ("\n");

        // This function is for the next player to be able to roll the dice.
        getchar ();

        do
        {
            // This is to retain the value of the sequence
            sequenceInReverse_copy = sequenceInReverse;

            // To determine when will the sequence end and start
            counter = numberOfPlayers;

            /* The sequence is in reverse (12345 to 54321) so that the equation
                to determine the next player will be modded until the last player is called. */
            do
            {
                // This is when the sequenceInReverse is less than 10
                if (sequenceInReverse_copy < 10)
                {
                    read_sequence = sequenceInReverse_copy;
                }
                else
                {
                    read_sequence = sequenceInReverse_copy % 10;
                    sequenceInReverse_copy = sequenceInReverse_copy / 10;
                }


                switch (read_sequence)
                {
                    // Calls player 1
                    case 1:
                        getNewTile (playerOne, &previousTileOne, &currentTileOne, &counter, &doggoOne,
                                    &ladderOne, &slideOne, &uturnOne, &doggoFarthestTileOne,
                                    &ladderFarthestTileOne, &slideFarthestTileOne, &uturnFarthestTileOne);
                        printf ("\n");
                        break;

                        // Calls player 2
                    case 2:
                        getNewTile (playerTwo, &previousTileTwo, &currentTileTwo, &counter, &doggoTwo,
                                    &ladderTwo, &slideTwo, &uturnTwo, &doggoFarthestTileTwo,
                                    &ladderFarthestTileTwo, &slideFarthestTileTwo, &uturnFarthestTileTwo);
                        printf ("\n");
                        break;

                        // Calls player 3
                    case 3:
                        getNewTile (playerThree, &previousTileThree, &currentTileThree, &counter, &doggoThree,
                                    &ladderThree, &slideThree, &uturnThree, &doggoFarthestTileThree,
                                    &ladderFarthestTileThree, &slideFarthestTileThree, &uturnFarthestTileThree);
                        printf ("\n");
                        break;

                        // Calls player 4
                    case 4:
                        getNewTile (playerFour, &previousTileFour, &currentTileFour, &counter, &doggoFour,
                                    &ladderFour, &slideFour, &uturnFour, &doggoFarthestTileFour,
                                    &ladderFarthestTileFour, &slideFarthestTileFour, &uturnFarthestTileFour);
                        printf ("\n");
                        break;

                        // Calls player 5
                    case 5:
                        getNewTile (playerFive, &previousTileFive, &currentTileFive, &counter, &doggoFive,
                                    &ladderFive, &slideFive, &uturnFive, &doggoFarthestTileFive,
                                    &ladderFarthestTileFive, &slideFarthestTileFive, &uturnFarthestTileFive);
                        printf ("\n");
                        break;
                }
                // This will end if the all the players are done rolling or if any player had reached tile 100
            } while (counter > 0 && (currentTileOne < 100 && currentTileTwo < 100 && currentTileThree < 100 && currentTileFour < 100 && currentTileFive < 100));

            // Ask the user if they want to display the board
            do
            {
                printf ("Would you like to display the board (Y/N)? ");
                scanf (" %c", &charYesOrNoDisplay);
            }
            while (charYesOrNoDisplay != 'n' && charYesOrNoDisplay != 'N' && charYesOrNoDisplay != 'y' && charYesOrNoDisplay != 'Y');

            if (charYesOrNoDisplay == 'Y' || charYesOrNoDisplay == 'y')
            {
                getBoard (currentTileOne, currentTileTwo, currentTileThree, currentTileFour, currentTileFive);
            }

            printf ("\n");

            // Ask the user if they want to display the ranking
            do
            {
                printf ("Would you like to display the ranking (Y/N)? ");
                scanf (" %c", &charYesOrNoRanking);
            }
            while (charYesOrNoRanking != 'n' && charYesOrNoRanking != 'N' && charYesOrNoRanking != 'y' && charYesOrNoRanking != 'Y');

            if (charYesOrNoRanking == 'Y' || charYesOrNoRanking == 'y')
            {
                getRank (currentTileOne, currentTileTwo, currentTileThree, currentTileFour, currentTileFive, numberOfPlayers);
            }

            printf ("\n");

            getchar ();

        } while (currentTileOne < 100 && currentTileTwo < 100 && currentTileThree < 100 && currentTileFour < 100 && currentTileFive < 100);

        // Ask the user if they want to play again
        do
        {
            printf ("Would you like to play again (Y/N)? ");
            scanf (" %c", &charYesOrNoPlayAgain);
        }
        while (charYesOrNoPlayAgain != 'n' && charYesOrNoPlayAgain != 'N' && charYesOrNoPlayAgain != 'y' && charYesOrNoPlayAgain != 'Y');

    } while (charYesOrNoPlayAgain == 'Y' || charYesOrNoPlayAgain == 'y');

    printf ("Hope you enjoyed Doggos, Ladders, Slides and U-turns! \n");
    printf ("Thank you for playing! :) \n");

    return 0;
}

void getBoard (int currentTileOne, int currentTileTwo, int currentTileThree, int currentTileFour, int currentTileFive)
{
    int numberOfRows = 10;
    int numberOfTiles = 100;

    while (numberOfRows != 0)
    {
        /*  If the number of left most tile is even,
            the columns is decreasing so the numberOfTiles is also decreasing. */
        if (numberOfTiles % 10 == 0)
        {
            for (int numberOfColumns = 1; numberOfColumns <= 10; numberOfColumns++)
            {
                /* This prints the player number on the tile instead
                    of the number of the tile if the current tile of players is equal
                    to the count of the tile. */
                if (currentTileOne == numberOfTiles || currentTileTwo == numberOfTiles || currentTileThree == numberOfTiles ||
                    currentTileFour == numberOfTiles || currentTileFive == numberOfTiles)
                {
                    printf ("   ");
                    if (currentTileOne == numberOfTiles)
                    {
                        printf ("P1");
                    }
                    if (currentTileTwo == numberOfTiles)
                    {
                        printf ("P2");
                    }
                    if (currentTileThree == numberOfTiles)
                    {
                        printf ("P3");
                    }
                    if (currentTileFour == numberOfTiles)
                    {
                        printf ("P4");
                    }
                    if (currentTileFive == numberOfTiles)
                    {
                        printf ("P5");
                    }
                }
                else
                {
                    printf ("%5d", numberOfTiles);
                }
                numberOfTiles--;
            }
            printf ("\n");
            numberOfRows--;
            numberOfTiles -= 9;
        }
            /*  If the number of left most tile is odd,
                the columns is increasing so the numberOfTiles is also increasing. */
        else
        {
            for (int numberOfColumns = 1; numberOfColumns <= 10; numberOfColumns++)
            {
                /*  This prints the player number on the tile instead
                    of the number of the tile if the current tile of players is equal
                    to the count of the tile. */
                if (currentTileOne == numberOfTiles || currentTileTwo == numberOfTiles || currentTileThree == numberOfTiles ||
                    currentTileFour == numberOfTiles || currentTileFive == numberOfTiles)
                {
                    printf ("   ");
                    if (currentTileOne == numberOfTiles)
                    {
                        printf ("P1");
                    }
                    if (currentTileTwo == numberOfTiles)
                    {
                        printf ("P2");
                    }
                    if (currentTileThree == numberOfTiles)
                    {
                        printf ("P3");
                    }
                    if (currentTileFour == numberOfTiles)
                    {
                        printf ("P4");
                    }
                    if (currentTileFive == numberOfTiles)
                    {
                        printf ("P5");
                    }
                }
                else
                {
                    printf ("%5d", numberOfTiles);
                }
                numberOfTiles++;
            }
            printf ("\n");
            numberOfRows--;
            numberOfTiles -= 11;
        }
    }
}

void getRank (int currentTileOne, int currentTileTwo, int currentTileThree, int currentTileFour, int currentTileFive, int numberOfPlayers)
{
    int playerPosition = 0;
    // Header
    printf ("  Rank");
    printf (" Player\n");

    // Prints the rank number by the incrementation of playerPosition and the player number
    do
    {
        for (int counter = 100; counter > -1; counter--)
        {
            if (counter == currentTileOne && numberOfPlayers > 0)
            {
                playerPosition++;
                numberOfPlayers--;
                printf ("%5d", playerPosition);
                printf ("    P1\n");
            }

            if (counter == currentTileTwo && numberOfPlayers > 0)
            {
                playerPosition++;
                numberOfPlayers--;
                printf ("%5d", playerPosition);
                printf ("    P2\n");
            }

            if (counter == currentTileThree && numberOfPlayers > 0)
            {
                playerPosition++;
                numberOfPlayers--;
                printf ("%5d", playerPosition);
                printf ("    P3\n");
            }

            if (counter == currentTileFour && numberOfPlayers > 0)
            {
                playerPosition++;
                numberOfPlayers--;
                printf ("%5d", playerPosition);
                printf ("    P4\n");
            }

            if (counter == currentTileFive && numberOfPlayers > 0)
            {
                playerPosition++;
                numberOfPlayers--;
                printf ("%5d", playerPosition);
                printf ("    P5\n");
            }
        }
    } while (numberOfPlayers > 0);
}

int getNumberOfPlayers (void)
{
    int numberOfPlayers;

    // Prompts the user the number of players until the user input a valid number
    do
    {
        printf ("Welcome to Doggos, Ladders, Slides and U-turns! \n");
        printf ("Please enter the number of players (2 - 5 players): ");
        scanf ("%d", &numberOfPlayers);
    }
    while (numberOfPlayers > 5 || numberOfPlayers < 2);

    return numberOfPlayers;
}

int rollDie (int sides)
{
    return (int) rand() % sides + 1;
}

int rollGreaterDie (int minimumSides)
{
    return (int) rand() % (10 - (minimumSides + 1) + 1) + (minimumSides + 1);
}

int rollGreaterOrEqualDie (int minimumSides)
{
    return (int) rand() % (10 - minimumSides + 1) + minimumSides;
}

int rollLesserDie (int maximumSides)
{
    return (int) rand() % (maximumSides - 1) + 1;
}

int getSequence (int numberOfPlayers)
{
    int counter = 0;
    int sequenceInReverse = 0;
    int diceOne = 0;
    int diceTwo = 0;
    int diceThree = 0;
    int diceFour = 0;
    int diceFive = 0;
    int sequenceOfPlayers;

    do
    {
        sequenceOfPlayers = rollDie (numberOfPlayers);
        if (sequenceOfPlayers <= numberOfPlayers)
        {
            if (sequenceOfPlayers != diceOne && sequenceOfPlayers != diceTwo && sequenceOfPlayers != diceThree && sequenceOfPlayers != diceFour && sequenceOfPlayers != diceFive)
            {
                printf ("%d", sequenceOfPlayers);

                if (counter == 0)
                {
                    sequenceInReverse = sequenceOfPlayers;
                }
                    /*  This computes for the sequence of players. This will turn the sequence in reverse
                        e.g. 54321 to 12345 */
                else if (counter > 0)
                {
                    sequenceInReverse += (pow(10, counter)) * sequenceOfPlayers;
                }

                switch (sequenceOfPlayers)
                {
                    case 1:
                        diceOne = sequenceOfPlayers;
                        break;
                    case 2:
                        diceTwo = sequenceOfPlayers;
                        break;
                    case 3:
                        diceThree = sequenceOfPlayers;
                        break;
                    case 4:
                        diceFour = sequenceOfPlayers;
                        break;
                    case 5:
                        diceFive = sequenceOfPlayers;
                        break;
                }
                counter++;
            }
        }
    } while (counter < numberOfPlayers);

    printf ("\n");

    /*  This part computes the value of their order for a specific player (e.g. Player One - 3rd)
        and prints the sequence of players in a sentence. */
    int firstPlayer = sequenceInReverse % 10;
    int secondPlayer = (sequenceInReverse / 10) % 10;
    int thirdPlayer = (sequenceInReverse / 100) % 10;
    int fourthPlayer = (sequenceInReverse / 1000) % 10;
    int fifthPlayer = (sequenceInReverse / 10000) % 10;

    if (numberOfPlayers == 2)
    {
        printf ("Player %d goes first, followed by player %d.", firstPlayer, secondPlayer);
    }
    else if (numberOfPlayers == 3)
    {
        printf ("Player %d goes first, followed by player %d, and player %d.", firstPlayer, secondPlayer, thirdPlayer);
    }
    else if (numberOfPlayers == 4)
    {
        printf ("Player %d goes first, followed by player %d, player %d, and player %d.", firstPlayer, secondPlayer, thirdPlayer, fourthPlayer);
    }
    else if (numberOfPlayers == 5)
    {
        printf ("Player %d goes first, followed by player %d, player %d, player %d, and player %d.", firstPlayer, secondPlayer, thirdPlayer, fourthPlayer, fifthPlayer);
    }

    printf ("\n");
    return sequenceInReverse;
}


int doggo (int currentTile)
{
    int newRow;
    int newColumn;
    int newTile = 0;
    int counter = 0;

    // This generates new row since the doggo can go anywhere
    newRow = rollDie (10);

    // This will determine the new tile. (The explanation is in getNewTile ())
    do
    {
        counter++;
        if (counter % 2 == 0)
        {
            newTile += 19;
        }
        else if (counter % 2 == 1)
        {
            newTile += 1;
        }
    } while (counter < newRow);

    // This generates new column since the doggo can go anywhere
    newColumn = rollDie (10);

    if (newTile % 2 == 1)
    {
        newTile += newColumn - 1;
    }
    else if (newTile % 2 == 0)
    {
        newTile -= newColumn - 1;
    }

    // This prints the result if the doggo went to a higher tile.
    if (currentTile < newTile)
    {
        printf ("A doggo is on tile %d. Yay! Please follow the doggo to tile %d (row %d, col %d). \n", currentTile, newTile, newRow, newColumn);
        return newTile;
    }
        // This prints the result if the doggo went to a lower tile.
    else if (currentTile > newTile)
    {
        printf ("A doggo is on tile %d. Sorry! You have to follow the doggo back to tile %d (row %d, col %d). \n", currentTile, newTile, newRow, newColumn);
    }
        // This prints the result if the doggo doesn't move to another tile
    else if (currentTile == newTile)
    {
        printf ("A doggo is on tile %d. Oh, the doggo didn't move. Please stay on tile %d (row %d, col %d). \n", currentTile, newTile, newRow, newColumn);
    }

    return newTile;
}

int ladder (int currentTile)
{
    int currentRow;
    int newRow;
    int newColumn;
    int newTile = 0;
    int counter = 0;

    // Determining the current row
    if (currentTile == 0)
    {
        currentRow = 0;
    }
    else
    {
        currentRow = (currentTile + 9) / 10;
    }

    /*  There is no ladder in row 10 and the ladder can only go up that's why
        I use rollGreaterDie for the current row*/
    newRow = rollGreaterDie (currentRow);
    newColumn = rollDie (10);

    // This will determine the new tile. (The explanation is in getNewTile ())
    do
    {
        counter++;
        if (counter % 2 == 0)
        {
            newTile += 19;
        }
        else if (counter % 2 == 1)
        {
            newTile += 1;
        }
    } while (counter < newRow);

    if (newTile % 2 == 1)
    {
        newTile += newColumn - 1;
    }
    else if (newTile % 2 == 0)
    {
        newTile -= newColumn - 1;
    }

    // This will print the results of the ladder.
    printf ("A ladder is on tile %d. Yay! Please climb the ladder to tile %d (row %d, col %d). \n", currentTile, newTile, newRow, newColumn);

    return newTile;
}

int slide (int currentTile)
{
    int currentRow;
    int newRow;
    int newColumn;
    int newTile = 0;
    int counter = 0;

    // Determining the current row
    if (currentTile == 0)
    {
        currentRow = 0;
    }
    else
    {
        currentRow = (currentTile + 9) / 10;
    }

    /*  There is no slide in row 1 and the slide can only go down that's why
        I use rollLesserDie for the current row*/
    newRow = rollLesserDie (currentRow);
    newColumn = rollDie (10);

    // This will determine the new tile. (The explanation is in getNewTile ())
    do
    {
        counter++;
        if (counter % 2 == 0)
        {
            newTile += 19;
        }
        else if (counter % 2 == 1)
        {
            newTile += 1;
        }
    } while (counter < newRow);

    if (newTile % 2 == 1)
    {
        newTile += newColumn - 1;
    }
    else if (newTile % 2 == 0)
    {
        newTile -= newColumn - 1;
    }

    // This will print the results of the ladder.
    printf ("A slide is on tile %d. Sorry! Please go back to tile %d (row %d, col %d). \n", currentTile, newTile, newRow, newColumn);

    return newTile;
}

int uturn (int currentTile, int previousTile)
{
    int currentRow;
    int currentColumn = 0;
    int newRow;
    int newColumn;
    int newTile;

    // If the player is in tile 0 and got U-Turn, the player would stay in Tile 0
    if (previousTile == 0)
    {
        currentRow = 0;
        currentColumn = 0;
    }
    else
    {
        currentRow = (previousTile + 9) / 10;

        // Determining the current column
        if (currentRow % 2 == 1)
        {
            currentColumn = previousTile % 10;

            if (currentColumn == 0)
            {
                currentColumn = 10;
            }
        }
        else if (currentRow % 2 == 0)
        {
            currentColumn = 11 - (previousTile % 10);

            if (currentColumn == 11)
            {
                currentColumn = 1;
            }
        }
    }

    newTile = previousTile;
    newRow = currentRow;
    newColumn = currentColumn;

    // This prints the result of the U-Turn
    if (currentTile > previousTile)
    {
        printf ("A U-turn is on tile %d. Sorry! Please go back to tile %d (row %d, col %d). \n", currentTile, newTile, newRow, newColumn);
    }
    if (currentTile < previousTile)
    {
        printf ("A U-turn is on tile %d. Yay! Please go back to tile %d (row %d, col %d). \n", currentTile, newTile, newRow, newColumn);
    }
    if (currentTile == previousTile)
    {
        printf ("A U-turn is on tile %d. Oh, Please go stay on tile %d (row %d, col %d). \n", currentTile, newTile, newRow, newColumn);
    }
    return newTile;
}

void printRollDie (int playerNumber, int currentTileNumber)
{
    // This will prompt the user to roll two dice if the user is in less than tile 91.
    if (currentTileNumber < 91)
    {
        printf ("[%d] Player %d, please roll a pair of D10 dice. [Press Enter To Continue]", currentTileNumber, playerNumber);
        getchar ();

    }
        // This will prompt the user to roll one die if the user is in row 10.
    else
    {
        printf ("[%d] Player %d, please roll the die. [Press Enter To Continue]", currentTileNumber, playerNumber);
        getchar ();
    }
}

int getHighestNumber (int assumedHighestNumber, int compareNumberOne, int compareNumberTwo, int compareNumberThree)
{
    return assumedHighestNumber >= compareNumberOne && assumedHighestNumber >= compareNumberTwo && assumedHighestNumber >= compareNumberThree;
}


void getNewTile (int playerNumber, int *previousTileNumber, int *currentTileNumber, int *counter, int *doggoNumber,
                 int *ladderNumber, int *slideNumber, int *uturnNumber, int *doggoFarthestTileNumber,
                 int *ladderFarthestTileNumber, int *slideFarthestTileNumber, int *uturnFarthestTileNumber)
{
    int getTileObject;
    int winningMove;
    int currentRow;
    int currentColumn;
    int newRow;
    int newColumn;
    int numberOfSteps;
    int numberOfSteps_copy;
    int firstDoubleDie;
    int secondDoubleDie;
    int newTile = 0;
    int tileCounter = 0;

    // This will ask the user to roll the die
    printRollDie (playerNumber, *currentTileNumber);

    *previousTileNumber = *currentTileNumber;

    // If in STARTING point
    if (*currentTileNumber == 0)
    {

        firstDoubleDie = rollDie (10);
        secondDoubleDie = rollDie (10);

        // If the player rolls a double 3
        if (firstDoubleDie == 3 && secondDoubleDie == 3)
        {
            newRow = 4;
            newColumn = 1;
        }
            // If the player rolls a double 5
        else if (firstDoubleDie == 5 && secondDoubleDie == 5)
        {
            newRow = 0;
            newColumn = 0;
        }
        else
        {
            currentRow = 0;
            currentColumn = 0;
            newRow = firstDoubleDie;
            newColumn = secondDoubleDie;
        }
    }

        // If NOT in STARTING point
    else
    {
        // Determining the current row
        currentRow = (*currentTileNumber + 9) / 10;

        // Determining the current column
        if (currentRow % 2 == 1)
        {
            currentColumn = *currentTileNumber % 10;

            if (currentColumn == 0)
            {
                currentColumn = 10;
            }
        }
        else if (currentRow % 2 == 0)
        {
            currentColumn = 11 - (*currentTileNumber % 10);

            if (currentColumn == 11)
            {
                currentColumn = 1;
            }
        }

        // Generating new row and new column if the players is in row 10
        if (currentRow == 10)
        {
            newRow = 10;
            numberOfSteps = rollDie (10);
            numberOfSteps_copy = numberOfSteps;
            newColumn = currentColumn;

            // Generating new column in accordance with the numberOfSteps generated
            while (numberOfSteps_copy > 0)
            {
                newColumn--;
                numberOfSteps_copy--;
            }

            //If the player is in row 10, generating new column but overstepped
            if (newColumn <= 0)
            {
                newColumn = abs (newColumn) + 2;

            }
        }
            //  Generating new row and column if NOT in row 10
        else
        {
            //Initial roll for double-5 and double-3
            firstDoubleDie = rollDie (10);
            secondDoubleDie = rollDie (10);

            if (firstDoubleDie == 3 && secondDoubleDie == 3)
            {
                if (currentRow >= 8)
                {
                    newRow = 10;
                    newColumn = 2;
                }
                else
                {
                    newRow = currentRow + 3;
                    newColumn = currentColumn;
                }

            }
            else if (firstDoubleDie == 5 && secondDoubleDie == 5)
            {
                newRow = currentRow;
                newColumn = currentColumn;
            }


            else
            {
                newRow = firstDoubleDie;
                newColumn = secondDoubleDie;

                /*  The program below can be activated if the
                    player is always moving forward */

                /*  Generating new row and column
                    if the current column is 1
                    and current row is 2, 4, 6, or 8
                    and also
                    Generating new row and column
                    if the current column is 10
                    and current row is 1, 3, 5, or 7 */

                /*
                if ((*currentTileNumber % 10) == 0 && ((*currentTileNumber / 10) % 2 == 0 || ((*currentTileNumber / 10) % 2) == 1))
                {
                    newRow = rollGreaterDie (currentRow);
                    newColumn = rollDie (10);
                }

                else
                {
                    newRow = rollGreaterOrEqualDie (currentRow);

                    if (newRow == currentRow)
                    {
                        if (newRow % 2 == 1)
                        {
                            newColumn = rollGreaterDie (currentColumn);
                        }
                        else if (newRow % 2 == 0)
                        {
                            newColumn = rollLesserDie (currentColumn);
                        }
                    }
                    else
                    {
                        newColumn = rollDie (10);
                    }
                } */
            }
        }
    }

    /* This will compute for the new tile. The new tile would add 19 if the tileCounter is even.
    and would add one if the tileCounter is odd. This is seen on the table where the leftmost tile
    of odd number rows ends with one while the leftmost tile of the even number rows ends with 0,
    Therefore if we add 19 to the leftmost tile of the odd number rows it results to an
    even number that ends with 0 */
    do
    {
        tileCounter++;
        if (tileCounter % 2 == 0)
        {
            newTile += 19;
        }
        else if (tileCounter % 2 == 1)
        {
            newTile += 1;
        }
    } while (tileCounter < newRow);

    /* After the new tile is computed by the number of new rows, we now know what is the leftmost
    tile. If the leftmost tile is odd, we would add the value of the new column. If the leftmost
    tile is even we would subtract the value of the new column.*/
    if (newTile % 2 == 1)
    {
        newTile += newColumn - 1;
    }
    else if (newTile % 2 == 0)
    {
        newTile -= newColumn - 1;
    }

    // This prints the result of their roll.
    if (firstDoubleDie == 3 && secondDoubleDie == 3)
    {
        printf ("You rolled %d and %d. Please proceed to tile %d (row %d, col %d). \n" , firstDoubleDie, secondDoubleDie, newTile, newRow, newColumn);
    }
    else if (firstDoubleDie == 5 && secondDoubleDie == 5)
    {
        printf ("You rolled %d and %d. You miss a turn. \nSorry! Please stay on tile %d (row %d, col %d). \n", firstDoubleDie, secondDoubleDie, newTile, newRow, newColumn);
    }
    else
    {
        if (*currentTileNumber < 91)
        {
            printf ("You rolled %d and %d. Please proceed to tile %d (row %d, col %d). \n" , newRow, newColumn, newTile, newRow, newColumn);
        }
        else if (*currentTileNumber > 90 && newTile < 100 && currentColumn > numberOfSteps)
        {
            printf ("You rolled %d. You only needed %d to reach the goal. Please proceed to tile %d (row %d, col %d). \n", numberOfSteps, (100 - newTile), newTile, newRow, newColumn);
        }
        else if (*currentTileNumber > 90 && newTile < 100 && currentColumn <= numberOfSteps)
        {
            printf ("You rolled %d. Oops! You overstep. Please go back to tile %d (%d, %d). You only needed %d to reach the goal. \n", numberOfSteps, newTile, newRow, newColumn, (100 - newTile));
        }
        else
        {
            printf ("You rolled %d. Please proceed to tile %d (row %d, col %d). \n", numberOfSteps, newTile, newRow, newColumn);
        }
    }

    *currentTileNumber = newTile;
    *counter -= 1;

    // The winning move will determine what object made the player won.
    if (*currentTileNumber == 100)
    {
        winningMove = 3;
    }

    // If the player is less than 100, they will roll the die to determine what object appeared on the tile.
    if (*currentTileNumber < 100 && (firstDoubleDie != 5 || secondDoubleDie != 5))
    {
        getTileObject = rollDie (10);

        switch (getTileObject)
        {
            // This calls the doggo.
            case 1:
                *previousTileNumber = *currentTileNumber;
                *currentTileNumber = doggo (*currentTileNumber);
                *doggoNumber += 1;
                *doggoFarthestTileNumber = *doggoFarthestTileNumber + abs (*currentTileNumber - *previousTileNumber);
                if (*currentTileNumber == 100)
                {
                    winningMove = 1;
                }
                break;
                // This calls the ladder.
            case 2:
                if (*currentTileNumber < 91)
                {
                    *previousTileNumber = *currentTileNumber;
                    *currentTileNumber = ladder (*currentTileNumber);
                    *ladderNumber += 1;
                    *ladderFarthestTileNumber = *ladderFarthestTileNumber + abs (*currentTileNumber - *previousTileNumber);
                    if (*currentTileNumber == 100)
                    {
                        winningMove = 2;
                    }
                }
                    // There's no ladder in row 10.
                else
                {
                    printf ("There is no doggo, ladder, slide nor U-turn on tile %d. \n", *currentTileNumber);
                    if (*currentTileNumber == 100)
                    {
                        winningMove = 3;
                    }
                }
                break;
                // This calls the slide.
            case 3:
                if (*currentTileNumber > 10)
                {
                    *previousTileNumber = *currentTileNumber;
                    *currentTileNumber = slide (*currentTileNumber);
                    *slideNumber += 1;
                    *slideFarthestTileNumber = *slideFarthestTileNumber + abs (*currentTileNumber - *previousTileNumber);
                }
                    // There's no slide in row 1.
                else
                {
                    printf ("There is no doggo, ladder, slide nor U-turn on tile %d. \n", *currentTileNumber);
                }
                break;
                // This calls the U-turn.
            case 4:
                *uturnFarthestTileNumber = *uturnFarthestTileNumber + abs (*currentTileNumber - *previousTileNumber);
                *currentTileNumber = uturn (*currentTileNumber, *previousTileNumber);
                *uturnNumber += 1;
                break;
                // This will inform the player that there is no object on their new tile.
            case 5 ... 10:
                printf ("There is no doggo, ladder, slide nor U-turn on tile %d. \n", *currentTileNumber);
                if (*currentTileNumber == 100)
                {
                    winningMove = 3;
                }
                break;
        }
    }

    if (*currentTileNumber == 100)
    {
        printf ("\n");
        printf ("You reached the goal! YOU WIN! \n");

        // This will print how many times the player encountered doggo.
        if (*doggoNumber == 1)
        {
            printf ("Doggo appeared %d time. \n", *doggoNumber);
        }
        else
        {
            printf ("Doggo appeared %d times. \n", *doggoNumber);
        }

        // This will print how many times the player encountered ladder.
        if (*ladderNumber == 1)
        {
            printf ("You climbed ladder %d time. \n", *ladderNumber);
        }
        else
        {
            printf ("You climbed ladders %d times. \n", *ladderNumber);
        }

        // This will print how many times the player encountered slide.
        if (*slideNumber == 1)
        {
            printf ("You rode slide %d time. \n", *slideNumber);
        }
        else
        {
            printf ("You rode slides %d times. \n", *slideNumber);
        }

        // This will print how many times the player encountered U-turn.
        if (*uturnNumber == 1)
        {
            printf ("You took U-turn %d time. \n", *uturnNumber);
        }
        else
        {
            printf ("You took U-turns %d times. \n", *uturnNumber);
        }

        // This will determine which object took the player to the farthest tile.
        if (*doggoFarthestTileNumber == 0 && *ladderFarthestTileNumber == 0 && *slideFarthestTileNumber == 0 && *uturnFarthestTileNumber == 0)
        {
            printf ("No object took you to the farthest tile. \n");
        }
        else
        {
            if (getHighestNumber (*doggoFarthestTileNumber, *ladderFarthestTileNumber, *slideFarthestTileNumber, *uturnFarthestTileNumber))
            {
                printf ("The doggo took you to the farthest tile. \n");
            }
            else if (getHighestNumber (*ladderFarthestTileNumber, *doggoFarthestTileNumber, *slideFarthestTileNumber, *uturnFarthestTileNumber))
            {
                printf ("The ladder took you to the farthest tile. \n");
            }
            else if (getHighestNumber (*slideFarthestTileNumber, *doggoFarthestTileNumber, *ladderFarthestTileNumber, *uturnFarthestTileNumber))
            {
                printf ("The slide took you to the farthest tile. \n");
            }
            else if (getHighestNumber (*uturnFarthestTileNumber, *doggoFarthestTileNumber, *ladderFarthestTileNumber, *slideFarthestTileNumber))
            {
                printf ("The U-turn took you to the farthest tile. \n");
            }
        }

        // This will determine whether winning move.
        if (winningMove == 1)
        {
            printf ("The winning move was when you followed the doggo. \n");
        }
        else if (winningMove == 2)
        {
            printf ("The winning move was when you climbed the ladder. \n");
        }
        else if (winningMove == 3)
        {
            printf ("The winning move was when you rolled the dice/die to tile 100. \n");
        }

        printf ("CONGRATULATIONS!  \n");
    }
}
