#include <iostream>
using namespace std;

int main () {
    string ssnInput;
    int menuOption;

    cout << "Welcome to the User Database!\n";
    cout << "Please enter the ssn of a user: ";
    cin >> ssnInput;
    cout << "How would you like to search for this user?\n1. Search using algorithm1\n2. Search using algorithm2\n";
    cout << "Option: ";
    cin >> menuOption;
    
    if (menuOption == 1) {
        cout << "Do algorithm1 here";
    }
    else if (menuOption == 2) {
        cout << "Do algorithm2 here";
    }
    else {
        cout << "Invalid input";
    }

    return 0;
}