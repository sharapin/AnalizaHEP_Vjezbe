/*
#include"Analyzer.h"

int main(void){

Analyzer *analyzer = new Analyzer();
cout << "r0 = " << analyzer -> R0(10, 0.5, 0.1) << endl;
analyzer -> ~Analyzer();

return 0;
}
*/

#include <stdio.h>
#include <math.h>
#include"Analyzer.h"

double binomial(int N, int r, double p) {
    double q = 1.0 - p;
    double a = lgamma(N + 1) - lgamma(r + 1) - lgamma(N - r + 1);
    double b = r * log(p) + (N - r) * log(q);
    return exp(a + b);
}

int binomial_cutoff(int N, double p, double epsilon) {
    double sum = 0.0;
    int r = 0;
    while (sum < epsilon) {
        sum += binomial(N, r, p);
        r++;
    }
    return r - 1;
}

int main() {
    int N = 10;
    double p = 0.5;
    double epsilon = 0.1;
    int r_0 = binomial_cutoff(N, p, epsilon);
    printf("For N=%d, p=%f, and epsilon=%f, the highest value of r_0 such that P(r<r_0)<epsilon is %d.\n", N, p, epsilon, r_0);
    return 0;
}
