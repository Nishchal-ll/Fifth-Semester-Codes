#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    
    // Take user input for number of random values
    cout << "Enter the number of random values: ";
    cin >> n;
    
    double data[n];

    // Input the random values (between 0 and 1)
    cout << "Enter " << n << " random values (between 0 and 1):\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Step 1: Sort the data
    sort(data, data + n);

    // Step 2: Compute the Kolmogorov-Smirnov statistic D
    double D = 0.0;

    for (int i = 0; i < n; i++) {
        double empirical_cdf = (double)(i + 1) / n; // F_n(x)
        double theoretical_cdf = data[i];           // F(x) = x (for uniform distribution)
        double diff1 = fabs(empirical_cdf - theoretical_cdf);
        double diff2 = fabs(theoretical_cdf - (double)i / n); // |F(x) - F_n(x-)|
        D = max(D, max(diff1, diff2)); // Maximum absolute difference
    }

    // Output the K-S statistic
    cout << "\nKolmogorov-Smirnov Test Statistic (D) = " << D << endl;

    return 0;
}
