#include <iostream>

using namespace std;

int main() {
    long long n, c = 0;
    cin >> n;
    
    while(n) {
        if(n % 10 == 7 || n % 10 == 4) c++;
        n /= 10;
    }
    
    if(c == 7 || c == 4) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
