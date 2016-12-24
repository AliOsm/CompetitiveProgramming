#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#include <memory.h>

using namespace std;

int k;
string a, b;
int dp[2001][2001];

int calc(int i, int j) {
    if(i == a.size()) return (b.size() - j) * k;
    if(j == b.size()) return (a.size() - i) * k;
    
    int &res = dp[i][j];
    if(res != -1) return res;
    
    res = 0;
    if(a[i] == b[j])
        return res = calc(i+1, j+1);
    
    return res = min(calc(i+1, j+1) + abs(a[i] - b[j]), min(calc(i+1, j) + k, calc(i, j+1) + k));
}

int main() {
    cin >> a >> b >> k;
    
    memset(dp, -1, sizeof dp);
    cout << calc(0, 0) << endl;
    
    return 0;
}
