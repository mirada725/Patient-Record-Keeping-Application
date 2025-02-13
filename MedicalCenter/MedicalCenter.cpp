#include <iostream>
#include <string>
#include "Patient.h"
#include "PatientRecordSystem.h"
#include "dataValidation.h"
#include "MedicineRecordSystem.h"
#include "Medicines.h"

using namespace std;

void Display() {
    cout << endl;
    cout << "\t\t\tPatient Record System" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t[1] Add New Record" << endl;
    cout << "\t\t[2] Delete Record by Registation Number" << endl;
    cout << "\t\t[3] Update Record" << endl;
    cout << "\t\t[4] Search Record by Registation Number" << endl;
    cout << "\t\t[5] Display All Records" << endl;

    cout << "\t\t[6] Add New Medicine" << endl;
    cout << "\t\t[7] Update Medicine by Medicine Name" << endl;
    cout << "\t\t[8] Display All Medicines" << endl;


    cout << "\t\t[9] Exit" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice: ";
}

int main() {
    PatientRecordSystem patientRecords;
    MedicineRecordSystem medicalRecords;
    int choice;

    do {
        system("cls");
        Display();

        cin >> choice;

        choice = validateChoice(choice);

        if (choice == 1) {
            int regNumber, age;
            string name, contactNumber, medicalHistory;
            cout << endl;
            do {
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                if (name == "") {
                    cout << "Please enter a valid name."  << endl;
                }
                else {
                    break;
                }
            } while (true);

            
            
            age =  validateAge();
            regNumber = validateRegistaionNumber();
            
            cout << "Enter Contact Number: ";
            cin.ignore();
            getline(cin, contactNumber);
            cout << "Enter Medical History: ";
            getline(cin, medicalHistory);

            patientRecords.addRecordSorted(regNumber, name, age, contactNumber, medicalHistory);
            cout << endl;
        }

        else if (choice == 2) {
            int regNumber;
            cout << endl;
            cout << "Enter Registration Number to Delete: ";
            cin >> regNumber;
            patientRecords.deleteRecord(regNumber);
        }

        else if (choice == 3) {
            int regNumber, newAge;
            string newMedicalHistory, newContactNumber;
            cout << endl;
            regNumber = validateRegistaionNumber();
            newAge = validateAge();

            cout << "Enter New Contact Number:";
            cin.ignore();
            getline(cin, newContactNumber);
            cout << "Enter New Medical History: ";
            getline(cin, newMedicalHistory);

            patientRecords.updateRecord(regNumber, newAge, newContactNumber, newMedicalHistory);
            cout << endl;
        }
        else if (choice == 4) {
            int regNo;
            cout << endl;
            cout << "Enter Registation Number to Search: ";
            cin.ignore();
            cin >> regNo;
            cout << endl;
            patientRecords.searchRecordByRedistationNumber(regNo);
        }
        else if (choice == 5) {
            cout << endl;
            patientRecords.displayRecords();
            cout << endl;
        }

        else if (choice == 6) {
            string MedicineName, ExpDate;
            int AvalableQuientity, Price;

            cout << endl;
            cout << "Enter Medicine: ";
            cin.ignore();
            getline(cin, MedicineName);

            AvalableQuientity = validateAvalableQuientity();

            cout << "Enter Expiration Date: ";
            cin.ignore();
            getline(cin, ExpDate);

            Price = validatePrice();

            medicalRecords.AddMedicine(MedicineName, AvalableQuientity, ExpDate, Price);
            cout << endl;
        }

        else if (choice == 7) {
            string MedicineName, ExpDate;
            int AvalableQuientity, Price;

            cout << endl;
            cout << "Enter the Name of the Medicine: ";
            cin.ignore();
            getline(cin, MedicineName);

            cout << "Enter New Quantity: ";
            cin>> AvalableQuientity;

            cout << "Enter the New Expiration Date: ";
            cin.ignore();
            getline(cin, ExpDate);

            cout << "Enter New Price: ";
            cin >> Price;

            medicalRecords.editMedicalRecode( MedicineName, AvalableQuientity, ExpDate, Price);
            cout << endl;
        }

        else if (choice == 8) {
            cout << endl;
            medicalRecords.displayRecords();
            cout << endl;
        }

        else if (choice == 9) {
            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\tExiting program." << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
            break;
            }

        else {
            cout << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\aInvalid Input. Please enter a valid Input." << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    } while (choice != 9);
    return 0;
}
