#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int const N = 1e5 + 1;
long long const M = 1e5 * 1e6 + 1;
int n, m, parent[N];
long long cost[N];
bool vis[N];
vector<vector<pair<int, int> > > g;
vector<int> res;
priority_queue<pair<long long, int> > qu;

void Dijkstra(int src) {
    while(!qu.empty()) qu.pop();
    for(int i = 0; i < n; i++) cost[i] = M;
    cost[src] = 0;
    qu.push(make_pair(0, src));
    
    while(!qu.empty()) {
        int v = qu.top().second;
        long long c = -qu.top().first;
        
        qu.pop();
        if(vis[v]) continue;
        vis[v] = true;
        
        for(int i = 0; i < g[v].size(); i++)
            if(g[v][i].second + c < cost[g[v][i].first]) {
                parent[g[v][i].first] = v;
                cost[g[v][i].first] = g[v][i].second + c;
                qu.push(make_pair(-(g[v][i].second + c), g[v][i].first));
            }
    }
}

int main() {
    int u, v, c;
    
    cin >> n >> m;
    g.resize(n);
    
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        u--; v--;
        g[u].push_back(make_pair(v, c));
        g[v].push_back(make_pair(u, c));
    }
    
    Dijkstra(0);
    
    if(cost[n - 1] == M) cout << -1 << endl;
    else {
        v = n - 1;
        
        while (v != 0) {
            res.push_back(v + 1);
            v = parent[v];
        }
        
        res.push_back(1);

        for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << ' ';
        cout << endl;
    }
    
    return 0;
}
