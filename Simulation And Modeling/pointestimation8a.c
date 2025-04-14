#include <stdio.h>
double computeSampleMean(double sample[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += sample[i];
    }
    return sum / n;
}
int main() {
    int n;
    double populationMean;
    printf("Enter the number of samples: ");
    scanf("%d", &n);
    double sample[n]; 
    printf("Enter the sample values: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &sample[i]);
    }
    printf("Enter the population mean: ");
    scanf("%lf", &populationMean);
    double sampleMean = computeSampleMean(sample, n);
    double bias = sampleMean - populationMean;
    printf("Sample Mean (Point Estimation): %.2lf\n", sampleMean);
    printf("Bias: %.2lf\n", bias);
    return 0;
}
