#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

double factorial(int n) {
    if (n == 0) {
        return 1;
    }
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double poisson_pmf(int k, double lambda) {
    return exp(-lambda) * pow(lambda, k) / factorial(k);
}

double poisson_cdf(int r, double lambda) {
    double sum = 0;
    for (int k = 0; k <= r; k++) {
        sum += poisson_pmf(k, lambda);
    }
    return sum;
}

double find_lower_bound(double confidence_level, int events, double step) {
    double lambda = 0.0;
    while (poisson_cdf(events, lambda) < (1 - confidence_level) / 2) {
        lambda += step;
    }
    return lambda;
}

double find_upper_bound(double confidence_level, int events, double step) {
    double lambda = 50.0;
    while (1 - poisson_cdf(events, lambda) < (1 - confidence_level) / 2) {
        lambda -= step;
    }
    return lambda;
}

int main() {
    double confidence_level;
    int events;
    double step = 0.001;

    printf("Enter the confidence level (0 to 1): ");
    scanf("%lf", &confidence_level);

    printf("Enter the number of events: ");
    scanf("%d", &events);

    double lower_bound = find_lower_bound(confidence_level, events, step);
    double upper_bound = find_upper_bound(confidence_level, events, step);

    printf("Central Confidence Interval for the Poisson Distribution:\n");
    printf("Lower bound: %.3f\n", lower_bound);
    printf("Upper bound: %.3f\n", upper_bound);

    return 0;
}

