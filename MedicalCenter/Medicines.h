#pragma once

#include <iostream>
#include <string>

using namespace std;

class Medicines {
public:
    string MedicineName, ExpDate;
    int AvalableQuientity, Price;

    Medicines* next;

    Medicines() {
        MedicineName = "";
        AvalableQuientity = NULL;
        ExpDate = "";
        Price = NULL;
        next = NULL;
    }

    Medicines(string medicName, int AvalableQuint, string expdate, int pric) {
        MedicineName = medicName;
        AvalableQuientity = AvalableQuint;
        ExpDate = expdate;
        Price = pric;
        next = NULL;
    }
};

