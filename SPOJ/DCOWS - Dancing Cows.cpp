#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

long long n, m;
long long dp[5001][5001];
vector<int> bulls, cows;

long long calc(long long i, long long j) {
    if(i == bulls.size()) return 0;
    if(j == cows.size()) return 2 * 1e18 + 1;
    
    long long &res = dp[i][j];
    if(res != -1) return res;
    
    return res = min(calc(i+1, j+1) + abs(bulls[i] - cows[j]), calc(i, j+1));
}

int main() {
    cin >> n >> m;
    
    bulls.resize(n);
    cows.resize(m);
    
    for(long long i = 0; i < n; i++) cin >> bulls[i];
    for(long long i = 0; i < m; i++) cin >> cows[i];
    
    sort(bulls.begin(), bulls.end());
    sort(cows.begin(), cows.end());
    
    memset(dp, -1, sizeof dp);
    cout << calc(0, 0) << endl;
    
    return 0;
}
