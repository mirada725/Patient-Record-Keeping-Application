#pragma once
#include "Patient.h"
#include "Medicines.h"

class MedicineRecordSystem {
private:
    Medicines* head;
    Medicines* tail;
    int size;

public:
    Medicines* getHeadMedi() {
        return head;

    }

    Medicines* getTailMedi() {
        return tail;
    }

    MedicineRecordSystem() {
        head = NULL;
        tail = NULL;
        size = 0;

    }

    void AddMedicine(string medicName, int AvalableQuint, string expdate, int pric) {
        Medicines* newMedical = new Medicines(medicName, AvalableQuint, expdate, pric);

        if (MedicineIsAvailable(medicName)) {
            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\tMedicine is already add to the system." << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            delete newMedical;
            return;
        }
        
        if (head == NULL) {
            head = newMedical;
            tail = newMedical;
        }

        else {
            tail->next = newMedical;
            tail = newMedical;
        }
        size++;
    }

    void editMedicalRecode(string medicName, int NewAvalableQuientity, string NewExpDate, int NewPrice) {

        Medicines* current = head;
        while (current != NULL) {
            if (current->MedicineName == medicName) {
                current->AvalableQuientity = NewAvalableQuientity;
                current->ExpDate = NewExpDate;
                current->Price = NewPrice;
                return;
            }
            current = current->next;
        }
        cout << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t\aMedicine not found in the list" << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;

    }

    // Function to display all Medical Recode records
    void displayRecords() {
        Medicines* current = head;

        if (head == NULL) {
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\aThere is no Record in the system." << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
        }

        else {
            while (current != NULL) {
                printMedicalDetails(current);
                current = current->next;
            }
        }
    }

    bool MedicineIsAvailable(string medicName) {
        Medicines* current = head;

        while (current != NULL) {
            if (current->MedicineName == medicName) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    // Destructor to free memory
    ~MedicineRecordSystem() {
        Medicines* current = head;
        while (current != NULL) {
            Medicines* temp = current;
            current = current->next;
            delete temp;
        }
    }

private:
    // Print the patient details
    void printMedicalDetails(Medicines* medicine) {
        cout << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Medicine Name: " << medicine->MedicineName << endl;
        cout << "Avalable Quientity: " << medicine->AvalableQuientity << endl;
        cout << "Expire Date: " << medicine->ExpDate << endl;
        cout << "Price: " << medicine->Price << endl;
        cout << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;

    }
};
