#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
double f(double x) {
    return sin(x);
}
int main() {
    double a, b;
    int numIterations;
    cout << "Enter the lower limit of the interval: ";
    cin >> a;
    cout << "Enter the upper limit of the interval: ";
    cin >> b;
    cout << "Enter the number of iterations: ";
    cin >> numIterations;
    srand(time(NULL));
    int numPointsInside = 0, numPointsOutside = 0;
    for (int i = 0; i < numIterations; i++) {
        double x = (double)rand() / RAND_MAX * (b - a) + a;
        double y = (double)rand() / RAND_MAX;
        if (y <= f(x)) {
            numPointsInside++;
        } else {
            numPointsOutside++;
        }
    }
    double totalArea = (b - a) * 1.0;
    double areaUnderCurve = totalArea * (double)numPointsInside / numIterations;
    cout << "Estimated area under the curve: " << areaUnderCurve << endl;

    return 0;
}
