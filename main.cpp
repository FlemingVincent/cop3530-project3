#include <iostream>

using namespace std;

int main () {
    string ssnInput;
    int menuOption;
    bool running = true;
    bool doesExist = true;

    cout << "Welcome to the Mira Incorporated Employee Database!\n";

    while (running) {
        cout << "How would you like to search for an employee?\n";
        cout << "1. Algorithm1\n2. Algorithm2\nOption: ";
        cin >> menuOption;
        if (menuOption == 1 || menuOption == 2) {
            cout << "Please enter the SSN of a user: ";
            cin >> ssnInput;
            
            if(menuOption == 1) {
                cout << "runAlgorithm1(ssnInput)\n";
            }

            else if(menuOption == 2) {
                cout << "runAlgorithm2(ssnInput)\n";

            }
            
            if (doesExist) {
            cout << "SSN does exist\n\n"; 
            }
            else {
            cout << "SSN does not exist\n\n";
            }
        }
        else {
         cout << "\nINVALID OPTION\n\n";
        }
    }
    return 0;
}