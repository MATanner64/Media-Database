#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <vector>
#include "film.h"
#include "videogame.h"
#include "television.h"

void readFromFile(const std::string& fileName, std::vector<Film>& filmVec, std::vector<VideoGame>& gameVec, std::vector<Television>& tvShowVec);

#endif // FILE_READER_H
