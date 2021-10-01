#include <string.h>
#include "employee.h"

/**
 * Returns pointer to data being looked for by using other methods for help
 * Every method uses this function in order to not have duplicate code
*/
static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr,
                                        int (*functionPtr)(const void *, PtrToConstEmployee))
{
    PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++)
        if((*functionPtr)(targetPtr, ptr) == 0)
            return (PtrToEmployee) ptr;
    return NULL;
}

/**
 * returns the pointer to the data that is wanted
*/
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return * (long *) targetPtr != tableValuePtr -> number;
}

static int compareEmploymentName(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return strcmp((char *) targetPtr , tableValuePtr -> name);
}

static int compareEmploymentPhoneNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return strcmp((char *) targetPtr , tableValuePtr -> phone);
}

static int compareEmploymentSalary(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return * (double *) targetPtr != tableValuePtr -> salary;
}

/**
 * Calls the compare funtions to get the pointer to the write data value
 * Then uses the return from those functions to call the searchEmployeeTable()
 * returns the pointer to the desired data
*/

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number){
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}

PtrToEmployee searchEmployeeByName(PtrToEmployee ptr, int size, char *name){
    return searchEmployeeTable(ptr, size, name, compareEmploymentName);
}

PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int size, char *phoneNumber){
    return searchEmployeeTable(ptr, size, phoneNumber, compareEmploymentPhoneNumber);
}

PtrToEmployee searchEmployeeBySalary(PtrToEmployee ptr, int size, double salary){
    return searchEmployeeTable(ptr, size, &salary, compareEmploymentSalary);
}