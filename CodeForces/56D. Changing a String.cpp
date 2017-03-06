#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

const int N = 1001;
int dp[N][N], shift = 0;
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

void path(int i, int j) {
    if(i == a.size()) {
        for(int k = j; k < b.size(); k++)
            cout << "INSERT " << i+(shift++)+1 << ' ' << b[j+(k-j)] << endl;
        
        return;
    };
    
    if(j == b.size()) {
        for(int k = i; k < a.size(); k++)
            cout << "DELETE " << i+shift+1 << endl;
            
        return;
    }
    
    if(a[i] == b[j]) {
        path(i+1, j+1);
        return;
    }
    
    int A = -2, B = -2, C = -2;
    
    A = calc(i+1, j) + 1;
    B = calc(i, j+1) + 1;
    C = calc(i+1, j+1) + 1;
    
    if(A == calc(i, j)) {
        cout << "DELETE " << i+shift+1 << endl;
        shift--;
        path(i+1, j);
    } else if(B == calc(i, j)) {
        cout << "INSERT " << i+shift+1 << ' ' << b[j] << endl;
        shift++;
        path(i, j+1);
    } else {
        cout << "REPLACE " << i+shift+1 << ' ' << b[j] << endl;
        path(i+1, j+1);
    }
}

int main() {
    cin >> a >> b;
    
    memset(dp, -1, sizeof dp);
    cout << calc(0, 0) << endl;
    path(0, 0);
    
    return 0;
}
