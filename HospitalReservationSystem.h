#ifndef HOSPITAL_RESERVATION_SYSTEM_H
#define HOSPITAL_RESERVATION_SYSTEM_H

#include "Patient.h"
#include "Reservation.h"
using namespace std;

class HospitalReservationSystem {
private:
    Patient* patientHead;        // Head pointer for patients linked list
    Reservation* reservationHead;// Head pointer for reservations linked list
    int nextPatientId;           // Counter for assigning patient IDs
    int nextReservationId;       // Counter for assigning reservation IDs

public:
    // Constructor initializes pointers and starting ID values
    HospitalReservationSystem() {
        patientHead = nullptr;
        reservationHead = nullptr;
        nextPatientId = 1000;
        nextReservationId = 2000;
    }

    // Register a new patient and store their information
    void registerPatient() {
        Patient* newPatient = new Patient();       // Create new patient node
        newPatient->id = nextPatientId++;          // Assign patient ID and increment

        cout << "\nEnter patient's full name: ";   
        cin.ignore();
        getline(cin, newPatient->fullName);        // Get full name with spaces

        while (true) {                              // Loop until valid birth date
            cout << "\nEnter birth date (e.g., 1990-01-01): ";
            cin >> newPatient->birthDate;
            cin.clear();
            cin.ignore(1000, '\n');

            // Check formatting and basic structure of date
            if (newPatient->birthDate.size() == 10 &&
                newPatient->birthDate[4] == '-' &&
                newPatient->birthDate[7] == '-' &&
                
                isdigit(newPatient->birthDate[0]) && isdigit(newPatient->birthDate[1]) &&
                isdigit(newPatient->birthDate[2]) && isdigit(newPatient->birthDate[3]) &&
                isdigit(newPatient->birthDate[5]) && isdigit(newPatient->birthDate[6]) &&
                isdigit(newPatient->birthDate[8]) && isdigit(newPatient->birthDate[9])) {

                
                int year = stoi(newPatient->birthDate.substr(0, 4));   // Extract year
                int month = stoi(newPatient->birthDate.substr(5, 2)); // Extract month
                int day = stoi(newPatient->birthDate.substr(8, 2));   // Extract day

                if (year >= 1900 && year <= 2100 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
                    break; // Exit loop if date is valid
                }
            }
            cout << "\n❌ Invalid date format. Please enter birth date like 1990-01-01."; // Error message
        }

        int choice;

        // Loop to validate gender input
        do {
            cout << "\nEnter gender (1 for Female, 2 for Male): ";
            cin >> choice;

            if (choice != 1 && choice != 2) {
                cout << "\n❌ Invalid input. Please enter 1 for Female or 2 for Male.";
            }
        } while (choice != 1 && choice != 2);

        newPatient->gender = (choice == 1) ? "Female" : "Male"; // Assign gender based on input

        // Loop to validate marital status input
        do {
            cout << "\nEnter marital status (1 for Married, 2 for Single): ";
            cin >> choice;

            if (choice != 1 && choice != 2) {
                cout << "\n❌ Invalid input. Please enter 1 for Married or 2 for Single.";
            }
        } while (choice != 1 && choice != 2);

        newPatient->maritalStatus = (choice == 1) ? "Married" : "Single"; // Assign marital status based on input

        // Loop to validate phone number format
        do {
            cout << "\nEnter phone number (e.g., +9665xxxxxxxx): ";
            cin >> newPatient->phone;

            // Check if number starts with +966 and is 13 characters long
            if (newPatient->phone.substr(0, 4) != "+966" || newPatient->phone.length() != 13) {
                cout << "\n❌ Invalid phone number. It must start with +966 and be 13 characters long.";
            } else {
                break; // Valid phone number
            }

        } while (true);

        newPatient->next = patientHead; // Add patient to the beginning of the list
        patientHead = newPatient;

        cout << "\nNew patient registered with ID: " << newPatient->id << endl; // Show assigned patient ID
    }

    // Search for a patient by ID
    Patient* findPatientById(int id) {
        Patient* current = patientHead;
        while (current) {
            if (current->id == id)
                return current; // Return the patient if ID matches
            current = current->next;
        }
        return nullptr; // Not found
    }

