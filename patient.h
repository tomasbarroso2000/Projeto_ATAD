#pragma once
#include "date.h"

typedef struct patient{
    int id;
    char sex[6]; // {“male”, “female”}
    int birthYear;
    char country[40]; //birth country
    char region[40];
    char infectionReason[100];
    int infectedBy; // id of the infected patient
    Date confirmedDate;
    Date releasedDate;
    Date deceasedDate;
    char status[10]; // {“isolated, “released”, “deceased”}
} Patient;

Patient createPatient(int id, char *sex, int birthYear, char* country, char* region, char* infectionReason, int infectedBy, Date confirmedDate, Date releasedDate, Date deceasedDate, char* status);
void printPatient(Patient p);
int getAge(Patient p);
int getNumberOfInfectedDays(Patient p);
int getDifference(Date old, Date recent);