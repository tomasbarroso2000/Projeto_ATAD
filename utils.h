#include "list.h"
#include "map.h"
#include <math.h>

int equalsStringIgnoreCase(char str1[], char str2[]);
char** split(char *string, int nFields, const char *delim);
void importPatientsFromFile(char *filename, PtList *patients);
void importRegionsFromFile(char *filename, PtMap *regions);
Date stringToDate(char *str);
float stringToNumber(char *str);
int listGetById(PtList list, long int id, ListElem *ptElem);
void printTopNReleased(PtList list, int n, int listSize);
int isRankIgnored(int rank, int *arr, int size);
int getOldestAgeBySex(PtList list, char *sex, int listSize);
void showStatusStatsByAge(PtList list, int listSize, int lowerlim, int upperlim);
void showGrowth(PtList list, Date date, int listSize);
double getRate(double val1, double val2);
double getAverage(double val1, double val2);