#pragma once
#include <iostream>
#include <string>

using namespace std;

class Patient {
public:
    int regNumber, age;
    string name, contactNumber, medicalHistory;
  
    Patient* prev;
    Patient* next;

    Patient() { // constructer
        regNumber = NULL;
        name = "";
        age = NULL;
        contactNumber = "";
        medicalHistory = "";
        next = NULL;
        prev = NULL;
    }

    Patient(int rgNum, string Name, int ag, string conNum, string medicHis) { // overloded constructer
        regNumber = rgNum;
        name = Name;
        age = ag;
        contactNumber = conNum;
        medicalHistory = medicHis;
        next = NULL;
        prev = NULL;
    }
};


