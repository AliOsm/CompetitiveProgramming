#include <iostream>
#include <iomanip>
#include <cmath>
 
using namespace std;
 
int main() {
    double a, b;
    cin >> a >> b;
    double x, y;
    cin >> x >> y;
    
    cout << fixed << setprecision(4) << sqrt(pow(a - x, 2) + pow(b - y, 2)) << endl;
 
    return 0;
}
