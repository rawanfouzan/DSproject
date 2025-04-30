#include "HospitalReservationSystem.h"
#include <iostream>
using namespace std;

int main() {
    HospitalReservationSystem system;
    int choice;

    do {
        // Display menu
        cout << "\n\n--- Hospital Reservation System ---\n";
        cout << "1. Register patient\n";
        cout << "2. Add reservation\n";
        cout << "3. Cancel reservation\n";
        cout << "4. Complete reservation\n";
        cout << "5. Display all reservations\n";
        cout << "6. Delete patient\n";
        cout << "7. Calculate daily income\n";
        cout << "8. Exit\n";

        cout << "Enter your choice (1-8): ";
        cin >> choice;

        if (choice < 1 || choice > 8) {
            cout << "\n❌ Invalid choice. Please enter a number between 1 and 8.\n"; // Input validation
            continue;
        }

        // Execute user choice
        switch (choice) {
            case 1: system.registerPatient(); break;
            case 2: system.addReservation(); break;
            case 3: system.cancelReservation(); break;
            case 4: system.completeReservation(); break;
            case 5: system.displayReservations(); break;
            case 6: {
                int patientId;
                cout << "\nEnter patient ID to delete: ";
                cin >> patientId;
                system.deletePatient(patientId);
                break;
            }
            case 7: {
                string date;
                cout << "\nEnter date (2025-MM-DD): ";
                cin >> date;
                system.calculateDailyIncome(date);
                break;
            }
        }
        
    } while (choice != 8); // Exit loop on user choosing 8

    return 0;}
