#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double n, r = 0, t;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> t;
        r += t / 100.0;
    }
    
    cout << fixed << setprecision(7) << r / n * 100 << endl;
    
    return 0;
}
