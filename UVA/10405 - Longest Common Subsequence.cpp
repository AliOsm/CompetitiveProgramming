#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int const N = 1001;
int dp[N][N];
string a, b;

int calc(int i, int j) {
    if(i == a.size() || j == b.size())
        return 0;
        
    int &res = dp[i][j];
    if(res != -1) return res;
    
    res = 0;
    
    if(a[i] == b[j])
        res = max(res, calc(i+1, j+1) + 1);
    res = max(res, calc(i+1, j));
    res = max(res, calc(i, j+1));
    return dp[i][j] = res;
}

int main() {
    while(getline(cin, a) && getline(cin, b)) {
        memset(dp, -1, sizeof dp);
        cout << calc(0, 0) << endl;
    }
    
    return 0;
}
