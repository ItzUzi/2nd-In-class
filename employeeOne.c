#include <string.h>
#include "employee.h"

PtrToEmployee searhEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber){
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for(;ptr < endPtr; ptr++){
        if (ptr -> number == targetNumber)
            return (PtrToEmployee) ptr;   
    }
    return NULL;
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetname){
    const PtrToConstEmployee endPtr = ptr + tableSize;
    
    for(; ptr < endPtr; ptr++){
        if (strmcmp(ptr->name, targetName) == 0)
            return (PtrToEmployee) ptr;
    }
    return NULL;
}

void main()
{


}

