#include <iostream>
#include <time.h>
#include <string>

using namespace std;

void header()
{
  cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
  cout << "\n\tTic Tac Toe Game";
  cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
}

int aleatoryPlayer() // function to avoid that the same player starts over and over again
{
  srand((unsigned)time(NULL));

  int aleatoryPlayer = rand() % 2;

  return aleatoryPlayer;
}

int exitProgram()
{
  system("CLS");

  cout << "Bye!";

  system("CLS");

  exit(1);

  return 1;
}

void homeMenu();

int returnExitOrContinue(string playerNameX, string playerNameO, int playerXScore, int playerOScore);

void gameBoardMap() 
{
  cout << "\n\n\t[Game Map]";
  cout << "\n\t1 | 2 | 3";
  cout << "\n\t4 | 5 | 6";
  cout << "\n\t7 | 8 | 9";
}

void gameBoardMask(char gameBoard[3][3])
{
  int row, column;

  cout << "\n\n";

  for (row = 0; row < 3; row++)
  {
    for (column = 0; column < 3; column++)
    {
      gameBoard[row][column] = '-';
    }
  }
}

void displayGameBoardMask(char gameBoard[3][3])
{
  int row, column;

  cout << "\n\n";
  cout << "\t[Game Mask]\n";

  for (row = 0; row < 3; row++)
  {
    cout << "\t    ";
    for (column = 0; column < 3; column++)
    {
      cout << gameBoard[row][column];
    }
    cout << "\n";
  }
}

int checksGameBoard(char gameBoard[3][3])
{
  int row, column;

  // [0 0] [0 1] [0 2]
  // [1 0] [1 1] [1 2]
  // [2 0] [2 1] [2 2]

  // checking the rows
  for (row = 0; row < 3; row++)
  {
    if (gameBoard[row][0] == 'X' && gameBoard[row][0] == gameBoard[row][1] && gameBoard[row][1] == gameBoard[row][2])
    {
      return 1;
    }
    else if (gameBoard[row][0] == 'O' && gameBoard[row][0] == gameBoard[row][1] && gameBoard[row][1] == gameBoard[row][2])
    {
      return 2;
    }
  }

  // checking the columns
  for (column = 0; column < 3; column++)
  {
    if (gameBoard[0][column] == 'O' && gameBoard[0][column] == gameBoard[1][column] && gameBoard[1][column] == gameBoard[2][column])
    {
      return 2;
    }
    else if (gameBoard[0][column] == 'X' && gameBoard[0][column] == gameBoard[1][column] && gameBoard[1][column] == gameBoard[2][column])
    {
      return 1;
    }
  }

  // checking diagonals
  if (gameBoard[0][0] != '-' && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
  {
    if (gameBoard[0][0] == 'X')
    {
      return 1;
    }
    else if (gameBoard[0][0] == 'O')
    {
      return 2;
    }
  }

  if (gameBoard[0][2] != '-' && gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0])
  {
    if (gameBoard[0][2] == 'X')
    {
      return 1;
    }
    else if (gameBoard[0][2] == 'O')
    {
      return 2;
    }
  }

  return 0;
}

void returnOrExit()
{
  int option;

  cout << "\n\n";

  do
  {
    cout << "\n1 - To return to the menu";
    cout << "\n2 - To exit the game";

    cout << "\n\nEnter an option: ";
    cin >> option;

  } while (option < 1 || option > 2);

  if (option == 1)
  {
    homeMenu();
  }
  else
  {
    exitProgram();
  }
}

