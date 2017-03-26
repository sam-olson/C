/* This program uses Simpson's rule to numerically integrate a function over a given boundary. The user is able to choose which function to integrate from a given list of 4 different functions
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define E 2.718

// subIntInput is a function that analyzes asks for input of the number of intervals, and tests this number's validity
int subIntInput(void) {
    bool check;
    int N = 0;
    while (check == false) {
        printf("Enter an even integer number of intervals:");
        scanf("%d", &N);
        printf("\n");
        if ((N % 2 != 0) || N < 1) {
            printf("That is an invalid number of intervals, try again\n");
        }
        else {
            break;
        }
    }
    return N;
}

// F is a function that selects one of the f(x) functions from the list and returns a value f that is used in the integrator function
double F(int menuChoice, double x) {
    double f;
    if (menuChoice == 1)
        return f = x;
    else if (menuChoice == 2)
        return f = (3 * (pow(x,3))) + (4 * x) + 2;
    else if (menuChoice == 3)
        return f = 2 * cos(x) * sin((pow(x,2))/2.0);
    else if (menuChoice == 4)
        return f = (x * (pow(E, (-3.0 * x)))) + 1;
    else {
        return 0.0;
    }
}

// The integrator function is a function that takes the output from the F function and computes the numeric integral
double integrator(double dx, double fx0, double fxN, double sum) {
    double u = (dx / 3.0) * (fx0 + sum + fxN);
    return u;
}

int main(void) {
    // Variables
    bool check;         // Boolean value used in while loop
    int selection;      // Variable that holds the user-entered selection integer
    double a1;          // Variable that stores the lower boundary
    double b1;          // Variable that stores the upper boundary
    double dx;          // Variable that stores the delta x value calculated from a, b, and N
    double N1;          // Variable that holds the output of the subIntInput function
    
    
    // Printing the table
    printf("Table of functions:\n");
    printf("[1] f(x) = x\n");
    printf("[2] f(x) = 3(x^3) + 4x + 2\n");
    printf("[3] f(x) = 2cos(x)sin((x^2)/2)\n");
    printf("[4] f(x) = x(e^-3x) + 1\n");
    
    // While loop
    while (check == true) {
        double sum = 0;     // Sum variable that is used to calculate the sigma in the integrator
        printf("Enter a number corresponding to the equation that you wish to integrate, or q/Q to quit: ");
        int number = scanf("%d", &selection);
        if(number != 1) {                       // This block of code is used to test whether the entered value is an integer
            char charSelect;                    // Character variable used to hold the entered character
            scanf("%c", &charSelect);
            if (charSelect == 'q' || charSelect == 'Q') {    // If the entered value is q or Q, the program exits with exit code 0
                printf("Exiting program...\n");
                return 0;
            }
        }
        if ((selection > 4 || selection < 1)) {       // This makes sure that the integer input is between 1 and 4 inclusive
            printf("That is not a valid selection, please try again...\n");
            continue;
        }

        else {
            printf("Enter a lower boundary to integrate over: ");       // Obtaining values for the boundaries
            scanf("%lf", &a1);
            printf("\n");
            printf("Enter an upper boundary to integrate over: ");
            scanf("%lf", &b1);
            printf("\n");
            if (b1 < a1) {                                  // If the lower boundary is of higher value than the upper boundary, they are switched
                double c = b1;                             // Dummy variable c stores the value of b1 for the swap
                b1 = a1;
                a1 = c;
            }
            
            N1 = subIntInput();                             // Function call to subIntInput, storing the return in N1
            dx = (b1 - a1) / N1;                            // Calculating dx
            for (int k = 1; k < N1; k++) {                  // Stepping through the intervals and summing the values
                if (k % 2 == 0) {                           // If k is even, the scaled output is multiplied by 2 and added to the sum
                    double l = (k / N1) * b1;               // Scaling the interval to the x axis
                    sum += 2.0 * F(selection, l);
                }
                
                else {                                      // If k is odd, the scaled output is multiplied by 4 and added to the sum
                    double l = (k / N1) * b1;               // Scaling the interval to the x axis
                    sum += 4.0 * F(selection, l);
                }
            }
            
            // Printing the output by calling the integrator function
            printf("The integration over these boundaries for the selected function was: %.10f\n", integrator(dx, F(selection, a1), sum, F(selection, b1)));
            continue;
        }
    return 0;
    }
}
