#include <iostream>
#include <vector> // Add this line for vector operations
#include <string> // Add this line for string operations
#include <iomanip>

#include "deletemenu.h"
#include "menuchoice.h"
#include "outputline.h"

using namespace std;

//Function to delete inventory within the selected vector
void Delete_Menu(vector<Film>& filmVec, vector<VideoGame>& gameVec, vector<Television>& tvShowVec)  {

    //local variables
    int deleteChoice;
    string userChoice;
    int itemToRemove;
    bool end = false;

    //Menu Header
    cout << "| ";
    cout << right << setw(40) << "DELETE FROM INVENTORY";
    cout << setw(19) << "|" << endl;
    outputLine();

    //While loop to keep going until user exits
    while (end == false)    {

        //outputting the 3 inventory options
        cout << "| Film -";
        cout << right << setw(53) << "1 |" << endl;
        cout << "| TV Show -";
        cout << right << setw(50) << "2 |" << endl;
        cout << "| Video Game -";
        cout << right << setw(47) << "3 |" << endl;
        cout << "| Exit -";
        cout << right << setw(53) << "4 |" << endl;
        outputLine();

        //prompting the user which one they want to delete from
        cout << "| Which inventory would you like to delete from? ";

        // Calculate the length of the placeholder space
        const int placeholderLength = 11;
        string placeholder(placeholderLength, ' ');  // Create a string of 30 spaces
        cout << placeholder << "|";

        // Move the cursor back to the space between the '+' signs
        cout << "\033[" << placeholderLength + 1 << "D";

        //user entering choice
        cin >> userChoice;
        outputLine();

        //calling the menu validation function
        userChoice = Menu_Choice(userChoice);

        //converting the validated choice to a int
        deleteChoice = stoi(userChoice);

        int mediaNumber = 1;

        //if they choose Films
        if (deleteChoice == 1)    {
            cout << "| ";
            cout << right << setw(30) << "FILMS";
            cout << setw(29) << "|" << endl;
            outputLine();

            //prints out the entries in the vector
            for (const auto& obj : filmVec)   {
                outputLine();
                cout << "| Film # ";
                cout << right << setw(50) << mediaNumber << " |" << endl;
                outputLine();
                obj.printInfo();
                mediaNumber++;
            }

            outputLine();
            //prompts the user which one they would like to delete
            cout << "| Which Film would you like to delete?                      |" << endl;
            cout << "| or type -1 to exit: ";

            // Calculate the length of the placeholder space
            const int placeholderLength = 38;
            string placeholder(placeholderLength, ' ');  // Create a string of 30 spaces
            cout << placeholder << "|";

            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength + 1 << "D";

            //user enters choice
            cin >> itemToRemove;
            outputLine();

            itemToRemove = itemToRemove - 1;

            //If their choice is a valid entry
            if (itemToRemove >= 0 && itemToRemove < filmVec.size()) {
                char yesNoChoice;

                //tells them which film they selected for deletion
                cout << "|                Film selected for deletion                 |" << endl;
                outputLine();
                filmVec[itemToRemove].printInfo();

                outputLine();
                //prompting the user are they sure?
                cout << "| Are you sure you want to delete (Y/N)? ";

                // Calculate the length of the placeholder space
                const int placeholderLength = 19;
                string placeholder(placeholderLength, ' ');  // Create a string of 30 spaces
                cout << placeholder << "|";

                // Move the cursor back to the space between the '+' signs
                cout << "\033[" << placeholderLength + 1 << "D";

                //user entering y or n
                cin >> yesNoChoice;

                outputLine();

                //if they choose yes
                if (yesNoChoice == 'y' || yesNoChoice == 'Y')   {
                    filmVec.erase(filmVec.begin() + itemToRemove);
                    cout << "|                   Inventory Removed                       |" << endl;
                    outputLine();
                }
                else {
                    outputLine();
                    cout << "| ";
                    cout << right << setw(30) << "EXITING";
                    cout << setw(29) << "|" << endl;
                    outputLine();
                    end = false;
                }

            }
            else {
                cout << "|                          EXITING                          |" << endl;
                outputLine();
                end = false;

            }

        }

        //if they choose to delete a tv show
        else if (deleteChoice == 2)  {
            cout << "| ";
            cout << right << setw(32) << "TV SHOWS";
            cout << setw(27) << "|" << endl;
            outputLine();

            //prints out all tv shows within the tv show vector
            for (const auto& obj : tvShowVec)   {
                outputLine();
                cout << "| TV Show #";
                cout << right << setw(48) << mediaNumber << " |" << endl;
                outputLine();
                obj.printInfo();
                mediaNumber++;
            }

            outputLine();
            //prmpts them which one they would like to delete
            cout << "| Which TV Show would you like to delete?                   |" << endl;
            cout << "| or type -1 to exit: ";

            // Calculate the length of the placeholder space
            const int placeholderLength = 38;
            string placeholder(placeholderLength, ' ');  // Create a string of 30 spaces
            cout << placeholder << "|";

            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength + 1 << "D";

            //user entering choice
            cin >> itemToRemove;
            outputLine();

            itemToRemove = itemToRemove - 1;


            //if its a valid choice
            if (itemToRemove >= 0 && itemToRemove < tvShowVec.size()) {
                char yesNoChoice;

                //tells them which entry is marked for deletion
                cout << "|               TV Show selected for deletion               |" << endl;
                outputLine();

                tvShowVec[itemToRemove].printInfo();

                outputLine();
                //asking them are they sure they want to delete
                cout << "| Are you sure you want to delete (Y/N)? ";

                // Calculate the length of the placeholder space
                const int placeholderLength = 19;
                string placeholder(placeholderLength, ' ');  // Create a string of 30 spaces
                cout << placeholder << "|";

                // Move the cursor back to the space between the '+' signs
                cout << "\033[" << placeholderLength + 1 << "D";

                //user entering choice
                cin >> yesNoChoice;

                outputLine();

                //if yes the entry is deleted
                if (yesNoChoice == 'y' || yesNoChoice == 'Y')   {
                    tvShowVec.erase(tvShowVec.begin() + itemToRemove);
                    cout << "|                   Inventory Removed                       |" << endl;
                    outputLine();
                }
                else {
                    outputLine();
                    cout << "| ";
                    cout << right << setw(30) << "EXITING";
                    cout << setw(29) << "|" << endl;
                    outputLine();
                    end = false;
                }

            }
            else {
                cout << "|                          EXITING                          |" << endl;
                outputLine();
                end = false;

            }
        }
        //if the user video game for deletion
        else if (deleteChoice == 3)  {

            cout << "| ";
            cout << right << setw(33) << "VIDEO GAMES";
            cout << setw(26) << "|" << endl;
            outputLine();

            //prints all the video games within the videogame vector
            for (const auto& obj : gameVec)   {
                outputLine();
                cout << "| Video Game #";
                cout << right << setw(45) << mediaNumber << " |" << endl;
                outputLine();
                obj.printInfo();
                mediaNumber++;
            }

            outputLine();
            //prompts them which one they would like to delete
            cout << "| Which Video Game would you like to remove?                |" << endl;
            cout << "| or type -1 to exit: ";

            // Calculate the length of the placeholder space
            const int placeholderLength = 38;
            string placeholder(placeholderLength, ' ');  // Create a string of 30 spaces
            cout << placeholder << "|";

            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength + 1 << "D";

            //user entering choice
            cin >> itemToRemove;
            outputLine();

            itemToRemove = itemToRemove - 1;

            //if its a valid choice within the video game vector
            if (itemToRemove >= 0 && itemToRemove < gameVec.size()) {
                char yesNoChoice;

                //tells them which one they marked for deletion
                cout << "|             Video Game selected for deletion              |" << endl;
                outputLine();

                gameVec[itemToRemove].printInfo();

                outputLine();
                //asks them if they are sure
                cout << "| Are you sure you want to delete (Y/N)? ";

                // Calculate the length of the placeholder space
                const int placeholderLength = 19;
                string placeholder(placeholderLength, ' ');  // Create a string of 30 spaces
                cout << placeholder << "|";

                // Move the cursor back to the space between the '+' signs
                cout << "\033[" << placeholderLength + 1 << "D";

                //user enters choice
                cin >> yesNoChoice;

                outputLine();

                //if yes, the entry is deleted
                if (yesNoChoice == 'y' || yesNoChoice == 'Y')   {
                    gameVec.erase(gameVec.begin() + itemToRemove);
                    cout << "|                   Inventory Removed                       |" << endl;
                    outputLine();
                }
                else {
                    outputLine();
                    cout << "| ";
                    cout << right << setw(30) << "EXITING";
                    cout << setw(29) << "|" << endl;
                    outputLine();
                    end = false;
                }

            }
            else {
                cout << "|                          EXITING                          |" << endl;
                outputLine();
                end = false;

            }
        }
        //if they select 4 for exit, the while loop is exited and the program goes back to the main menu
        else if (deleteChoice == 4){
            end = true;
        }
    }

}
