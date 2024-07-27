#ifndef PATIENT_H
#define PATIENT_H

#include "common.h"

typedef struct {
    int id;
    char name[MAX_STRING_LENGTH];
    int age;
    char gender;
    char insurance[MAX_STRING_LENGTH];
    char condiition[MAX_STRING_LENGTH];
    char session_date[20];
} Patient;

bool add_patient(Patient* patient);
bool update_patient(Patient* patient);
Patient* get_patient(int id);
Patient** get_all_patients(int* count);

#endif