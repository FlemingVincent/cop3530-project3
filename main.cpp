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

    return 0;
}