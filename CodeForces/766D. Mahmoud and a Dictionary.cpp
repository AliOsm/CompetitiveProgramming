#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int const N = 2e5;
int n, m, q, ds[N];
map<string, int> mp;

int find(int x) {
    return (ds[x] == x ? x : (ds[x] = find(ds[x])));
}

int main() {
    int type, a, b;
    string t1, t2;
    
    cin >> n >> m >> q;
    
    for(int i = 0; i < n; i++) {
        cin >> t1;
        mp[t1] = i;
        ds[i] = i;
        ds[i + n] = i + n;
    }
    
    for(int i = 0; i < m; i++) {
        cin >> type >> t1 >> t2;
        
        a = mp[t1];
        b = mp[t2];
        
        if(type == 1) {
            if(find(a) != find(b + n) && find(b) != find(a + n)) {
                ds[find(a)] = find(b);
                ds[find(a + n)] = find(b + n);
                cout << "YES" << endl;
            } else
                cout << "NO" << endl;
        } else {
            if(find(a) != find(b) && find(a + n) != find(b + n)) {
                ds[find(a)] = find(b + n);
                ds[find(b)] = find(a + n);
                cout << "YES" << endl;
            } else
                cout << "NO" << endl;
        }
    }
    
    for(int i = 0; i < q; i++) {
        cin >> t1 >> t2;
        
        a = mp[t1];
        b = mp[t2];
        
        if(find(a) == find(b) || find(a + n) == find(b + n))
            cout << 1 << endl;
        else if(find(a) == find(b + n) || find(b) == find(a + n))
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
    
    return 0;
}
