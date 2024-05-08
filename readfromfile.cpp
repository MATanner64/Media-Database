#include <iostream>
#include <vector> // Add this line for vector operations
#include <string> // Add this line for string operations

#include "readfromfile.h"

using namespace std;

//function to pull info saved in txt file and populate the various vectors for the classes
void readFromFile(const string& fileName, vector<Film>& filmVec, vector<VideoGame>& gameVec, vector<Television>& tvShowVec) {
    ifstream inFile(fileName);
    string line;
    bool isFirstLine = true; // Flag to indicate if it's the first line (date line)

    if (inFile.is_open()) {
        while (getline(inFile, line)) {

            if (isFirstLine) {
                isFirstLine = false; // Skip the first line (LAST UPDATED: date line)
                cout << line << endl; // Print out the date
                continue;
            }

            if (line == "Film") {
                // Read film-specific data
                string title, genre, studio, rating, director;
                string releaseDate, length;

                getline(inFile, title);
                inFile >> releaseDate >> ws; // Clear the newline character left in the buffer
                getline(inFile, genre);
                getline(inFile, studio);
                getline(inFile, rating);
                getline(inFile, director);
                inFile >> length >> ws;

                // Create and store Film object
                Film film;
                film.set_Title(title);
                film.set_ReleaseDate(releaseDate);
                film.set_genre(genre);
                film.set_studio(studio);
                film.set_rating(rating);
                film.set_director(director);
                film.set_length(length);

                //adding the current film to the film vector
                filmVec.push_back(film);

            } else if (line == "VideoGame") {
                // Read video game-specific data
                string title, genre, studio, rating, platform;
                string releaseDate, playerCount;

                getline(inFile, title);
                inFile >> releaseDate >> ws;
                getline(inFile, genre);
                getline(inFile, studio);
                getline(inFile, rating);
                getline(inFile, platform);
                inFile >> playerCount >> ws;

                // Create and store VideoGame object
                VideoGame game;
                game.set_Title(title);
                game.set_ReleaseDate(releaseDate);
                game.set_genre(genre);
                game.set_studio(studio);
                game.set_rating(rating);
                game.set_platform(platform);
                game.set_playcount(playerCount);

                //adding the current game to the game vector
                gameVec.push_back(game);

            } else if (line == "TV-Show") {
                // Read tv show-specific data
                string title, genre, studio, rating, tagline;
                string releaseDate, season;

                getline(inFile, title);
                inFile >> releaseDate >> ws;
                getline(inFile, genre);
                getline(inFile, studio);
                getline(inFile, rating);
                getline(inFile, tagline);
                inFile >> season >> ws;

                // Create and store TVShow object
                Television tvShow;
                tvShow.set_Title(title);
                tvShow.set_ReleaseDate(releaseDate);
                tvShow.set_genre(genre);
                tvShow.set_studio(studio);
                tvShow.set_rating(rating);
                tvShow.set_Tagline(tagline);
                tvShow.set_season(season);

                //adding the current tv show to the tv show vector
                tvShowVec.push_back(tvShow);
            }
        }

        // Check EOF after the while loop
        if (inFile.eof()) {
            inFile.close();
        } else {
            cout << "Error reading from file." << endl;
        }
    } else {
        cout << "Unable to open file " << fileName << " for reading!" << endl;
    }
}
