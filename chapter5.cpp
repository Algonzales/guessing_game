/**********************************************************************
    Program Author:         Alexander Gonzales
    Program Date:           10/12/2016
    Program Description:    Chapter 5 Assignment
**********************************************************************/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;

int main()
{
    ifstream inputFile("scores.txt");
    string name = "name";
    string name1 = "unknown";
    string name2 = "unknown";
    string name3 = "unknown";
    int playerScore = 1;
    int score;
    int score1 = 99;
    int score2 = 99;
    int score3 = 99;
    int counter = 1;
    cout << "   Welcome to the Guessing Game \n";
    cout << "   Here are the Top 3 Players \n";
    while (inputFile)
    {
        inputFile >> name >> score; //reads the data
        switch (counter)
        {
        case 1:
            name1 = name;
            score1 = score;
            cout << "       " << name << " " << score << endl;
            break;
        case 2:
            name2 = name;
            score2 = score;
            cout << "       " << name << " " << score << endl;
            break;
        case 3:
            name3 = name;
            score3 = score;
            cout << "       " << name << " " << score << endl;
            break;
        }
        counter++;
    }

    inputFile.close();


    srand(time(0));
    int number = rand() % 100 + 1;
    cout << "   Enter your name: ";
    cin >> name;
    cout << "   Guess a number between 1 and 100 \n";
    cout << number;
    int guess = -1;
    while (guess != number)
    {
        // Prompt the user to guess the number
        cout << "\n   Enter your guess: ";
        cin >> guess;
        while (cin.fail() || guess < 0 || guess > 100)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "   Please enter a guess between 1 and 100, input 0 to end game: ";
            cin >> guess;
        }

        if (guess == number)
        {
            cout << "   Yes, the number is " << number << endl;
        }
        else if (guess > number)
        {
            cout << "   Your guess is too high" << endl;
            playerScore ++;
        }

        else if (guess < number)
        {
            cout << "   Your guess is too low" << endl;
            playerScore ++;
        }
    } // End of loop

    if (playerScore <= score1)
    {
        name3 = name2;
        score3 = score2;
        name2 = name1;
        score2 = score1;
        name1 = name;
        score1 = playerScore;
    }
    else if (playerScore <= score2)
    {
        name3 = name2;
        score3 = score2;
        name2 = name;
        score2 = playerScore;
    }
    else if (playerScore <= score3)
    {
        name3 = name;
        score3 = playerScore;
    }
    ofstream outputFile ("scores.txt");
    outputFile << name1 << " " << score1 << endl;
    outputFile << name2 << " " << score2 << endl;
    outputFile << name3 << " " << score3 << endl;
    outputFile.close();

    cout << ("\n");

    cout << " Here are the new top players \n";
    counter = 1;
    ifstream inputFile2 ("scores.txt");
    while (inputFile2)
    {
        inputFile2 >> name >> score; //reads the data
        switch (counter)
        {
        case 1:
            name1 = name;
            score1 = score;
            cout << "       " << name << " " << score << endl;
            break;
        case 2:
            name2 = name;
            score2 = score;
            cout << "       " << name << " " << score << endl;
            break;
        case 3:
            name3 = name;
            score3 = score;
            cout << "       " << name << " " << score << endl;
            break;
        }
        counter++;
    }

    inputFile2.close();


    return 0;
}
