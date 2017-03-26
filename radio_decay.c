
// This program computes some decay calculations for several radioactive isotopes


#include <stdio.h>
#include <math.h>
#define E 2.718

int main(void) {
    
    // Variables
    double A;                       // Amount of remaining isotope after time t
    double hlAc = 21.77;            // Half life of Actinium 227 in years
    double hlBa = 12.8;             // Half life of Barium 140 in days
    double hlCs = 2.06;             // Half life of Cesium 134 in years
    double hlI = 2.26;              // Half life of Iodine 132 in hours
    int indexChoice;                // The index number of the isotope to be analyzed
    double hlIsotope;               // Variable assigned to the half life of the chosen isotope
    double a0;                      // Initial activity (in micro-Curies)
    double t;                       // Decay time
    char timeUnit;                  // Variable that stores the unit of time chosen by the user
    
    // Data table
    printf("  Isotope     |  Abbreviation  |  Half-life   | Index Number\n");
    printf("______________________________________________________________\n");
    printf("Actinium 227  |    Ac-227      |  %.2lf years |      0\n", hlAc);
    printf("Barium 140    |    Ba-140      |  %.1lf  days  |      1\n", hlBa);
    printf("Cesium 134    |    Cs-134      |  %.2lf  years |      2\n", hlCs);
    printf("Iodine 132    |    I-132       |  %.2lf  hours |      3\n", hlI);
    
    // Making sure all half-life values are in days (Barium 140 is already in days)
    hlAc = hlAc * 365.25;
    hlCs = hlCs * 365.25;
    hlI = hlI / 24.0;
    
    // User Input for index choice
    printf("Enter the index number of the isotope that you wish to analyze: ");
    scanf("%d", &indexChoice);
    
    // Selecting the isotope
    switch(indexChoice){
        case 0:
            hlIsotope = hlAc;
            break;
        
        case 1:
            hlIsotope = hlBa;
            break;
        
        case 2:
            hlIsotope = hlCs;
            break;
        
        case 3:
            hlIsotope = hlI;
            break;
        
        default:
            printf("That is not a valid index, exiting program\n");
            return 0;
    }
    
    // User input and conditional for initial activity
    printf("Enter the initial activity in micro-Curies: ");
    scanf("%lf", &a0);
    
    if (a0 <= 0 || a0 > 1E6) {
        printf("That is not a valid value for the initial activity, exiting program\n");
        return 0;
    }
    
    // User input and conditional for decay time
    printf("Enter a decay time: ");
    scanf("%lf", &t);
    
    if (t <= 0) {
        printf("That is not a valid value for the decay time, exiting program\n");
        return 0;
    }
    
    // User input and conditional for time units
    printf("Time unit  |  Index symbols\n");
    printf("___________________________\n");
    printf("  Hours    |     h or H\n");
    printf("   Days    |     d or D\n");
    printf("  Years    |     y or Y\n");
    printf("Select the units of the decay time from the table above:");
    scanf(" %c", &timeUnit);
    
    switch (timeUnit) {
        case 'h':
        case 'H':
            t = t / 24.0;
            break;
        
        case 'd':
        case 'D':
            t = t;
            break;
        
        case 'y':
        case 'Y':
            t = t * 365.25;
            break;
        
        default:
            printf("That is not a valid time unit index, exiting program\n");
            return 0;
            
    }
    
    A = a0 * pow(E, ((-0.693 * t) / hlIsotope));        // Equation for the remaining isotope
    
    printf("The amount remaining after %.2f days is %.4e micro-Curies\n", t, A);
    

    return 0;
}
