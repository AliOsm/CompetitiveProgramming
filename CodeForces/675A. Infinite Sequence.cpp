#include <iostream>

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    
    if(a == b && b == c && c == a || (a == b)) {
        cout << "YES" << endl;
    } else if(c == 0 && a != b) {
        cout << "NO" << endl;
    } else if(a > b && c > 0) {
        cout << "NO" << endl;
    } else if(a < b && c < 0) {
        cout << "NO" << endl;
    } else if((b - a) % c == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
