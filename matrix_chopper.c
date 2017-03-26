/* This program chops up a matrix according to user-specified parameters, including row and column limits. The matrix is then printed in its
    new form
*/

#include <stdio.h>

void print_array(int array[5][5], int lcolumn, int rcolumn, int trow, int brow) {       // Function for creating matrices
    
    /* * * * * * * * * * * * * * * Parameter Meanings * * * *  * * * * * * * * * *
    *                                                                            *
    * array[5][5] --> This is an array entered by the users of max size 5x5      *
    * lcolumn     --> This is the leftmost column that the user wishes to see    *
    * rcolumn     --> This is the rightmost column that the user wishes to see   *
    * trow        --> This is the topmost column that the user wishes to see     *
    * brow        --> This is the bottommost column that the user wishes to see  *
    *                                                                            *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    
    // Function variables
    int array2[6][6] = {};                              // Empty square 2D array of max size 6 for storing the
    int arrayrow = 0;                                   // Dummy variable used to keep track of how many rows have been assigned to the new matrix
    int numrows = brow - trow + 1;                      // Calculates number of rows to print based on user input
    int numcol = rcolumn - lcolumn + 1;                 // Calculates number of columns to print based on user input
    int l = 0;                                          // Dummy variable used to keep track of how many columns have been assigned to the new matrix
    
    // Looping procedures
    for (int i = 0; i < 5; i++) {                       // Looping through rows
        if (i < trow || i > brow)                       // This checks to see if the row is between the top row and bottom row as entered by the user
            continue;                                   // If it is outside the user entered range, the command turns back to the for loop with continue;
        else {
            for (int j = 0; j < 5; j++) {               // Looping through columns
                if (j < lcolumn || j > rcolumn)         // Checks to see if column is within range specified by user
                    continue;                           // If not --> continue back to top of for loop
                else {
                    array2[arrayrow][l] = array[i][j];  // If all of the tests are passed, the values at that row and column in the original data array are
                                                        // stored in the new array
                    l++;                                // Increment the new array's column number
                }
            }
            arrayrow++;                                 // Increment the new array's row number
            l = 0;                                      // If the loop goes successfully through a whole row, the column number must be reset
        }
        
    }

    for (int m = 0; m < numrows; m++) {                 // Nested for loops for printing each array element
        for (int n = 0; n < numcol; n++) {
            printf("%d ", array2[m][n]);
        }
        printf("\n");
    }
}
int main(void) {
    
    // Variables
    int lcolumn;        // User entered value for left column limit
    int rcolumn;        // User entered value for right column limit
    int trow;           // User entered value for top row limit
    int brow;           // User entered value for bottom row limit
    int array[5][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};
    
    // User input
    printf("Enter a lower column boundary: \n");
    scanf("%d", &lcolumn);
    
    printf("Enter an upper column boundary: \n");
    scanf("%d", &rcolumn);
    
    printf("Enter a top row boundary: \n");
    scanf("%d", &trow);
    
    printf("Enter a bottom row boundary: \n");
    scanf("%d", &brow);
    
    printf("\n");
    print_array(array, lcolumn, rcolumn, trow, brow);           // Calling the function
    return 0;
}
