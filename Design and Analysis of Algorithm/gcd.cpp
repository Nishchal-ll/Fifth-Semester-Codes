#include<iostream>
using namespace std;
int gcd(int a, int b, int &steps) {
    if(a == 0) {
        steps++;
        cout << b << " is GCD" << endl;
        return steps;
    }
    if(b == 0) {
        steps++;
        cout << a << " is GCD" << endl;
        return steps;
    }
    while (b != 0) {
        steps++;
        int r = a % b; 
        a = b;
        b = r;
    }
    cout << a << " is GCD" << endl;
    return steps;
}
int main() {
    int a, b, steps = 0;
    cout << "Enter a and b: ";
    cin >> a >> b;
    int stepCount = gcd(a, b, steps);
    cout << "Steps taken: " << stepCount << endl;
    return 0;
}

