#include <iostream>

using namespace std;

int main() {
    // Given parameters
    int X0 = 13;  // Initial seed
    int m = 1000; // Modulus
    int a = 15;   // Multiplier
    int n = 50;   // Number of random numbers to generate

    int X = X0; // Initialize with seed

    cout << "Generated Random Numbers using Multiplicative Congruential Method:\n";
    
    for (int i = 0; i < n; i++) {
        X = (a * X) % m; // Multiplicative Congruential Formula
        cout << X << " ";
    }

    cout << endl;
    return 0;
}
