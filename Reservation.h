#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
using namespace std;

struct Reservation {
    int id;
    string department;
    string date;
    string time;
    string status;
    Reservation* next;
    int patientId;
    float totalCost;
};

#endif
