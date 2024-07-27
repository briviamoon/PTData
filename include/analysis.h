#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "common.h"
#include "patient.h"

typedef struct {
    char insurance[MAX_STRING_LENGTH];
    int count;
} InsuranceCount;

typedef struct {
    char condition[MAX_STRING_LENGTH];
    int count;
} ConditionCount;

typedef struct {
    char age[MAX_STRING_LENGTH];
    int count;
} AgeCount;

typedef struct {
    char gender[MAX_STRING_LENGTH];
    int count;
} GenderCount;

typedef struct {
    char residence[MAX_STRING_LENGTH];
    int count;
} Residence;

InsuranceCount* analyze_insurance(Patient** patients, int count, int* result_count);
ConditionCount* analyze_conditions(Patient** patients, int count, int* result_count);
double calculate_average_age(Patient** patient, int count);

#endif
