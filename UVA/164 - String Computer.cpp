#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

const int N = 21;
int dp[N][N], shift;
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
    int x;
    
    if(i == a.size()) {
        for(int k = j; k < b.size(); k++, shift++) {
            x = i+shift+1;
            cout << "I" << b[j+(k-j)];
            if(x < 10) cout << '0' << x;
            else cout << x;
        }
        
        return;
    };
    
    if(j == b.size()) {
        x = i+shift+1;
        
        for(int k = i; k < a.size(); k++) {
            cout << "D" << a[i++];
            if(x < 10) cout << '0' << x;
            else cout << x;
        }
            
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
        x = i+shift+1;
        cout << "D" << a[i];
        if(x < 10) cout << '0' << x;
        else cout << x;
        shift--;
        path(i+1, j);
    } else if(B == calc(i, j)) {
        x = i+shift+1;
        cout << "I" << b[j];
        if(x < 10) cout << '0' << x;
        else cout << x;
        shift++;
        path(i, j+1);
    } else {
        x = i+shift+1;
        cout << "C" << b[j];
        if(x < 10) cout << '0' << x;
        else cout << x;
        path(i+1, j+1);
    }
}

int main() {
    while(cin >> a && a != "#") {
        cin >> b;
        shift = 0;
        memset(dp, -1, sizeof dp);
        calc(0, 0);
        path(0, 0);
        cout << 'E' << endl;
    }
    
    return 0;
}
