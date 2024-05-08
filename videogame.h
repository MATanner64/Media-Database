#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "media.h"
#include <fstream>

class VideoGame : public Media {
private:
    string rating;
    string platform;
    string playerCount;

public:
    // Constructors
    VideoGame();
    VideoGame(const string& title, const string& releaseDate, const string& genre, const string& studio,
              const string& rating, const string& platform, const string& playerCount);

    // Setters
    void set_rating(const string& ratingVideoGame);
    void set_platform(const string& platformVideoGame);
    void set_playcount(const string& playerCountVG);

    // Getters
    string get_rating() const;
    string get_platform() const;
    string get_playerCount() const;

    // Print method
    void printInfo() const override;

    // Exporting to file
    void saveToFile(ofstream& outFile) const;
};

#endif
