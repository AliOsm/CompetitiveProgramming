#include <iostream>
 
using namespace std;
 
long long n, m;
 
long long can(long long mid) {
    long long S = mid, cc = mid * 2;
    
    if(S <= n && cc <= m)
        return true;
    else {
        if(cc > m) return false;
        
        long long needS = S - n;
        
        if(cc <= (m - (needS * 2)))
            return true;
        else
            return false;
    }
}

int main() {
    cin >> n >> m;
    
    long long l = 0, r = 1e18, res;
    while(l <= r) {
        long long mid = (l + r) / 2;
        
        if(can(mid)) {
            res = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    
    cout << res << endl;
    
    return 0;
}
