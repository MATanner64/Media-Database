#include <iostream>
#include <string> // Add this line for string operations

#include "menuchoice.h"
#include "outputline.h"
#include "outputline.h"

using namespace std;

//function to valdiated menu choice
string Menu_Choice(string input) {

    //local variables
    string userInput = input;
    int numberTest;

    //testing the input for invalid choices and characters
    for (char c : userInput) {
        if (!isdigit(c)) {
            //output message for invalid and new input to test again
            outputLine();
            cout << "|**********************INVALID INPUT************************|" << endl;
            cout << "|       Cannot contain letters or special characters        |" << endl;
            outputLine();
            cout << "| Enter option code: ";

            // Calculate the length of the placeholder space
            const int placeholderLength = 39;
            string placeholder(placeholderLength, ' ');  // Create a string of 30 spaces
            cout << placeholder << "|";

            // Move the cursor back to the space between the '|' signs
            cout << "\033[" << placeholderLength + 1 << "D";

            cin >> userInput;

            return Menu_Choice(userInput);
        }
    }

    //converting the input to a int
    numberTest = stoi(userInput);

    //if loop to test if choice is 1,2 or 3
    if (numberTest < 1 || numberTest > 4) {
        //output message for invalid and new input to test again
        outputLine();
        cout << "|**********************INVALID INPUT************************|" << endl;
        cout << "|       Cannot contain letters or special characters        |" << endl;
        outputLine();
        cout << "| Enter option code: ";

        // Calculate the length of the placeholder space
        const int placeholderLength = 39;
        string placeholder(placeholderLength, ' ');  // Create a string of 30 spaces
        cout << placeholder << "|";

        // Move the cursor back to the space between the '|' signs
        cout << "\033[" << placeholderLength + 1 << "D";

        cin >> numberTest;
        userInput = to_string(numberTest);
        return Menu_Choice(userInput);
    }

    //line after invalid message
    outputLine();

    //converting number test int to string
    userInput = to_string(numberTest);

    return userInput;
}
