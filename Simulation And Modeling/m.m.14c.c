#include <stdio.h>

int main() {
    double lambda, mu;

    printf("Enter Arrival Rate (lambda): ");
    scanf("%lf", &lambda);
    printf("Enter Service Rate (mu): ");
    scanf("%lf", &mu);

    double rho = lambda / mu;
    printf("Traffic Intensity (rho): %.4f\n", rho);

    double expected_customers = lambda / (mu - lambda);
    printf("Expected number of customers in the system: %.4f\n", expected_customers);

    double expected_time = 1 / (mu - lambda);
    printf("Expected time a customer spends in the system: %.4f minutes\n", expected_time);

    return 0;
}
