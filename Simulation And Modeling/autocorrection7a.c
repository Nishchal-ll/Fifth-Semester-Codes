#include <stdio.h>

#define N 10

void auto_correlation(int arr[], int n) {
    double mean = 0.0;
    double sum = 0.0;
    double sum_lag = 0.0;

    // Calculate the mean of the array
    for (int i = 0; i < n; i++) {
        mean += arr[i];
    }
    mean /= n;

    // Calculate the auto-correlation for lag = 1
    for (int i = 0; i < n - 1; i++) {
        sum += (arr[i] - mean) * (arr[i + 1] - mean);
    }

    // Calculate variance
    for (int i = 0; i < n; i++) {
        sum_lag += (arr[i] - mean) * (arr[i] - mean);
    }

    double auto_corr = sum / sum_lag;
    printf("Auto-correlation at lag 1: %.4f\n", auto_corr);
}

int main() {
    int data[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto_correlation(data, N);
    return 0;
}
