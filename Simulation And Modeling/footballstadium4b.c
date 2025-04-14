#include <stdio.h>

int main() {
    double time_to_purchase_ticket = 20.0 / 60;
    double time_to_seat = 1.5;

    double total_time = time_to_purchase_ticket + time_to_seat;
    printf("Total time spent by the sports fan: %.4f minutes\n", total_time);

    if (total_time <= 2) {
        printf("The fan can expect to be seated for the kick-off.\n");
    } else {
        printf("The fan cannot expect to be seated for the kick-off.\n");
    }

    return 0;
}
