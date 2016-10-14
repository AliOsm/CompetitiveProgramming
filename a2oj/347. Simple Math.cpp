#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double a, b, c, x;
    cin >> a >> b >> c;

    x = (-b+sqrt((b*b)-(4*a*c)))/(2*a);

    cout << x;

    return 0;
}
