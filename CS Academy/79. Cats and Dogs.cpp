#include <bits/stdc++.h>

using namespace std;

int const N = 2001;
int n, m, cats[N];
pair<int, int> a[N], b[N];

long long dist(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) +
            (a.second - b.second) * (a.second - b.second);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    for(int i = 0; i < m; ++i)
        cin >> b[i].first >> b[i].second;
    
    for(int i = 0; i < m; ++i) {
        long long best = 1e18, idx;
        for(int j = 0; j < n; ++j)
            if(best > dist(b[i], a[j]))
                idx = j, best = dist(b[i], a[j]);
        ++cats[idx];
    }
    
    int res = 0;
    for(int i = 0; i < n; ++i)
        res += cats[i] == 1;
    
    cout << res << endl;
    
    return 0;
}
