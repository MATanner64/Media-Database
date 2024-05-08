#include <iostream>
#include <iomanip>

#include "outputline.h"

using namespace std;

void outputLine() {
    //added long line to separate input and output
    cout << setfill('-') << setw(62) << " " << endl;
    //setting the fill back to blank spaces
    cout << setfill(' ');
}

void outputStarLine() {
    //added long line to separate input and output
    cout << setfill('*') << setw(62) << " " << endl;
    //setting the fill back to blank spaces
    cout << setfill(' ');
}
