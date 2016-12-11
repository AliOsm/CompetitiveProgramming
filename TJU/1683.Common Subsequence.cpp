#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

const int N = 2001;
int dp[N][N];
string a, b;

int calc(int i, int j) {
    if(i == a.size() || j == b.size()) return 0;
    
    int &res = dp[i][j];
    if(res != -1) return res;
    
    res = 0;
    if(a[i] == b[j])
        return res = calc(i + 1, j + 1) + 1;
    
    return res = max(calc(i + 1, j), calc(i, j + 1));
}

int main() {
    while(cin >> a >> b) {
        memset(dp, -1, sizeof dp);
        cout << calc(0, 0) << endl;
    }
    
    return 0;
}