    // Start of function to create a reservation
    void addReservation() {
        int patientId;
        cout << "\nEnter patient ID for reservation: ";

        cin >> patientId;

        Patient* patient = findPatientById(patientId); // Search for patient by ID
        if (!patient) {
            cout << "\nPatient ID not found."; // Patient doesn't exist
            return;
        }

        Reservation* newRes = new Reservation(); // Create new reservation node

        newRes->patientId = patientId; // Link reservation to patient

        int departmentChoice;
        cout << "\nEnter department \n 1: Neurology \n 2: Cardiology  \n 3: Dermatology  \n 4: Pediatrics  \n 5: General  \n 6: Dentistry : ";
        cin >> departmentChoice;

        // Assign department name based on user choice
        switch (departmentChoice) {
            case 1: newRes->department = "Neurology"; break;
            case 2: newRes->department = "Cardiology"; break;
            case 3: newRes->department = "Dermatology"; break;
            case 4: newRes->department = "Pediatrics"; break;
            case 5: newRes->department = "General"; break;
            case 6: newRes->department = "Dentistry"; break;
            default:
                cout << "\nInvalid department choice!";
                delete newRes; // Cancel creation if department is invalid
                return;
        }

        string date;
        while (true) { // Loop until a valid date is entered
            cout << "\nEnter date in Gregorian (2025-MM-DD): ";
            cin >> date;
            cin.clear();
            cin.ignore(1000, '\n');

            // Validate date structure
            if (date.size() == 10 && date[4] == '-' && date[7] == '-' &&
                isdigit(date[0]) && isdigit(date[1]) && isdigit(date[2]) && isdigit(date[3]) &&
                isdigit(date[5]) && isdigit(date[6]) && isdigit(date[8]) && isdigit(date[9])) {

                int year = stoi(date.substr(0, 4));
                int month = stoi(date.substr(5, 2));
                int day = stoi(date.substr(8, 2));

                if (year >= 2025 && year <= 2100 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
                    newRes->date = date;  // Assign validated date
                    break;
                }
            }
            cout << "\n❌ Invalid date. Please enter a valid date like 2025-04-18."; // Error message for invalid date
        }

        while (true) { // Loop until valid time is entered
            cout << "\nEnter time (e.g., 14:30): ";
            cin >> newRes->time;
            cin.clear();
            cin.ignore(1000, '\n');

            // Validate time format
            if (newRes->time.size() == 5 && newRes->time[2] == ':' &&
                isdigit(newRes->time[0]) && isdigit(newRes->time[1]) &&
                isdigit(newRes->time[3]) && isdigit(newRes->time[4])) {

                int hour = stoi(newRes->time.substr(0, 2));
                int minute = stoi(newRes->time.substr(3, 2));

                if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59) {
                    break; // Valid time
                }
            }
            cout << "\n❌ Invalid time format or range. Please use HH:MM (e.g., 14:30) and valid time.";
        }

        Reservation* current = reservationHead;
        while (current != nullptr) {
            // Check if this patient already has a confirmed reservation at this date/time
            // OR if another reservation exists for the same department at same date/time
            if ((current->patientId == patientId && current->date == newRes->date &&
                 current->time == newRes->time && current->status == "Confirmed") ||
                (current->date == newRes->date && current->time == newRes->time &&
                 current->department == newRes->department && current->status == "Confirmed")) {

                cout << "\n❌ This time slot is already taken (either by same patient or department).";
                delete newRes;
                return;
            }
            current = current->next;

        }

        int confirmPayment;
        cout << "\nReservation fee is 150 SAR.\nIt must be paid now to confirm the appointment.\nIt is non-refundable." << endl;
        cout << "\nDid the patient pay the reservation fee? (1 = Yes / 2 = No): ";
        cin >> confirmPayment;

        if (confirmPayment != 1) {
            cout << "\nReservation was not created because the patient did not pay the required fee."; // Don't create if unpaid
            delete newRes;
            return;
        }

        newRes->totalCost = 150;                    // Set base reservation cost
        newRes->status = "Confirmed";               // Set status as confirmed
        newRes->id = nextReservationId++;           // Assign unique reservation ID
        newRes->next = reservationHead;             // Insert at head of reservation list
        reservationHead = newRes;

