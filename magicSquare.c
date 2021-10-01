#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Takes a 2d array as a parameter
 * Checks if 2d array is a magic square
 * by adding all rows,columns,and diagonals
 * 
 * Magic square is a square where the sum of the
 * rows,columns, and diagonals is 15
 * 
 * Returns a 1 if square is a "magic square"
 * else returns 0
*/
int test(int magicSquare[3][3]){
    int false = 0;
    int true = 1;
    int sum = 0;
    // Used for rows
    int sum2 = 0;
    int check;

    for(int diagonal = 0; diagonal < 3; diagonal++)
        sum += magicSquare[diagonal][diagonal];
    // initializes the check to make sure all next sums sum up to the check
    check = sum;
    sum = 0;

    int row;
    for(int column = 0; column < 3; column++){
        row = 2 - column;
        sum += magicSquare[column][row];
    }
    if(sum != check)
        return false;
    sum = 0;
    // Adds the sum of all the columns to make sure sum is equal to check
    for(int rows = 0; rows < 3; rows++){
        for(int columns = 0; columns < 3; columns++){
            sum += magicSquare[columns][rows];
            // Adds the sum of all the rows to make sure sum is equal to check
            sum2 += magicSquare[rows][columns];
        }
        if(sum != check || sum != sum2)
            return false;
        sum = 0;
        sum2 = 0;
    }

    return true;
}

void rndmArray(int array[3][3], int temp[9]){
    int count = 0;

    for(int column = 0; column < 3; column++)
        for(int row = 0; row < 3; row++){
            array[column][row] = temp[count];
            count++; 
        }
    
    for(int column = 0; column < 3; column++)
        for(int row = 0; row < 3; row++)
            printf("Array at column %d and row %d, is: %d\n", column, row, array[column][row]);
    

        
}

/**
 * Checks if array contains number since it
 * should contain no duplicates
 * @Params: array, targetNum
 * checks array contents for target num
 * if targetNum is found return 1 else return 0
*/
int contains(int array[9], int targetNum){
    int result = 0;

    for(int index = 0; index < 10; index++){
        if (array[index] == targetNum)
            result = 1;
    }
        
    return result;
}

void rndmNum(int array[3][3]){
    srand(time(NULL));
    int rndm = (rand() % 9) + 1;
    int count = 0;
    int check = 45;
    int temp[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int result;
    while(count < 9){
        if(result != 1){
            temp[count] = rndm;
            count++;
        }
        if (count == 8){
            for(int i = 0; i < 8; i++)
                check -= temp[i];
            temp[8] = check;
            check++;
        }


    srand(time(NULL));
    rndm = (rand() % 9) + 1;
    result = contains(temp, rndm);
    }

    rndmArray(array, temp);
}

int main(int argc, char const *argv[])
{
    int count = -1;
    int result = 0;
    int wrongSquare[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int correctSquare[3][3] = {
        {4,9,2},
        {3,5,7},
        {8,1,6}
    };

    result = test(correctSquare);
    printf("Result: %d\n", result);
    result = 0;

    while (result != 1){
        // Calculates how many failed attempts there were
        // Does not increment if rndm square is a magic square
        count++;
        int rndmSquare[3][3];
        rndmNum(rndmSquare);
        result = test(rndmSquare);
        printf("Count is: %d\n", count);
    }
    

    return 0;
}
