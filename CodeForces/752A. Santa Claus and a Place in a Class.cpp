#include <iostream>

using namespace std;

int main() {
    int n, m, k, c = 1;
    cin >> n >> m >> k;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(c == k) {
                cout << i << ' ' << j << ' ' << 'L' << endl;
                return 0;
            }
            
            c++;
            
            if(c == k) {
                cout << i << ' ' << j << ' ' << 'R' << endl;
                return 0;
            }
            
            c++;
        }
    
    return 0;
}
