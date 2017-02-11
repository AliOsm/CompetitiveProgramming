#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    
    while(cin >> n >> m && n != -1 && m != -1) {
        if(n > m) swap(n, m);
        if(n == m) cout << 0 << endl;
        else if(n == 0 && m == 99) cout << 1 << endl;
        else if(n == 0 && m != 99) cout << min(m, 99 - m + 1) << endl;
        else if(n != 0 && m == 99) cout << min(n + 1, 99 - n) << endl;
        else cout << min(abs(n - m), n - 1 + 99 - m + 2) << endl;
    }
    
    return 0;
}
