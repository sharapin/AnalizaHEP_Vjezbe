#include <cstdio>
#include <ctime>
#include <iostream>
#include "Analyzer.h"


// Princip koda je sljedeci: Na temelju danih vrijednosti za poluosi a,b i c, elipsoid "smjestamo" u kvadar. 
// Zatim random generatorom ( ovdje je koristen implementirani C-ov generator rand() ) uzimamo tocke iz tog kvadra i zapisujemo koje su tocke upale u elipsoid, a koje ne.
// Omjer broja tih tocaka nam daje priblizan volumen elipsoida. 
// Greske u volumenu su prvenstveno uzrokovane neoptimiziranoscu ovog random generatora.


int main() {
    double a, b, c;
    int num_points = 1000000;

    printf("Upisite zeljene vrijednosti za poluosi a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    srand(time(NULL));

    Elipsoid elipsoid(a, b, c);
    double Elipsoid_Volumen = elipsoid.volumen(num_points);
    printf("Volumen trazenog elipsoida: %lf\n", Elipsoid_Volumen);

    return 0;
}
