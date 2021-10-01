#include <stdio.h>
#include <stdlib.h>
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
    int check = 15;
    int sum = 0;

    // Adds the sum of all the columns to make sure that the sum is 15
    for(int rows = 0; rows < 3; rows++){
        for(int columns = 0; columns < 3; columns++){
            sum += magicSquare[columns][rows];
            printf("Sum is: %d\n", sum);
        }
        if(sum != 15)
            return false;
        sum = 0;
    }

    sum = 0;

    for(int columns = 0; columns < 3; columns ++){
        for(int rows = 0; rows < 3; rows ++){
            sum += magicSquare[columns][rows];
            printf("Sum is: %d\n", sum);
        }
        if(sum != 15)
            return false;
        sum = 0;
    }

    for(int diagonal = 0; diagonal < 3; diagonal++)
        sum += magicSquare[diagonal][diagonal];
    
    int row = 3;
    for(int diagonal)

    return true;
}

int main(int argc, char const *argv[])
{
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

    int result = test(wrongSquare);
    printf("Result: %d\n", result);
    return 0;
}
