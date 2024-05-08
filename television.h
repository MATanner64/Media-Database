#ifndef TELEVISION_H
#define TELEVISION_H

#include "media.h"
#include <fstream>

class Television : public Media {
private:
    string rating;
    string tagline;
    string season;

public:
    // Constructors
    Television();
    Television(const string& title, const string& releaseDate, const string& genre, const string& studio,
               const string& rating, const string& tagline, const string& season);

    // Setters
    void set_rating(const string& ratingTV);
    void set_Tagline(const string& taglineTV);
    void set_season(const string& seasonTV);

    // Getters
    string get_rating() const;
    string get_Tagline() const;
    string get_season() const;

    // Print method
    void printInfo() const override;

    // Exporting to file
    void saveToFile(ofstream& outFile) const;
};

#endif
