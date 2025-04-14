#include <stdio.h>
#include <math.h>

int main() {
    // Example observed and expected frequencies
    int observed[] = {10, 20, 30, 40};
    int expected[] = {15, 25, 35, 25};
    int n = sizeof(observed) / sizeof(observed[0]);
    
    double chi_square_stat = 0.0;

    // Calculate the chi-square statistic
    for (int i = 0; i < n; i++) {
        chi_square_stat += pow(observed[i] - expected[i], 2) / expected[i];
    }

    // Output the chi-square statistic
    printf("Chi-square statistic: %.4f\n", chi_square_stat);

    return 0;
}
