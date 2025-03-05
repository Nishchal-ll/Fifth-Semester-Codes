#include<iostream>
#include<cmath>
#include<iomanip> 
using namespace std;
double fact(int x){
    if(x==0||x==1){
        return 1;
    }
    else{
        return x*fact(x-1);
    }
}
double poisson(int x, double lambda) {
    return exp(-lambda) * pow(lambda, x) / fact(x);
}
int main() {
    double lambda = 12.0;
    cout << "Poisson Distribution for x=0 to 15:\n" << endl;
    for (int x = 0; x <= 15; x++) {
        double p = poisson(x, lambda);
        cout << "P[" << x << "] = " << fixed << setprecision(10) << p << endl;
    }
    return 0;
}

