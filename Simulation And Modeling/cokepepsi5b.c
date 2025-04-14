#include <stdio.h>

int main() {
    double p_pepsi_to_coke = 0.20;  // Probability of buying Coke after Pepsi
    double p_pepsi_to_pepsi = 0.80; // Probability of buying Pepsi after Pepsi
    double p_coke_to_coke = 0.90;   // Probability of buying Coke after Coke
    double p_coke_to_pepsi = 0.10;  // Probability of buying Pepsi after Coke

    // Given the current state is Pepsi, calculate the probability of buying Coke after two purchases
    double p_coke_after_two_purchases = (p_pepsi_to_coke * p_pepsi_to_coke) + 
                                        (p_pepsi_to_pepsi * p_coke_to_coke);

    printf("The probability of purchasing Coke after two purchases from now, given the person currently buys Pepsi: %.4f\n", p_coke_after_two_purchases);

    return 0;
}
