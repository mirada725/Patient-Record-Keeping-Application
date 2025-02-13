#pragma once
#include <iostream>
#include <string>

using namespace std;

// Validate registration number
int validateRegistaionNumber() {
    int regNo;
    bool validRegNumber = false;
    while (!validRegNumber) {
        cout << "Enter Registration Number: ";
        cin >> regNo;

        if (cin.fail()) {
            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\aInvalid registration number. Please enter a valid integer." << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            cin.clear(); // Clear the error flag on cin
            cin.ignore();// Ignore any remaining characters in the input buffer
        }else {
            validRegNumber = true;
            return regNo;
        }
    }
}

// Validate age
int validateAge() {
    int age;
    bool validAge = false;
    while (!validAge) {
        cout << "Enter Age: ";
        cin >> age;

        if (cin.fail()) {
            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\aInvalid age. Please enter a valid integer." << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            cin.clear();
            cin.ignore();
        }
        else {
            validAge = true;
            return age;
        }
    }
}

// Validate Choice
int validateChoice(int choice) {
    bool validChoice = false;
    while (!validChoice) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        else {
            validChoice = true;
            return choice;
        }
    }
}

// Validate Avalable Quientity
int validateAvalableQuientity() {
    int AvalableQuientity;
    bool validAvalableQuientity = false;
    while (!validAvalableQuientity) {
        cout << "Enter Avalable Quientity: ";
        cin >> AvalableQuientity;

        if (cin.fail()) {
            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\aInvalid avalable quientity. Please enter a valid integer." << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            cin.clear();
            cin.ignore();
        }
        else {
            validAvalableQuientity = true;
            return AvalableQuientity;
        }
    }
}

// Validate Price
int validatePrice() {
    int Price;
    bool validPrice = false;
    while (!validPrice) {
        cout << "Enter Price of a Medicine: ";
        cin >> Price;

        if (cin.fail()) {
            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\aInvalid Price. Please enter a valid integer." << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            cin.clear();
            cin.ignore();
        }
        else {
            validPrice = true;
            return Price;
        }
    }
}
