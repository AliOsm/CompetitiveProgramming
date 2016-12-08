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
        res = max(res, calc(i + 1, j + 1) + 1);
    res = max(res, calc(i + 1, j));
    res = max(res, calc(i, j + 1));
    return dp[i][j] = res;
}

string sol;
void path(int i, int j) {
    if(i == a.size() || j == b.size())
        return;
    
    int A = 0, B = 0, C = 0;
    
    if(a[i] == b[j])
        A = calc(i + 1, j + 1) + 1;
    B = calc(i + 1, j);
    C = calc(i, j + 1);
    
    if(A == calc(i, j)) {
        sol += a[i];
        path(i + 1, j + 1);
    } else if(B == calc(i, j))
        path(i + 1, j);
    else
        path(i, j + 1);
}

int main() {
    while(getline(cin, a) && getline(cin, b)) {
        memset(dp, -1, sizeof dp);
        sol = "";
        cout << calc(0, 0) << " -> ";
        path(0, 0);
        cout << sol << endl;
    }
    
    return 0;
}
