#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m;
bool vis[N];
vector<vector<int> > g;

void dfs(int v, int l) {
    vis[v] = true;
    if(l == 0)
        cout << v + 1 << ' ';
    
    for(int i = 0; i < g[v].size(); ++i)
        if(!vis[g[v][i]])
            dfs(g[v][i], l == 0 ? m / 3 - 1 : l - 1);
}

int main() {
    cin >> n >> m;
    g.resize(n);
    for(int i = 0, from, to; i < m; ++i) {
        cin >> from >> to;
        --from, --to;
        g[from].push_back(to);
        swap(from, to);
        g[from].push_back(to);
    }
    
    bool ok = true;
    for(int i = 0; i < n; ++i) {
        if(g[i].size() >= 3) {
            for(int j = 0; j < 3; ++j)
                cout << g[i][j] + 1 << ' ';
            cout << endl;
            return 0;
        }
        
        if(g[i].size() <= 1)
            ok = false;
    }
    
    if(!ok || m % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }
    
    dfs(0, 0);
    
    return 0;
}
