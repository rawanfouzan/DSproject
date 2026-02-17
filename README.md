# Hospital Reservation System

## Project Overview:
This project is a group project developed as part of the CS214 Data Structures course at Qassim University. It focuses on building a Hospital Reservation System using C++ and a Linked List data structure for efficient management of patient records and appointment reservations. The system supports functionalities like patient registration, reservation scheduling, cancellation, and tracking daily income from reservations.

## Team Members:
- Rawan Alfouzan 
- Aljazi Aleqab 

## Project Files:
This project consists of several source files, as well as documentation. Below is a list of the main files included:

### Source Code Files:
- HospitalReservationSystem.cpp: The core C++ implementation of the reservation system. It includes the main logic for handling patient registration, reservations, and cancellations.
- HospitalReservationSystem.h: The header file containing the class declarations and function prototypes for the reservation system.
- Patient.h: Header file that defines the Patient class, including details like name, age, gender, and ID.
- Reservation.h: Header file that defines the Reservation class, which manages the reservation details such as time, department, and status.
- main.cpp: The main entry point of the program where the system functions are initialized and executed.

### Documentation Files:
- DSproject.pdf: The project report that provides detailed information about the design of the system, the data structure selection, and the main functions implemented. It also explains the reasoning behind choosing the linked list and describes the structure and implementation of the code.
- CS214Project.pdf: This document contains the guidelines provided for the CS214 Data Structures course, outlining the requirements and expectations for the project.

## Features:
- Patient Registration: Registers a new patient by storing personal information such as name, gender, and age.
- Reservation Scheduling: Allows patients to schedule appointments, ensuring no conflicts in the department or time slots.
- Reservation Cancellation: Enables users to cancel appointments, freeing up time slots.
- Reservation Completion: Marks the appointment as completed once the patient attends.
- View Reservations: Displays a list of all current reservations with patient details and status.
- Delete Patient: Deletes a patient's record, along with associated reservations.
- Daily Income Calculation: Bonus feature that calculates the total income for the hospital from reservations made on a specific day.

## Data Structure Used:
- Linked List: The system uses a linked list to dynamically store and manage patient and reservation data. Linked lists are ideal for this project due to their ability to handle frequent insertions and deletions efficiently.

## How to Run:
1. Download all the project files.
2. Open the HospitalReservationSystem.cpp file and other .cpp files in a C++ IDE or compiler (e.g., GCC).
3. Compile and run the program.
4. Follow the on-screen menu to interact with the system, including patient registration, reservation scheduling, and cancellations.

## Requirements:
- C++ compiler (e.g., GCC)
- Basic understanding of C++ and linked list operations.

## Acknowledgments:
This project was developed for the CS214 Data Structures course at Qassim University. Special thanks to Dr. Hoba Alsultan for the guidance and support throughout the project.

Feel free to modify the system or use it for your own purposes.
