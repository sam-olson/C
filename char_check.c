/* 
 
This program takes a user-entered string and assess whether or not a user-entered character is in the string. If the character is in the string, the index location of the character is returned. The search can begin from the beginning of the string, or the end of the string.
 
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXLENGTH   256

int findchr(char str[], char ch, int dir) {
    int loc;                                        // Local variable used for storing location of character
    if (dir == 0) {                                 // Branch for if user chooses to search forward
        for (int k = 0; k < strlen(str); k++) {
            if (str[k] == ch) {
                loc = k;                            // If the character is found, the location of the character is stored in loc
                return loc;
            }
        }
        return -1;                                  // If nothing is found, return error
    }
    else if (dir == 1) {                            // Branch for if user chooses to search in reverse
        int l = (int)strlen(str) - 1;
        for (int k = l; k >= 0; k--) {
            if (str[k] == ch) {
                loc = l - k - 1;                    // The location is offset by one due to the reverse process
                return loc;

            }
        }
        return -1;                                  // If nothing is found, return error
    }
    return 0;
}

int main(void) {
    
    // Variables
    char string[MAXLENGTH];                         // String of maximum length determined by MAXLENGTH macro
    char ch;                                        // Character variable to store user-chosen character to search for
    int dir = 0;                                    // 0 or 1 direction integer
    bool check = true;                              // Used in while loop
    
    // User input
    printf("Enter a string to analyze: \n");
    fgets(string, MAXLENGTH, stdin);
    printf("Enter the character which you wish to find: \n");
    scanf("%c", &ch);
    
    // Error handling
    while (check == true) {
        printf("Enter a direction that you wish to search the string in (0 for forward, 1 for reverse): \n");
        scanf("%d", &dir);
        if (dir != 0 && dir != 1) {
            printf("That is not a valid direction, please try again\n");        // Error handling for invalid direction input
            continue;               // Go back to top of loop if invalid input is used
        }
        else {
            check = false;          // This is reached if the user entered a valid input
        }
    }
    
    // Output
    int output = findchr(string, ch, dir);          // Function is called
    if (output == -1)
        printf("That character is not in the string\n");            // If the return is an error, an error message is printed
    else {
        printf("The character occured at index number: %d\n", output);      // Otherwise the location of the character is printed
    }
}

