#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> x, y;

int main() {
    int t;
    cin >> t;
    
    int n, m, q;
    while(t--) {
        cin >> n >> m >> q;
        
        x.clear();
        x.resize(q + 2);
        y.clear();
        y.resize(q + 2);
        
        x[0] = 0;
        y[0] = 0;
        
        for(int i = 1; i <= q; i++)
            cin >> x[i] >> y[i];
        
        x[x.size() - 1] = n + 1;
        y[y.size() - 1] = m + 1;
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        int mxx = 0, mxy = 0;
        
        for(int i = 0; i < x.size() - 1; i++) {
            mxx = max(mxx, x[i+1] - x[i] - 1);
            mxy = max(mxy, y[i+1] - y[i] - 1);
        }
        
        cout << mxx * mxy << endl;
    }
    
    return 0;
}
