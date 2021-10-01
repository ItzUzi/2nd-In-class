#include <stdlib.h>
#include <string.h>
#include "employee.h"

Employee EmployeeTable[] = {
    {10011l, "Person One", "123-456-7890", 12.5},
    {10100l, "Person Two", "323-555-5555", 12},
    {10101l, "Person Three", "232-111-2222", 13},
    {10110l, "Person Four", "123-555-6666", 10},
    {10111l, "Person Five", "321-543-7561", 9}
};

const int EmployeeTableEntries = sizeof(EmployeeTable)/sizeof(EmployeeTable[0]);