#include <iostream>
 
using namespace std;
 
int main() {
    long long n;
    cin >> n;
    
    long long res = 1;
    for(int i = 1; i <= n; i++) {
        res *= i;
        res %= ((long long)1e9 + 7);
    }
    
    cout << res << endl;
        
    return 0;
}
