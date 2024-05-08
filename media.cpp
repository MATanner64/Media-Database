#include <iostream>
#include <vector> // Add this line for vector operations
#include <string> // Add this line for string operations
#include <iomanip>

#include "media.h"

using namespace std;

// Default Constructor
Media::Media() {
    // Initialize variables
    title = "";
    releaseDate = "";
    genre = "";
    studio = "";
}

// Parameterized Constructor
Media::Media(const string& title, const string& releaseDate, const string& genre, const string& studio) {
    // Initialize variables with provided values
    this->title = title;
    this->releaseDate = releaseDate;
    this->genre = genre;
    this->studio = studio;
}

// Setters
void Media::set_Title(const string& titleMedia) {
    title = titleMedia;
}

void Media::set_ReleaseDate(const string& releaseDateMedia) {
    releaseDate = releaseDateMedia;
}

void Media::set_genre(const string& genreMedia) {
    genre = genreMedia;
}

void Media::set_studio(const string& studioMedia) {
    studio = studioMedia;
}

// Getters
string Media::get_Title() const {
    return title;
}

string Media::get_ReleaseDate() const {
    return releaseDate;
}

string Media::get_genre() const {
    return genre;
}

string Media::get_studio() const {
    return studio;
}

// Print method
void Media::printInfo() const {
    cout << "| Title: ";
    cout << right << setw(50) << title << " |" << endl;
    cout << "| Release Date: ";
    cout << right << setw(43) << releaseDate << " |" << endl;
    cout << "| Genre: ";
    cout << right << setw(50) << genre << " |" << endl;
    cout << "| Studio: ";
    cout << right << setw(49) << studio << " |" << endl;
}
