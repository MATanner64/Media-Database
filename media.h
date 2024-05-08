#ifndef MEDIA_H
#define MEDIA_H

#include <string>
using namespace std;

class Media {
private:
    string title;
    string releaseDate;
    string genre;
    string studio;

public:
    // Constructors
    Media();
    Media(const string& title, const string& releaseDate, const string& genre, const string& studio);

    // Setters
    void set_Title(const string& titleMedia);
    void set_ReleaseDate(const string& releaseDateMedia);
    void set_genre(const string& genreMedia);
    void set_studio(const string& studioMedia);

    // Getters
    string get_Title() const;
    string get_ReleaseDate() const;
    string get_genre() const;
    string get_studio() const;

    // Print method
    virtual void printInfo() const;
};

#endif

