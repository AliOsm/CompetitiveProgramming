#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main() {     
    double a;
    cin >> a;
    
    cout << "A=" << fixed << setprecision(4) << 3.14159 * a * a << endl;
 
    return 0;
}
