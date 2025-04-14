#include <stdio.h>

int main() {
    double p_rain_today = 0.0;   // Probability that today is not rainy (i.e. not raining today)
    double p_not_rain_today = 1.0;  // Probability that today is not rainy
    double p_rain_tomorrow_given_rain_today = 0.40;
    double p_not_rain_tomorrow_given_rain_today = 0.60;
    double p_rain_tomorrow_given_not_rain_today = 0.20;
    double p_not_rain_tomorrow_given_not_rain_today = 0.80;

    // Calculate the probability of it being not rainy two days later if today is not rainy
    double p_not_rain_day_after_tomorrow = (p_not_rain_today * p_not_rain_tomorrow_given_not_rain_today) + 
                                            (p_rain_today * p_not_rain_tomorrow_given_rain_today);

    printf("The probability that it will not rain the day after tomorrow if today is not rainy: %.4f\n", p_not_rain_day_after_tomorrow);

    return 0;
}
