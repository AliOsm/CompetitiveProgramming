#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

const int N = 5000;
int dp[N][N];
string a, b;

int calc(int i, int j) {
    if(i == a.size())
        return b.size() - j;
        
    if(j == b.size())
        return a.size() - i;
        
    int &res = dp[i][j];
    if(res != -1) return res;
    
    res = 0;
    if(a[i] == b[j])
        return res = calc(i+1, j+1);
    
    return res = min(calc(i+1, j) + 1, min(calc(i, j+1) + 1, calc(i+1, j+1) + 1));
}

int main() {
    int x, y;
    
    while(cin >> x >> a >> y >> b) {
        memset(dp, -1, sizeof dp);
        cout << calc(0, 0) << endl;
    }
    
    return 0;
}
