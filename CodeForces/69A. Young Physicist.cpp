#include <iostream>

using namespace std;

int main() {
    int n, a, b, c, r1, r2, r3;
    r1 = r2 = r3 = 0;
    
    cin >> n;
    n--;
    
    cin >> r1 >> r2 >> r3;
    
    while(n--) {
        cin >> a >> b >> c;
        
        r1 += a;
        r2 += b;
        r3 += c;
    }
    
    if(!r1 && !r2 && !r3) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
