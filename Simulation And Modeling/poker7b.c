#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void poker_test() {
    int data[N];
    int counts[5] = {0};  // Store counts for values 1 through 5
    
    srand(time(0));

    // Generate N random numbers between 1 and 5
    for (int i = 0; i < N; i++) {
        data[i] = rand() % 5 + 1;
        counts[data[i] - 1]++;
    }

    // Display the generated numbers
    printf("Generated numbers: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Display the counts of each number
    printf("Counts of each number: ");
    for (int i = 0; i < 5; i++) {
        printf("Number %d: %d ", i + 1, counts[i]);
    }
    printf("\n");

    // Check for pairs, three of a kind, etc.
    if (counts[0] == 2 || counts[1] == 2 || counts[2] == 2 || counts[3] == 2 || counts[4] == 2) {
        printf("There is at least one pair.\n");
    }
    if (counts[0] == 3 || counts[1] == 3 || counts[2] == 3 || counts[3] == 3 || counts[4] == 3) {
        printf("There is at least one three of a kind.\n");
    }
    if (counts[0] == 4 || counts[1] == 4 || counts[2] == 4 || counts[3] == 4 || counts[4] == 4) {
        printf("There is at least one four of a kind.\n");
    }
    if (counts[0] == 5 || counts[1] == 5 || counts[2] == 5 || counts[3] == 5 || counts[4] == 5) {
        printf("There is a five of a kind.\n");
    }
}

int main() {
    poker_test();
    return 0;
}
