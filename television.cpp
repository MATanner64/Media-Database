#include <iostream>
#include <fstream>
#include <string> // Add this line for string operations


#include "television.h"

using namespace std;

// Constructors
Television::Television() : Media() {
    rating = "";
    tagline = "";
    season = "";
}

Television::Television(const string& title, const string& releaseDate, const string& genre, const string& studio,
                       const string& rating, const string& tagline, const string& season) :
    Media(title, releaseDate, genre, studio) {
    this->rating = rating;
    this->tagline = tagline;
    this->season = season;
}

// Setters
void Television::set_rating(const string& ratingTV) {
    rating = ratingTV;
}

void Television::set_Tagline(const string& taglineTV) {
    tagline = taglineTV;
}

void Television::set_season(const string& seasonTV) {
    season = seasonTV;
}

// Getters
string Television::get_rating() const {
    return rating;
}

string Television::get_Tagline() const {
    return tagline;
}

string Television::get_season() const {
    return season;
}

// Print method
void Television::printInfo() const {
    Media::printInfo();
    cout << "| Rating: ";
    cout << right << setw(49) << rating << " |" << endl;
    cout << "| Tagline: ";
    cout << right << setw(48) << tagline << " |" << endl;
    cout << "| Season: ";
    cout << right << setw(49) << season << " |" << endl;
}

// Exporting to file
void Television::saveToFile(ofstream& outFile) const {
    outFile << "TV-Show" << endl;
    outFile << get_Title() << endl;
    outFile << get_ReleaseDate() << endl;
    outFile << get_genre() << endl;
    outFile << get_studio() << endl;
    outFile << rating << endl;
    outFile << tagline << endl;
    outFile << season << endl;
}
