#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

const int N = 1001;
int dp[N][N];
string a, b;

int calc(int i, int j) {
    if(i == a.size() || j == b.size()) return 0;
    
    int &res = dp[i][j];
    if(res != -1) return res;
    
    res = 0;
    if(a[i] == b[j])
        res = max(res, calc(i+1, j+1) + 1);
    
    res = max(res, max(calc(i, j+1), calc(i+1, j)));
    
    return dp[i][j] = res;
}

int main() {
    int res;
    bool blankline = false;
    
    while(cin >> a && a != "#") {
        if(blankline) cout << endl;
        blankline = true;
        
        cin >> b;
        memset(dp, -1, sizeof dp);
        res = calc(0, 0);
        cout << (15 * (a.size() - res)) + (30 * (b.size() - res)) << endl;
    }
    
    return 0;
}