        cout << "\nReservation confirmed with ID: " << newRes->id << endl; // Confirmation message
    }

    // Display all reservations with their details
    void displayReservations() {
        Reservation* current = reservationHead;
        cout << "\n--- All Reservations ---\n";
        while (current) {
            cout << "Reservation ID: " << current->id
                 << "\n | Patient ID: " << current->patientId
                 << "\n | Department: " << current->department
                 << "\n | Date: " << current->date
                 << "\n | Time: " << current->time
                 << "\n | Status: " << current->status 
                 << "\n | Bill: " << current->totalCost << " SAR"
                 << endl;
            cout << "-----------------------------------------------\n";
            current = current->next;
        }

    }

    // Function to delete a patient and all their related reservations
    void deletePatient(int patientId) {
        Patient* currentPatient = patientHead;
        Patient* prevPatient = nullptr;

        while (currentPatient != nullptr) {
            if (currentPatient->id == patientId) {
                Reservation* currentRes = reservationHead;
                Reservation* prevRes = nullptr;

                while (currentRes != nullptr) {
                    // Find all reservations linked to this patient and delete them
                    if (currentRes->patientId == patientId) {
                        if (prevRes == nullptr) {
                            reservationHead = currentRes->next;
                        } else {
                            prevRes->next = currentRes->next;
                        }
                        Reservation* tempRes = currentRes;
                        currentRes = currentRes->next;
                        delete tempRes;
                    } else {
                        prevRes = currentRes;
                        currentRes = currentRes->next;
                    }
                }

                // Now delete the patient from the patient list
                if (prevPatient == nullptr) {
                    patientHead = currentPatient->next;
                } else {
                    prevPatient->next = currentPatient->next;
                }
                delete currentPatient;
                cout << "\nPatient and their reservations have been successfully deleted";
                return;
            }
            prevPatient = currentPatient;
            currentPatient = currentPatient->next;
        }

        cout << "\n❌ Patient not found. Please make sure the Patient ID is correct";
    }

    // Cancel a reservation by ID
    void cancelReservation() {
        int resId;
        cout << "\nEnter reservation ID to cancel: ";
        cin >> resId;

        Reservation* current = reservationHead;
        while (current) {
            if (current->id == resId) {
                if (current->status == "Cancelled") {
                    cout << "\nReservation is already cancelled."; // Already cancelled
                    return;
                }
                if (current->status == "Completed") {
                    cout << "\nCannot cancel a completed reservation."; // Can't cancel after completion
                    return;
                }

                current->status = "Cancelled"; // Set status to cancelled
                cout << "\nReservation cancelled successfully.";
                return;
            }
            current = current->next;
        }

        cout << "\n❌ Reservation ID not found."; // No matching ID
    }

    // Mark a reservation as completed and calculate additional cost
    void completeReservation() {
        int resId;
        cout << "\nEnter reservation ID to complete: ";
        cin >> resId;

        Reservation* current = reservationHead;
        while (current) {
            if (current->id == resId) {
                if (current->status == "Completed") {
                    cout << "\nReservation is already completed."; // Already marked done

                return;
            }
            if (current->status == "Cancelled") {
                cout << "\nCannot complete a cancelled reservation.";
                return;
            }

            cout << "\nReservation fee: 150 SAR (already paid and non-refundable)";

            float additionalCost;
            cout << "\nEnter additional cost of services (e.g., lab = 50 SAR, x-ray = 150 SAR , etc.): ";
            cin >> additionalCost;

            float remaining = additionalCost - 150; // Calculate remaining to be paid
            cout << "\nRemaining amount to be paid by patient: " << remaining << " SAR\n\n";

            int paidChoice;
            cout << "\nDid the patient pay the remaining amount? (1 = Yes / 2 = No): ";
            cin >> paidChoice;

            if (paidChoice == 1) {
                current->totalCost += remaining; // Add additional cost to total
                current->status = "Completed";        // Mark as completed
                cout << "\nReservation marked as completed.";
            } else {
                cout << "\nReservation status remains as: " << current->status << ".\nPayment not completed.";
            }
            return;
        }
        current = current->next;
    }

    cout << "\nReservation ID not found."; // No match found
}
void calculateDailyIncome(string date) {
    Reservation* current = reservationHead;
    float totalIncome = 0;
    bool found = false;

    while (current != nullptr) {
        if (current->date == date ) {
            totalIncome += current->totalCost;
            found = true;
        }
        current = current->next;
    }

    if (found) {
        cout << "\nTotal income for " << date << " is: " << totalIncome << " SAR\n";
    } else {
        cout << "\nNo reservations found on this date.\n";
    }
}
};

#endif
