#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

struct Patient {
    int id;
    string fullName;
    string birthDate;
    string gender;
    string maritalStatus;
    string phone;
    Patient* next;
};

#endif
