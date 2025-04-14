#include <iostream>

using namespace std;

int main() {
    // Given parameters
    int X0 = 11;  // Initial seed
    int m = 100;  // Modulus
    int a = 5;    // Multiplier
    int c = 13;   // Increment
    int n = 50;   // Number of random numbers to generate

    int X = X0; // Initialize with seed

    cout << "Generated Random Numbers using Mixed Congruential Method:\n";
    
    for (int i = 0; i < n; i++) {
        X = (a * X + c) % m; // Mixed Congruential Formula
        cout << X << " ";
    }

    cout << endl;
    return 0;
}
