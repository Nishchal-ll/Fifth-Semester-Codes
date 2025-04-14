#include <stdio.h>
#include <math.h>
double computeSampleMean(double sample[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += sample[i];
    }
    return sum / n;
}
double computeStandardDeviation(double sample[], int n, double mean) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += pow(sample[i] - mean, 2);
    }
    return sqrt(sum / (n - 1)); 
}

int main() {
    int n;
    double confidenceLevel, Z;
    printf("Enter the number of samples: ");
    scanf("%d", &n);
    double sample[n];
    printf("Enter the sample values: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &sample[i]);
    }
    printf("Enter the confidence level (90, 95, or 99): ");
    scanf("%lf", &confidenceLevel);
    if (confidenceLevel == 90) {
        Z = 1.645;
    } else if (confidenceLevel == 95) {
        Z = 1.96;
    } else if (confidenceLevel == 99) {
        Z = 2.576;
    } else {
        printf("Invalid confidence level! Using 95%% by default.\n");
        Z = 1.96;
    }
    double sampleMean = computeSampleMean(sample, n);
    double standardDeviation = computeStandardDeviation(sample, n, sampleMean);
    double marginOfError = Z * (standardDeviation / sqrt(n));
    double lowerBound = sampleMean - marginOfError;
    double upperBound = sampleMean + marginOfError;
    printf("Sample Mean: %.2lf\n", sampleMean);
    printf("Standard Deviation: %.2lf\n", standardDeviation);
    printf("Margin of Error: %.2lf\n", marginOfError);
    printf("Confidence Interval: (%.2lf, %.2lf)\n", lowerBound, upperBound);
    return 0;
}
