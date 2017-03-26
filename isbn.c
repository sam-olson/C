
/* This program takes the first 12 digits of an ISBN-13 number as chosen by the user, and determines the group number and publisher number. The program also computes the checksum of the ISBN
*/

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // Variables
    long int isbn;                          // User-entered ISBN
    int done = 1;                           // Boolean to keep the while loop going
    long int num = 0;                       // Placeholder number to calculate the modulus of the ISBN
    int i;                                  // Indexing variable
    long int j;                             // Placeholder variable to store calculations
    int k;                                  // Indexing variable
    int l;                                  // Indexing variable
    long int m;                             // Number used to store array variables during checksum
    long int array[12] = {0};               // Array that holds digits of ISBN
    long int group;                         // Variable containing the groupnumber
    int sum = 0;                            // Checksum holding variable
    
    while (done == 1) {
        
        // User input
        printf("Enter the first 12 digits of your desired ISBN-13, or 0 to exit: ");
        scanf("%ld", &isbn);
        
        // Making sure the ISBN is valid
        if (isbn == 0) {
            printf("Exiting program...\n");
            return 0;
        }
        
        else if (isbn > 999999999999) {
            printf("That ISBN is too long, try again\n");
        }
        
        else if (isbn < 99999999999) {
            printf("That ISBN is too short, try again\n");
        }
        
        else {
            
            // Storing digits in array using modulus/division
            for (i = 0; i <= 11; i++) {
                if (i == 0) {
                    j = (isbn / 100000000000);
                    num += j * 100000000000;
                    array[0] = j;
                }
                
                else if (i == 1) {
                    j = (isbn % num) / 10000000000;
                    num += (j * 10000000000);
                    array[1] = j;
                }
                
                else if (i == 2) {
                    j = (isbn % num) / 1000000000;
                    num += j * 1000000000;
                    array[2] = j;
                }
                
                else if (i == 3) {
                    j = (isbn % num) / 100000000;
                    num += j * 100000000;
                    array[3] = j;
                }
                
                else if (i == 4) {
                    j = (isbn % num) / 10000000;
                    num += j * 10000000;
                    array[4] = j;
                }
                
                else if (i == 5) {
                    j = (isbn % num) / 1000000;
                    num += j * 1000000;
                    array[5] = j;
                }
                
                else if (i == 6) {
                    j = (isbn % num) / 100000;
                    num += j * 100000;
                    array[6] = j;
                }
                
                else if (i == 7) {
                    j = (isbn % num) / 10000;
                    num += j * 10000;
                    array[7] = j;
                }
                
                else if (i == 8) {
                    j = (isbn % num) / 1000;
                    num += j * 1000;
                    array[8] = j;
                }
                
                else if (i == 9) {
                    j = (isbn % num) / 100;
                    num += j * 100;
                    array[9] = j;
                }
                
                else if (i == 10) {
                    j = (isbn % num) / 10;
                    num += j * 10;
                    array[10] = j;
                }
                
                else if (i == 11) {
                    j = (isbn % num);
                    num += j;
                    array[11] = j;
                }
            }
            
            // Printing the ISBN back with periods inbetween each digit
            printf("Your ISBN is: ");
            for (k = 0; k < 12; k++) {
                printf("%ld.", array[k]);
            }
            
            printf("\n\n");
            
            // Analyzing the group number and publisher number
            group = array[3];
            printf("Group: ");
            if (group == 0) {
                printf("0 - English\n");
                printf("Publisher: ");
                if (array[4] == 0 || array[4] == 1) {
                    printf("%ld%ld\n", array[4], array[5]);
                    printf("Title: ");
                    printf("%ld%ld%ld%ld%ld%ld\n", array[6], array[7], array[8], array[9], array[10], array[11]);
                }
                else if (array[4] >= 2 && array[4] <= 6) {
                    printf("%ld%ld%ld\n", array[4], array[5], array[6]);
                    printf("Title: ");
                    printf("%ld%ld%ld%ld%ld\n", array[7], array[8], array[9], array[10], array[11]);
                }
                else if (array[4] == 7 || array[4] == 8) {
                    if (array[5] <= 4) {
                        printf("%ld%ld%ld%ld\n", array[4], array[5], array[6], array[7]);
                        printf("Title: ");
                        printf("%ld%ld%ld%ld\n", array[8], array[9], array[10], array[11]);
                    }
                    else {
                        printf("%ld%ld%ld%ld%ld\n", array[4], array[5], array[6], array[7], array[8]);
                        printf("Title: ");
                        printf("%ld%ld%ld\n",array[9], array[10], array[11]);
                    }
                }
                
                else if (array[4] == 9) {
                    if (array[5] <=4) {
                        printf("%ld%ld%ld%ld%ld%ld\n", array[4], array[5], array[6], array[7], array[8], array[9]);
                        printf("Title: ");
                        printf("%ld%ld\n", array[10], array[11]);
                    }
                    else {
                        printf("%ld%ld%ld%ld%ld%ld%ld\n", array[4], array[5], array[6], array[7], array[8], array[9], array[10]);
                        printf("Title: ");
                        printf("%ld\n", array[11]);
                    }
                }
                
            }
            
            else if (group == 1)
                printf("1 - English\n");
            else if (group == 2)
                printf("2 - French\n");
            else if (group == 3)
                printf("3 - German\n");
            else if (group == 4)
                printf("4 - Japan\n");
            else if (group == 5)
                printf("5 - former USSR\n");
            else if (group == 7)
                printf("7 - China\n");
            else {
                printf("Not a valid group number\n");
            }
            
            // Computing checksum
            for (l = 0; l < 12; l++) {
                m = array[l];
                if ((l % 2) == 0)
                    sum += m;
                else {
                    sum += (m * 3);
                }
            }
            
            sum %= 10;
            sum = 10 - sum;
            
            printf("Check: ");
            printf("%d\n", sum);
        }
    }
    return 0;
}

