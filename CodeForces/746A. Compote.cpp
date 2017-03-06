#include <iostream>

using namespace std;

int a, b, c;

inline int can(int mid) {
    if(mid * 1 <= a && mid * 2 <= b && mid * 4 <= c)
        return true;
        
    return false;
}

int main() {
    cin >> a >> b >> c;
    
    int r = 1000, l = 0, mid = 0, res = 1001;
    
    while(l <= r) {
        mid = (r + l) / 2;
        
        if(can(mid)) {
            l = mid + 1;
            res = mid;
        } else
            r = mid - 1;
    }

    cout << (1 * res) + (2 * res) + (4 * res) << endl;
    
    return 0;
}
