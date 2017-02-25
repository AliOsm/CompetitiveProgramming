#include <iostream>

using namespace std;

int main() {
    long long t;
    cin >> t;
    
    long long n, m;
    while(t--) {
        cin >> n >> m;
        cout << (m * (m - 1) / 2) * (n / m) + (((n % m) * (n % m + 1)) / 2) << endl;
    }
    
    return 0;
}
