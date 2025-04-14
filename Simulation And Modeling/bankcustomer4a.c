#include <stdio.h>
int main() {
    double lambda = 1.0 / 10;
    double mu = 1.0 / 5;

    double P_no_wait = 1 - (lambda / mu);
    printf("a. Probability that a customer will not have to wait: %.4f\n", P_no_wait);

    double expected_customers = lambda / (mu - lambda);
    printf("b. Expected number of customers in the bank: %.4f\n", expected_customers);

    double expected_time = 1 / (mu - lambda);
    printf("c. Expected time a customer spends in the bank: %.4f minutes\n", expected_time);

    return 0;
}
