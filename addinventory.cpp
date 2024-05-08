#include <iostream>
#include <vector> // Add this line for vector operations
#include <string> // Add this line for string operations
#include <iomanip>

#include "addinventory.h"
#include "outputline.h"
#include "menuchoice.h"

using namespace std;

//function to add inventory
void Add_Inventory(vector<Film>& filmVec, vector<VideoGame>& gameVec, vector<Television>& tvShowVec)    {

    //local variables
    string currTitle, currGenre, currStudio, currRating, currPlatform, currDirector, currTagline;
    string currReleaseDate, currPlayerCount, currLength, currSeason;

    string year;
    int mediaChoice;
    string userChoice;
    bool end = false;

    //current new objects to add
    Film currFilm;
    Television currTVShow;
    VideoGame currVideoGame;

    //header for adding to inventory
    cout << "| ";
    cout << right << setw(36) << "ADD TO INVENTORY";
    cout << setw(23) << "|" << endl;
    outputLine();

    //runs loop until user enters exit code
    while (end == false)    {
        cout << "| Film -";
        cout << right << setw(53) << "1 |" << endl;
        cout << "| TV Show -";
        cout << right << setw(50) << "2 |" << endl;
        cout << "| Video Game -";
        cout << right << setw(47) << "3 |" << endl;
        cout << "| Exit -";
        cout << right << setw(53) << "4 |" << endl;
        outputLine();

        //prompts them for which media they would like to add
        cout << "| What kind of media would you like to add? ";

        // Calculate the length of the placeholder space
        int placeholderLength = 16;
        string placeholder(placeholderLength, ' ');  // Create a string of 30 spaces
        cout << placeholder << "|";

        // Move the cursor back to the space between the '+' signs
        cout << "\033[" << placeholderLength + 1 << "D";

        //user enters choice
        cin >> userChoice;
        outputLine();

        //calls menu choice validation function
        userChoice = Menu_Choice(userChoice);

        //converts the validated choice to an int
        mediaChoice = stoi(userChoice);

        //if they want to add a film
        if (mediaChoice == 1) {
            //Enter title
            cout << "| Enter Film title: ";

            // Calculate the length of the placeholder space
            int placeholderLength = 40;
            string placeholder(placeholderLength, ' ');  // Create a string of 40 spaces
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            cin.ignore(); // Clear the newline character left in the buffer
            getline(cin, currTitle);

            cout << "| Enter Release Year: ";

            placeholder = string(38, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            cin >> currReleaseDate;
            cin.ignore(); // Clear the newline character left in the buffer

            cout << "| Enter Film Genre: ";

            placeholder = string(40, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            getline(cin, currGenre);

            cout << "| Enter Film Studio: ";

            placeholder = string(39, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            getline(cin, currStudio);

            cout << "| Enter Film Rating: ";

            placeholder = string(39, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            getline(cin, currRating);

            cout << "| Enter Film Director: ";

            placeholder = string(37, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            getline(cin, currDirector);

            cout << "| Enter Film Length: ";

            placeholder = string(39, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            cin >> currLength;

            outputLine();

            //setts all variables to curr film
            currFilm.set_Title(currTitle);
            currFilm.set_ReleaseDate(currReleaseDate);
            currFilm.set_genre(currGenre);
            currFilm.set_studio(currStudio);
            currFilm.set_rating(currRating);
            currFilm.set_director(currDirector);
            currFilm.set_length(currLength);

            //adds the new film to the film vector
            filmVec.push_back(currFilm);
        }
        //if user wants to add a new tv show
        else if (mediaChoice == 2)  {
            cout << "| Enter TV Show title: ";

            // Calculate the length of the placeholder space
            int placeholderLength = 37;
            string placeholder(placeholderLength, ' ');  // Create a string of 40 spaces
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            cin.ignore(); // Clear the newline character left in the buffer
            getline(cin, currTitle);

            cout << "| Enter Release Year: ";

            placeholder = string(38, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            cin >> currReleaseDate;

            cin.ignore(); // Clear the newline character left in the buffer

            cout << "| Enter TV Show Genre: ";

            placeholder = string(37, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            getline(cin, currGenre);

            cout << "| Enter TV Show Studio: ";

            placeholder = string(36, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            getline(cin, currStudio);

            cout << "| Enter TV Show Rating: ";

            placeholder = string(36, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            getline(cin, currRating);

            cout << "| Enter TV Show Tagline: ";

            placeholder = string(35, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            getline(cin, currTagline);

            cout << "| Enter Number of Season: ";

            placeholder = string(34, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            cin >> currSeason;

            outputLine();

            //sets the variables for the current tv show being made
            currTVShow.set_Title(currTitle);
            currTVShow.set_ReleaseDate(currReleaseDate);
            currTVShow.set_genre(currGenre);
            currTVShow.set_studio(currStudio);
            currTVShow.set_rating(currRating);
            currTVShow.set_Tagline(currTagline);
            currTVShow.set_season(currSeason);

            //adds the current tv show to the tv show vector
            tvShowVec.push_back(currTVShow);

        }

        //if the user wants to add a new video game
        else if (mediaChoice == 3)  {
            cout << "| Enter Video Game title: ";

            // Calculate the length of the placeholder space
            int placeholderLength = 34;
            string placeholder(placeholderLength, ' ');  // Create a string of 40 spaces
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            cin.ignore(); // Clear the newline character left in the buffer
            getline(cin, currTitle);

            cout << "| Enter Release Year: ";

            placeholder = string(38, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            cin >> currReleaseDate;

            cin.ignore(); // Clear the newline character left in the buffer

            cout << "| Enter Video Game Genre: ";

            placeholder = string(34, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            getline(cin, currGenre);

            cout << "| Enter Video Game Studio: ";

            placeholder = string(33, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            getline(cin, currStudio);

            cout << "| Enter Video Game Rating: ";

            placeholder = string(33, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            getline(cin, currRating);

            cout << "| Enter Video Game Platform: ";

            placeholder = string(31, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            getline(cin, currPlatform);

            cout << "| Enter Number of Players: ";

            placeholder = string(33, ' ');
            cout << placeholder << "|";
            // Move the cursor back to the space between the '+' signs
            cout << "\033[" << placeholderLength - 3 << "D";

            cin >> currPlayerCount;

            outputLine();

            //adds the variables to the current video game being made
            currVideoGame.set_Title(currTitle);
            currVideoGame.set_ReleaseDate(currReleaseDate);
            currVideoGame.set_genre(currGenre);
            currVideoGame.set_studio(currStudio);
            currVideoGame.set_rating(currRating);
            currVideoGame.set_platform(currPlatform);
            currVideoGame.set_playcount(currPlayerCount);

            //adds the new video game to the video game vector
            gameVec.push_back(currVideoGame);

        }
        //if the user choose the exit code, the loop ends and the program goes back to the main menu
        else if (mediaChoice == 4){
            end = true;
        }
    }

}
