#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    int b1, b2, b3;
    cin >> b1 >> b2 >> b3;
    int n;
    cin >> n;
    
    if(ceil((a1 + a2 + a3) / 5.0) + ceil((b1 + b2 + b3) / 10.0) <= n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}
