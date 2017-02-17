#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    long long n, m;
    cin >> t;
    
    while(t--) {
        cin >> n;
        
        m = 8 * n + 1;
        n = sqrt(m);
        
        if(m == n * n)
            cout << "Go On Bob " << (n - 1) / 2 << endl;
        else
            cout << "Better Luck Next Time" << endl;
    }
    
    return 0;
}
