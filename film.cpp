#include <iostream>
#include <fstream>
#include <string> // Add this line for string operations

#include "film.h"

using namespace std;

// Constructors
Film::Film() : Media() {
    rating = "";
    director = "";
    length = "";
}

Film::Film(const string& title, const string& releaseDate, const string& genre, const string& studio,
           const string& rating, const string& director, const string& length) :
    Media(title, releaseDate, genre, studio) {
    this->rating = rating;
    this->director = director;
    this->length = length;
}

// Setters
void Film::set_rating(const string& ratingFilm) {
    rating = ratingFilm;
}

void Film::set_director(const string& directorFilm) {
    director = directorFilm;
}

void Film::set_length(const string& lengthFilm) {
    length = lengthFilm;
}

// Getters
string Film::get_rating() const {
    return rating;
}

string Film::get_director() const {
    return director;
}

string Film::get_length() const {
    return length;
}

// Print method
void Film::printInfo() const {
    Media::printInfo();
    cout << "| Rating: ";
    cout << right << setw(49) << rating << " |" << endl;
    cout << "| Director: ";
    cout << right << setw(47) << director << " |" << endl;
    cout << "| Length: ";
    cout << right << setw(49) << length << " |" << endl;
}

// Exporting to file
void Film::saveToFile(ofstream& outFile) const {
    outFile << "Film" << endl;
    outFile << get_Title() << endl;
    outFile << get_ReleaseDate() << endl;
    outFile << get_genre() << endl;
    outFile << get_studio() << endl;
    outFile << rating << endl;
    outFile << director << endl;
    outFile << length << endl;
}
