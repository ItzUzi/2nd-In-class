#include <string.h>
#include <stdlib.h>
#include "employee.h"

void main(void){
    /**
     * Tells compiler that methods exist in other C files
    */
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int tableSize, char *targetNumber);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int tableSize, double targetSalary);

    /**
     * Tells compiler about the employeeTable.c file
    */
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;
    PtrToEmployee matchPtr;

    // Tests the searchEmployeeByPhoneNumber by calling it
    printf("\nNow testing searchEmployeeByPhoneNumber()...\n");
    char *wrongPhoneNumber = "999-999-9999";
    char *correctPhoneNumber = "123-456-7890";

    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, wrongPhoneNumber);

    // matchPtr should equal null
    if(matchPtr != NULL)
        printf("The phone number: %s, was found in record %d.\n", wrongPhoneNumber, matchPtr - EmployeeTable);
    else
        printf("The phone number: %s, was not found in any record.\n", wrongPhoneNumber);

    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, correctPhoneNumber);

    // matchPtr should not equal null
    if(matchPtr != NULL)
        printf("The phone number: %s, was found in record %d.\n", correctPhoneNumber, matchPtr - EmployeeTable);
    else
        printf("The phone number: %s, was not found in any record.\n", correctPhoneNumber);

    printf("\nNow testing searchEmployeeBySalary()...\n");

    double wrongSalary = 9.5;
    double rightSalary = 10;

    // Tests the searchEmployeeBySalary by calling the function
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, wrongSalary);

    // matchPtr should be NULL
    if(matchPtr != NULL)
        printf("The salary: $%.2lf, was found in record %d.\n", wrongSalary, matchPtr - EmployeeTable);
    else
        printf("The salary: $%.2lf, was not found in any record.\n", wrongSalary);

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, rightSalary);
    // matchPtr should not be NULL
    if(matchPtr != NULL)
        printf("The salary: $%.2lf, was found in record %d.\n", rightSalary, matchPtr - EmployeeTable);
    else
        printf("The salary: $%.2lf, was not found in any record.\n", rightSalary);
}   