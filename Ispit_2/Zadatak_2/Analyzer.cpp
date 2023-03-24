#include"Analyzer.h"

#include <cstdlib>
#include <cmath>

Elipsoid::Elipsoid(double a, double b, double c) : a_(a), b_(b), c_(c) {}

double Elipsoid::volumen(int num_points) {
    int tocke_unutar = 0;

    for (int i = 0; i < num_points; i++) {
        double x = random(-a_, a_);
        double y = random(-b_, b_);
        double z = random(-c_, c_);

        if (unutar(x, y, z)) {
            tocke_unutar++;
        }
    }

    double Kvadar_volumen =8 * a_ * b_ * c_;
    return (tocke_unutar / static_cast<double>(num_points)) * Kvadar_volumen;
}

bool Elipsoid::unutar(double x, double y, double z) const {
    return (pow(x / a_, 2) + pow(y / b_, 2) + pow(z / c_, 2)) <= 1;
}

double Elipsoid::random(double min, double max) const {
    return min + (rand() / static_cast<double>(RAND_MAX)) * (max - min);
}
