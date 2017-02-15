#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

const int N = 101;
int n, m;
vector<vector<int> > g;
pair<int, int> dp[N];

pair<int, int> max(pair<int, int> a, pair<int, int> b) {
    if(b.first > a.first) return b;
    if(a.first > b.first) return a;
    
    if(b.second < a.second) return b;
    if(a.second < b.second) return a;
}

pair<int, int> calc(int m) {
    pair<int, int> &res = dp[m];
    if(res.first != -1) return dp[m];
    res.first = 0;
    res.second = m;
    
    pair<int, int> tmp;
    for(int i = 0; i < g[m].size(); i++) {
        tmp = calc(g[m][i]);
        tmp.first++;
        res = max(res, tmp);
    }
    
    return res;
}

int main() {
    int a, b;
    
    for(int i = 1; cin >> n && n; i++) {
        cin >> m;
        m--;
        
        g.clear();
        g.resize(n);
        
        while(cin >> a >> b && a && b) {
            a--; b--;
            g[a].push_back(b);
        }
        
        memset(dp, -1, sizeof dp);
        cout << "Case " << i << ": The longest path from " << m + 1 << " has length " << calc(m).first << ", finishing at " << calc(m).second + 1 << "." << endl << endl;
    }
    
    return 0;
}
