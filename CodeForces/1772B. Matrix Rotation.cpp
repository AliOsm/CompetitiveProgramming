#include <bits/stdc++.h>

using namespace std;

int g[2][2];

void rotate() {
    int tmp = g[0][0];
    g[0][0] = g[1][0];
    g[1][0] = g[1][1];
    g[1][1] = g[0][1];
    g[0][1] = tmp;
}

bool check() {
    return g[0][0] < g[0][1] && g[1][0] < g[1][1] && g[0][0] < g[1][0] && g[0][1] < g[1][1];
}

int main() {
    int t;
    cin >> t;
    
    while(t-- != 0) {
        cin >> g[0][0] >> g[0][1] >> g[1][0] >> g[1][1];
        
        bool ok = false;
        
        for(int i = 0; i < 5; ++i) {
            if(check()) {
                ok = true;
                break;
            }
            
            rotate();
        }
        
        if(ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}
