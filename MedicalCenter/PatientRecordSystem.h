#pragma once
#include <iostream>
#include <string>
#include "Patient.h"


class PatientRecordSystem {
private:
    Patient* head;
    Patient* tail;
    int size;

public:

    Patient* getHead() {
        return head;//getting the last added node
    }

    Patient* getTail() {
        return tail; //getting the first added node
    }

    // Constructor to initialize the linked list
    PatientRecordSystem() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
   
        
    
    // Function to add a new patient record a last node
    void addRecordSorted(int regNumber, string name, int age, string contNumber, string medicHis) {
        Patient* newPatient = new Patient(regNumber, name, age, contNumber, medicHis);
        Patient* current = head;
        
        if (patientIsAvailable(regNumber)) {
            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\tPatient is already available the system." << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            delete newPatient;
            return;
        }
        
        if (head == NULL) {
                head = newPatient;
                tail = newPatient;
        } 
        
        else if (regNumber < head->regNumber) {
                newPatient->next = head;
                head->prev = newPatient;
                head = newPatient;
        }
        
        else {
                Patient* current = head;
                while (current->next != NULL && current->next->regNumber < regNumber) {
                    current = current->next;
                }

                newPatient->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = newPatient;
                }
                else {
                    tail = newPatient;
                }

                newPatient->prev = current;
                current->next = newPatient;
         }
         size++;
    }

    // Function to delete a patient record
    void deleteRecord(int regNumber) {
        if (head == NULL) {
            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\aThere is no Record" << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            return;
        }
        Patient* current = head;

        while (current != NULL) {
            if (current->regNumber == regNumber) {
                if (current->prev != NULL) { // Delete inside a node
                    current->prev->next = current->next;
                }
                else { // Delete the first node
                    head = current->next;
                }
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                else { // Delete the last node
                    tail = current->prev;
                }
                delete current;
                size--;
                cout << endl;
                cout << "Patient " << regNumber << " deleted successfully...." << endl;
                return;
            }

            else{
                current = current->next;
            }
        }
        cout << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\tRecord not found." << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;

    }

    // Function to update a patient record
    void updateRecord(int regNumber, int newAge, string newContactNumber, string newMedicalHistory) {
        Patient* current = head;
        while (current != NULL) {
            if (current->regNumber == regNumber) {
                current->age = newAge;
                current->contactNumber = newContactNumber;
                current->medicalHistory = current->medicalHistory.append("\n").append(newMedicalHistory);
                return;
            }
            current = current->next;
        }
        cout << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\tRecord not found." << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;

    }

    // Function to search for a patient record by name
    void searchRecordByRedistationNumber(int regNo) {
        Patient* current = head;
        while (current != NULL) {
            if (current->regNumber == regNo) {
                printPatirntDetails(current);
                return;
            }
            current = current->next;
        }
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\tRecord not found." << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;

    }

    // Function to display all patient records
    void displayRecords() {
        Patient* current = head;
        if (head == NULL) {
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\aThere is no Record in the system." << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
        }

        else {
            while (current != NULL) {
                printPatirntDetails(current);
                current = current->next;
            }
        }

        
    }

    bool patientIsAvailable(int regNum) {
        Patient* current = head;

        while (current != NULL) {
            if (current->regNumber == regNum) {
                return true;
            }  
            current = current->next;
        }
        
        return false;
    }
   

    // Destructor to free memory
    ~PatientRecordSystem() {
        Patient* current = head;
        while (current != NULL) {
            Patient* temp = current;
            current = current->next;
            delete temp;
        }
    }
private:
    void printPatirntDetails(Patient* patient) {
        // Print the patient details
        cout << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Registration Number: " << patient->regNumber << endl;
        cout << "Name: " << patient->name << endl;
        cout << "Age: " << patient->age << endl;
        cout << "Contact Number: " << patient->contactNumber << endl;
        cout << "Medical History: " << patient->medicalHistory << endl;
        cout << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;

    }
};
