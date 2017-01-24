#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int n;
double sol, dp[(1 << 16)], initValue = -1;
vector<pair<int, int> > p;

inline double dist(int i, int j) {
    return sqrt(pow(p[i].first - p[j].first, 2.0) + pow(p[i].second - p[j].second, 2.0));
}

double calc(int i, bitset<16> e) {
    if(e.all()) return 0;
    if(e[i]) return calc(i + 1, e);
    
    double &res = dp[e.to_ulong()];
    if(res != -1) return res;
    res = 1e18 + 1;
    
    for(int j = 0; j < n; j++)
        if(i != j && ~e[j]) {
            e[j] = e[i] = 1;
            res = min(res, calc(i + 1, e) + dist(i, j));
            e[j] = e[i] = 0;
        }
    
    return res;
}

int main() {
    string s;
    
    for(int c = 1; cin >> n && n; c++) {
        n *= 2;
        p.clear();
        p.resize(n);
        for(int i = 0; i < n; i++) cin >> s >> p[i].first >> p[i].second;
        sol = 1e18;
        fill_n(dp, (1<<16), initValue);
        
        bitset<16> e;
        for(int i = n; i < 16; i++) e[i] = 1;

        cout << "Case " << c << ": " << fixed << setprecision(2) << calc(0, e) << endl;
    }
    
    return 0;
}
