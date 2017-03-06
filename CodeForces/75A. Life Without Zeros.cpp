#include <iostream>

using namespace std;

void reverse(long long &n) {
    long long tmp = 0;
    while(n != 0) {
        tmp *= 10;
        tmp += n % 10;
        n /= 10;
    }
    n = tmp;
}

int main() {
    long long a, b, c;
    cin >> a >> b;
    c = a + b;
    
    long long x = a, y = b, z = c, tmp;
    
    tmp = 0;
    while(x != 0) {
        if(x % 10 != 0) {
            tmp *= 10;
            tmp += x % 10;
        }
        
        x /= 10;
    }
    x = tmp;
    
    tmp = 0;
    while(y != 0) {
        if(y % 10 != 0) {
            tmp *= 10;
            tmp += y % 10;
        }
        
        y /= 10;
    }
    y = tmp;
    
    tmp = 0;
    while(z != 0) {
        if(z % 10 != 0) {
            tmp *= 10;
            tmp += z % 10;
        }
        
        z /= 10;
    }
    z = tmp;
    
    reverse(x);
    reverse(y);
    reverse(z);
    
    if(x + y == z) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
