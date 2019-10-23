#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1)

int main() {

    double r;

    while(scanf("%lf", &r) != EOF) {

        double area_total = r*r;
        double area_quartil = area_total*(1 - PI/4);
        double quadriculado_quartil = area_total*(1 - sqrt(3)/4 - PI/6);
        double pointed_quartil = area_quartil - 2*quadriculado_quartil;
        double center_area = area_total - 4*pointed_quartil - 4*quadriculado_quartil;
        quadriculado_quartil *= 4;
        pointed_quartil *= 4;

        printf("%.3f %.3f %.3f\n", center_area, pointed_quartil, quadriculado_quartil);

    }
    
}
