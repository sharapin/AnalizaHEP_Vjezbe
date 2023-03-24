#ifndef ELIPSOID_H
#define ELIPSOID_H

class Elipsoid {
public:
    Elipsoid(double a, double b, double c);
    double volumen(int num_points);

private:
    double a_;
    double b_;
    double c_;

    bool unutar(double x, double y, double z) const;
    double random(double min, double max) const;
};

#endif
