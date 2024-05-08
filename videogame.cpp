#include <iostream>
#include <fstream>
#include <string> // Add this line for string operations

#include "videogame.h"

using namespace std;

// Constructors
VideoGame::VideoGame() : Media() {
    rating = "";
    platform = "";
    playerCount = "";
}

VideoGame::VideoGame(const string& title, const string& releaseDate, const string& genre, const string& studio,
                     const string& rating, const string& platform, const string& playerCount) :
    Media(title, releaseDate, genre, studio) {
    this->rating = rating;
    this->platform = platform;
    this->playerCount = playerCount;
}

// Setters
void VideoGame::set_rating(const string& ratingVideoGame) {
    rating = ratingVideoGame;
}

void VideoGame::set_platform(const string& platformVideoGame) {
    platform = platformVideoGame;
}

void VideoGame::set_playcount(const string& playerCountVG) {
    playerCount = playerCountVG;
}

// Getters
string VideoGame::get_rating() const {
    return rating;
}

string VideoGame::get_platform() const {
    return platform;
}

string VideoGame::get_playerCount() const {
    return playerCount;
}

// Print method
void VideoGame::printInfo() const {
    Media::printInfo();
    cout << "| Rating: ";
    cout << right << setw(49) << rating << " |" << endl;
    cout << "| Platform: ";
    cout << right << setw(47) << platform << " |" << endl;
    cout << "| # of Players: ";
    cout << right << setw(43) << playerCount << " |" << endl;
}

// Exporting to file
void VideoGame::saveToFile(ofstream& outFile) const {
    outFile << "VideoGame" << endl;
    outFile << get_Title() << endl;
    outFile << get_ReleaseDate() << endl;
    outFile << get_genre() << endl;
    outFile << get_studio() << endl;
    outFile << rating << endl;
    outFile << platform << endl;
    outFile << playerCount << endl;
}
