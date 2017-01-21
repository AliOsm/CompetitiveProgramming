#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int n, mid, cur, res;
    vector<int> p;
    while(t--) {
        cin >> n;
        mid = cur = res = 0;
        
        p.clear();
        p.resize(n);
        for(int i = 0; i < n; i++) cin >> p[i];
        sort(p.begin(), p.end());
        
        mid = ceil((p[0] + p[n - 1]) / 2.0);
        cur = mid;
        
        for(int i = 0; i < n; i++) {
            res += abs(cur - p[i]);
            cur = p[i];
        }
        
        res += abs(cur - mid);
        
        cout << res << endl;
    }
    
    return 0;
}
