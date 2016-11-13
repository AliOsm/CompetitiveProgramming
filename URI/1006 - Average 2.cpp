#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main() {     
    double a, b, c;
    cin >> a >> b >> c;
    
    cout << "MEDIA = " << fixed << setprecision(1) << ((a * 2) + (b * 3) + (c * 5)) / 10 << endl;
 
    return 0;
}
