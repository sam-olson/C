/*
    This program calculates several characterists of a laser, such as the minimum Guassian beam width,
    the positions of the mirrors, and the angular spread of the beam.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.141592654

int main(void) {
    
    // Variables
    double r1;          // Curvature of mirror 1
    double r2;          // Curvature of mirror 2
    double L;           // Length between centers of two mirrors
    double lambda;      // The wavelength of light used
    double w0;          // Minimum beam width
    double z1;          // Position of mirror 1
    double z2;          // Position of mirror 2
    double zR;          // Rayleigh length
    double g1;          // Intermediate variable
    double g2;          // Intermediate variable
    double theta;       // Beam angular spread
    double geo_dist;    // Geostationary distance
    double wGD;         // Beam waist at geostationary distance
    
    // User Input
    printf("Enter a value for the curvature of mirror 1 in centimeters: ");
    scanf("%lf", &r1);
    
    printf("Enter a value for the curvature of mirror 2 in centimeters: ");
    scanf("%lf", &r2);
    
    printf("Enter a value for the length between the center of the two mirrors in centimeters: ");
    scanf("%lf", &L);
    
    printf("Enter a value for the wavelength of light used in nanometers: ");
    scanf("%lf", &lambda);
    
    // Calculations
    z1 = -(L * (r2 - L)) / (r1 + r2 - (2 * L));
    z2 = z1 + L;
    
    g1 = 1 - (L / r1);
    g2 = 1 - (L / r2);
    
    zR = sqrt((L * (r2 - L) * (r1 - L) * (r1 + r2 - L)) / (pow(r1 + r2 - (2 * L), 2)));
    
    w0 = sqrt((L * lambda * 1E-7) / PI) * pow((g1 * g2 * (1 - g1 * g2)) / pow((g1 + g2 - (2 * g1 * g2)), 2), 0.25);
    
    theta = (2 * ((lambda * 1E-7) / (PI * w0)));
    
    geo_dist = 35786 * 1E5;
    wGD = (w0 * sqrt(1 + pow((geo_dist / zR),2))) / 1E5;
    
    // Output
    printf("Position of mirror 1 = %.3g cm\n", z1);
    printf("Position of mirror 2 = %.3g cm\n", z2);
    printf("Minimum beam width = %.3g cm\n", w0);
    printf("Beam angular spread = %.3g radians\n", theta);
    printf("Beam width at geostationary distance = %.3g km\n", wGD);
    
    return 0;
}
