#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> // Add this line for vector operations
#include <string> // Add this line for string operations
#include <iomanip>

#include "film.h"
#include "television.h"
#include "videogame.h"
#include "readfromfile.h"
#include "deletemenu.h"
#include "menuchoice.h"
#include "outputline.h"
#include "viewinventory.h"
#include "addinventory.h"

using namespace std;

// Function to get current date and time as a string
string getCurrentDateTimeString() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Convert date and time to string
    stringstream dateTimeStream;
    dateTimeStream << setw(2) << setfill('0') << 1 + ltm->tm_mon << "/" << setw(2) << setfill('0') << ltm->tm_mday << "/" << 1900 + ltm->tm_year << " at "
                   << setw(2) << setfill('0') << ltm->tm_hour << ":" << setw(2) << setfill('0') << ltm->tm_min << ":" << setw(2) << setfill('0') << ltm->tm_sec;
    return dateTimeStream.str();
}

//function to write the last updated and time to the top.
// Outputs each object in the 3 vectors in the designated format for the read function
void writeToTextFile(const string& fileName, const vector<Film>& filmVec, const vector<VideoGame>& gameVec, const vector<Television>& tvShowVec) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        // Write today's date to the top of the file
        outFile << "|            Last Updated: " << getCurrentDateTimeString() << "           |" << endl << endl;

        // Write film objects to file
        for (const auto& film : filmVec) {
            film.saveToFile(outFile);
        }

        // Write video game objects to file
        for (const auto& game : gameVec) {
            game.saveToFile(outFile);
        }

        // Write TV show objects to file
        for (const auto& tvShow : tvShowVec) {
            tvShow.saveToFile(outFile);
        }

        //closes the file and notifies user that data was saved successfully
        outFile.close();
        cout << "|           Data saved to " << fileName << " successfully.           |" << endl;
        outputLine();
    } else {
        cout << "Unable to open file " << fileName << " for writing!" << endl;
    }
}

//main function
int main() {

    //new vectors to store media from media.txt
    vector<Film> filmVec;
    vector<VideoGame> gameVec;
    vector<Television> tvShowVec;

    //local variables
    int newMedia;
    int mediaChoice;
    bool end = false;

    // Read existing data from file
    readFromFile("media.txt", filmVec, gameVec, tvShowVec);

    //header for program
    outputLine();
    cout << "| ";
    cout << right << setw(36) << "MEDIA DATABASE";
    cout << setw(23) << "|" << endl;
    outputStarLine();

    //loop to run until user types exit code
    while (end == false)    {

        int menuChoice;
        string userChoice;

        //main menu header
        cout << "| ";
        cout << right << setw(34) << "MAIN MENU";
        cout << setw(25) << "|" << endl;
        outputLine();

        //main menu with corresponding option codes
        cout << "| VIEW INVENTORY -";
        cout << right << setw(43) << "1 |" << endl;
        cout << "| ADD TO INVENTORY -";
        cout << right << setw(41) << "2 |" << endl;
        cout << "| DELETE FROM INVENTORY -";
        cout << right << setw(36) << "3 |" << endl;
        cout << "| EXIT PROGRAM -";
        cout << right << setw(45) << "4 |" << endl;
        outputLine();

        //prompting user for which menu option they want to choose
        cout << "| Type option code: ";

        // Calculate the length of the placeholder space
        const int placeholderLength = 40;
        string placeholder(placeholderLength, ' ');  // Create a string of 30 spaces
        cout << placeholder << "|";

        // Move the cursor back to the space between the '+' signs
        cout << "\033[" << placeholderLength + 1 << "D";

        //user enters choice
        cin >> userChoice;

        //calling menu choice validaton fuction
        userChoice = Menu_Choice(userChoice);

        //converting validated choice to int
        menuChoice = stoi(userChoice);

        outputStarLine();

        //if the choose 1
        if (menuChoice == 1)    {
            View_Inventory(filmVec,gameVec,tvShowVec);
        }
        //if they choose 2
        else if (menuChoice == 2)   {
            Add_Inventory(filmVec,gameVec,tvShowVec);

        }
        //if they choose 3
        else if (menuChoice == 3)   {
            Delete_Menu(filmVec,gameVec,tvShowVec);

        }
        //if they choose 4, program exits
        else if (menuChoice == 4)   {
            end = true;
        }

    }

    //program footer
    cout << "| ";
    cout << right << setw(36) << "CLOSING PROGRAM";
    cout << setw(23) << "|" << endl;
    outputStarLine();

    // Alphabetize the Film vector by title
    sort(filmVec.begin(), filmVec.end(), [](const Film& a, const Film& b) {
        return a.get_Title() < b.get_Title();
    });

    // Alphabetize the VideoGame vector by title
    sort(gameVec.begin(), gameVec.end(), [](const VideoGame& a, const VideoGame& b) {
        return a.get_Title() < b.get_Title();
    });

    // Alphabetize the Television vector by title
    sort(tvShowVec.begin(), tvShowVec.end(), [](const Television& a, const Television& b) {
        return a.get_Title() < b.get_Title();
    });

    // Write updated data to the text file
    writeToTextFile("media.txt", filmVec, gameVec, tvShowVec);

    return 0;
}


