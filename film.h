#ifndef FILM_H
#define FILM_H

#include "media.h"
#include <fstream>

class Film : public Media {
private:
    string rating;
    string director;
    string length;

public:
    // Constructors
    Film();
    Film(const string& title, const string& releaseDate, const string& genre, const string& studio,
         const string& rating, const string& director, const string& length);

    // Setters
    void set_rating(const string& ratingFilm);
    void set_director(const string& directorFilm);
    void set_length(const string& lengthFilm);

    // Getters
    string get_rating() const;
    string get_director() const;
    string get_length() const;

    // Print method
    void printInfo() const override;

    // Exporting to file
    void saveToFile(ofstream& outFile) const;
};

#endif