void play(string playerNameX, string playerNameO, int playerXScore, int playerOScore)
{
  char gameBoard[3][3];
  bool playerX;
  bool playerXWon = false, playerOWon = false;
  bool validPosition;
  int gameState = 1, turns = 0;
  int rowPlayed, row, columnPlayed, column;
  int positionInput;
  // [0 0] [0 1] [0 2]
  // [1 0] [1 1] [1 2]
  // [2 0] [2 1] [2 2]
  int positions[9][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
  string currentPlayer, currentSignal;

  header();

  gameBoardMask(gameBoard);

  if (aleatoryPlayer() == 1)
  {
    playerX = true;
  }
  else if (aleatoryPlayer() == 0)
  {
    playerX = false;
  }

  while (gameState == 1 && turns < 9)
  {

    system("CLS");

    header();

    cout << "\n\nScore: [X] " << playerNameX << " " << playerXScore << " x " << playerOScore << " " << playerNameO << " [O]";

    gameBoardMap();

    displayGameBoardMask(gameBoard);

    cout << "\nTurn: " << turns;

    if (playerX == true)
    {
      currentPlayer = playerNameX;
      currentSignal = 'X';
    }
    else
    {
      currentPlayer = playerNameO;
      currentSignal = 'O';
    }

    validPosition = false;

    while (validPosition == false)
    {

      cout << "\n\n[" << currentSignal << "] " << currentPlayer << " enter a position according to the map above: ";
      cin >> positionInput;

      rowPlayed = positions[positionInput - 1][0];
      columnPlayed = positions[positionInput - 1][1];

      if (gameBoard[rowPlayed][columnPlayed] == '-')
      {
        validPosition = true;

        if (playerX == true)
        {
          gameBoard[rowPlayed][columnPlayed] = 'X';
          playerX = false;
        }
        else
        {
          gameBoard[rowPlayed][columnPlayed] = 'O';
          playerX = true;
        }
      }
    }

    if (checksGameBoard(gameBoard) == 1)
    {
      playerXScore++;
      playerXWon = true;
      turns = 9;
      system("CLS");
    }
    else if (checksGameBoard(gameBoard) == 2)
    {
      playerOScore++;
      playerOWon = true;
      turns = 9;
      system("CLS");
    }

    turns++;
  }

  system("CLS");

  displayGameBoardMask(gameBoard);

  if (playerXWon == true)
  {
    cout << "\n[X] " << playerNameX << " wins!!";
  }
  else if (playerOWon == true)
  {
    cout << "\n[O] " << playerNameO << " wins!!";
  }
  else if (turns == 9 && playerXWon == false && playerOWon == false)
  {
    cout << "\nDraw!";
  }

  cout << "\n\n######End of the game######";

  returnExitOrContinue(playerNameX, playerNameO, playerXScore, playerOScore);
}

int returnExitOrContinue(string playerNameX, string playerNameO, int playerXScore, int playerOScore)
{
  int option;

  cout << "\n\n";

  do
  {

    cout << "\n1 - To keep playing";
    cout << "\n2 - To return to the menu";
    cout << "\n3 - To exit the game";

    cout << "\n\nEnter an option: ";
    cin >> option;

  } while (option < 1 || option > 3);

  if (option == 1)
  {
    play(playerNameX, playerNameO, playerXScore, playerOScore);
  }
  else if (option == 2)
  {
    homeMenu();
  }
  else
  {
    exitProgram();
  }

  return 0;
}

void homeMenu()
{
  system("CLS");

  int option;

  string playerNameX, playerNameO;

  header();

  cout << "\n\n1 - Play";
  cout << "\n2 - Instructions";
  cout << "\n3 - About";
  cout << "\n4 - Exit";

  cout << "\n\nEnter an option: ";
  cin >> option;

  system("CLS");

  char gameBoard[3][3];

  switch (option)
  {
  case 1:
    header();
    cout << "\n\nEnter the name of the player [X]: ";
    cin >> playerNameX;
    cout << "\nEnter the name of the player [O]: ";
    cin >> playerNameO;
    play(playerNameX, playerNameO, 0, 0);
    break;

  case 2:
    system("CLS");
    header();
    cout << "\n\nIn order to win the game, a player must place three of theirs marks in a horizontal, vertical \nor diagonal row.";
    returnOrExit();
    break;

  case 3:
    system("CLS");
    header();
    cout << "\n\nGame created by Vinicius Medeiros.";
    cout << "\n2020";
    returnOrExit();
    break;

  case 4:
    exitProgram();
    break;
  }
}

int main()
{
  homeMenu();

  return 0;
}