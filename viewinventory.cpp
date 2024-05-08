#include <iostream>
#include <vector> // Add this line for vector operations
#include <string> // Add this line for string operations
#include <iomanip>

#include "viewinventory.h"
#include "outputline.h"
#include "menuchoice.h"

using namespace std;

//fuction to view current inventory
void View_Inventory(const vector<Film>& filmVec, const vector<VideoGame>& gameVec, const vector<Television>& tvShowVec)  {

    //local variables
    int inventoryOption;
    string userChoice;
    bool end = false;

    //header for inventory viewing
    cout << "| ";
    cout << right << setw(36) << "VIEW INVENTORY";
    cout << setw(23) << "|" << endl;

    //while loop goes until user enters exit code
    while (end == false)    {

        int mediaNumber = 1;

        //tells user which code to enter for each inventory choice
        outputLine();
        cout << "| Film -";
        cout << right << setw(53) << "1 |" << endl;
        cout << "| TV Show -";
        cout << right << setw(50) << "2 |" << endl;
        cout << "| Video Game -";
        cout << right << setw(47) << "3 |" << endl;
        cout << "| Exit -";
        cout << right << setw(53) << "4 |" << endl;
        outputLine();

        //prompts user for their choice
        cout << "| What inventory would you like to see? ";

        // Calculate the length of the placeholder space
        const int placeholderLength = 20;
        string placeholder(placeholderLength, ' ');  // Create a string of 30 spaces
        cout << placeholder << "|";

        // Move the cursor back to the space between the '+' signs
        cout << "\033[" << placeholderLength + 1 << "D";

        //user enters choice
        cin >> userChoice;

        outputStarLine();

        //calling the menu choice validation functinon
        userChoice = Menu_Choice(userChoice);

        //converting the validated choice to an int
        inventoryOption = stoi(userChoice);

        //prints all the films if they choose 1
        if (inventoryOption == 1)    {
            cout << "| ";
            cout << right << setw(30) << "FILMS";
            cout << setw(29) << "|" << endl;

            for (const auto& obj : filmVec)   {
                outputLine();
                cout << "| Film # ";
                cout << right << setw(50) << mediaNumber << " |" << endl;

                obj.printInfo();
                mediaNumber++;
            }

            outputStarLine();
            cout << "| ";
            cout << right << setw(30) << "END";
            cout << setw(29) << "|" << endl;
        }
        //prints all the tv shows if they choose 2
        else if (inventoryOption == 2)  {
            cout << "| ";
            cout << right << setw(32) << "TV SHOWS";
            cout << setw(27) << "|" << endl;

            for (const auto& obj : tvShowVec)   {
                outputLine();
                cout << "| TV Show #";
                cout << right << setw(48) << mediaNumber << " |" << endl;
                obj.printInfo();
                mediaNumber++;
            }

            outputStarLine();
            cout << "| ";
            cout << right << setw(30) << "END";
            cout << setw(29) << "|" << endl;
        }
        //prints all the video games if they choose 3
        else if (inventoryOption == 3)  {
            cout << "| ";
            cout << right << setw(33) << "VIDEO GAMES";
            cout << setw(26) << "|" << endl;

            for (const auto& obj : gameVec)   {
                outputLine();
                cout << "| Video Game #";
                cout << right << setw(45) << mediaNumber << " |" << endl;
                obj.printInfo();
                mediaNumber++;
            }

            outputStarLine();
            cout << "| ";
            cout << right << setw(30) << "END";
            cout << setw(29) << "|" << endl;
        }

        //if they choose 4, program exits to main menu
        else if (inventoryOption == 4){
            end = true;
        }
    }

}
