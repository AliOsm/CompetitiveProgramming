#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

const int N = 2001;
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
        return res = calc(i + 1, j + 1);
    
    res = 1e9;
    return res = min(res, min(calc(i + 1, j) + 1, min(calc(i, j + 1) + 1, calc(i + 1, j + 1) + 1)));
}

void path(int i, int j) {
    if(i == a.size() || j == b.size()) return;
    
    if(a[i] == b[j]) {
        path(i + 1, j + 1);
        return;
    }
    
    int A = -2, B = -2, C = -2;
    
    A = calc(i + 1, j) + 1;
    B = calc(i, j + 1) + 1;
    C = calc(i + 1, j + 1) + 1;
    
    if(A == calc(i, j)) {
        cout << "Delete a[" << i << "] -> " << a[i] << endl;
        path(i + 1, j);
    } else if(B == calc(i, j)) {
        cout << "Insert b[" << j << "] -> " << b[j] << endl;
        path(i, j + 1);
    } else {
        cout << "Replace a[" << i << "] -> " << a[i] << " with b[" << j << "] -> " << b[j] << endl;
        path(i + 1, j + 1);
    }
}

int main() {
    int t;
    cin >> t;
    
    while(t-- && cin >> a >> b) {
        memset(dp, -1, sizeof dp);
        cout << calc(0, 0) << endl;
        path(0, 0);
    }
    
    return 0;
}
