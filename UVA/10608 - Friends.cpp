#include <iostream>
#include <algorithm>

using namespace std;

int const N = 3e4 + 1;
int ds[N], rankt[N];

int find(int x) {
    return (ds[x] == x ? x : ds[x] = find(ds[x]));
}

int main() {
    int t;
    cin >> t;
    
    int n, m, a, b;
    while(t--) {
        cin >> n >> m;
        
        for(int i = 0; i < n; i++) {
            ds[i] = i;
            rankt[i] = 1;
        }
        
        while(m--) {
            cin >> a >> b;
            a--; b--;
            
            a = find(a);
            b = find(b);
            
            if(a == b)
                continue;
            
            ds[a] = b;
            rankt[b] += rankt[a];
        }
        
        sort(rankt, rankt + n);
        cout << rankt[n - 1] << endl;
    }
    
    return 0;
}
