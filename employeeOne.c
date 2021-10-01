#include <string.h>
#include "employee.h"

/**
 * Returns pointer to Number if it is found
 * Returns NULL if Number is not found
*/
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber){
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for(;ptr < endPtr; ptr++){
        if (ptr -> number == targetNumber)
            return (PtrToEmployee) ptr;   
    }
    return NULL;
}

/**
 * Returns pointer to Name if it is found
 * Returns NULL if Name is not found
*/
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName){
    const PtrToConstEmployee endPtr = ptr + tableSize;
    
    for(; ptr < endPtr; ptr++){
        if (strcmp(ptr->name, targetName) == 0)
            return (PtrToEmployee) ptr;
    }
    return NULL;
}

/**
 * Returns pointer to PhoneNumber if it is found
 * Returns NULL if PhoneNumber is not found
*/
PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, char *targetNumber){
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++){
        if(strcmp(ptr->phone, targetNumber) == 0)
            return (PtrToEmployee) ptr;
    }
    return NULL;
}

/**
 * Returns pointer to salary if it is found
 * Returns NULL if salary is not found
*/
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary){
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++){
        if(ptr -> salary == targetSalary)
            return (PtrToEmployee) ptr;
    }
    return NULL;
}

