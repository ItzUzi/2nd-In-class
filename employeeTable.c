#include <stdlib.h>
#include <string.h>
#include "employee.h"

Employee EmployeeTable[] = {
    {10011, "Person One", "123-456-7890", 12.5},
    {10100, "Person Two", "323-555-5555", 12},
    {10101, "Person Three", "232-111-2222", 13},
    {10110, "Person Four", "123-555-6666", 10},
    {10111, "Person Five", "321-543-7561", 9}
};

const int EmployeeTableEntries = sizeof(EmployeeTable)/sizeof(EmployeeTable[0]);

void main(){
    printf("%d\n", sizeof(EmployeeTable));
}