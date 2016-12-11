#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

const int N = 2001;
int dp[N][N];
string a, b, sol;

int calc(int i, int j) {
    if(i == a.size() || j == b.size()) return 0;
    
    int &res = dp[i][j];
    if(res != -1) return res;
    
    res = 0;
    if(a[i] == b[j])
        return res = calc(i + 1, j + 1) + 1;
    
    return res = max(calc(i + 1, j), calc(i, j + 1));
}

void path(int i, int j) {
    if(i == a.size() || j == b.size()) return;

    int A = -2, B = -2, C = -2;

    if(a[i] == b[j])
        A = calc(i + 1, j + 1) + 1;

    B = calc(i + 1, j);
    C = calc(i, j + 1);

    if(A == calc(i, j)) {
        sol += a[i];
        path(i + 1, j + 1);
    } else if (B == calc(i, j)) {
        path(i + 1, j);
    } else {
        path(i, j + 1);
    }
}

int main() {
    while(cin >> a >> b) {
        sol = "";
        memset(dp, -1, sizeof dp);
        cout << calc(0, 0) << " -> ";
        path(0, 0);
        cout << sol << endl;
    }
    
    return 0;
}