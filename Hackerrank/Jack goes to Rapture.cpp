#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;

int const N = 5 * 1e4 + 1;
long long const M = 1e18 + 1;
int n, m;
long long cost[N];
bool vis[N];
vector<vector<pair<int, int> > > g;
priority_queue<pair<int, int> > q;

void Dijkstra(int src) {
    int v, c;
    
    cost[src] = 0;
    q.push(make_pair(0, src));
    
    while(!q.empty()) {
        v = q.top().second;
        c = -q.top().first;
        q.pop();
        
        if(vis[v]) continue;
        vis[v] = true;
        
        for(int i = 0; i < g[v].size(); i++)
            if(max(g[v][i].second, c) < cost[g[v][i].first])
                if(g[v][i].second - c < 0) {
                    cost[g[v][i].first] = c;
                    q.push(make_pair(-c, g[v][i].first));
                } else {
                    cost[g[v][i].first] = max(g[v][i].second, c);
                    q.push(make_pair(-(max(g[v][i].second, c)), g[v][i].first));
                }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    g.clear();
    g.resize(n);
    for(int i = 0; i < n; i++) cost[i] = M;
    memset(vis, false, sizeof vis);

    int v, u, c;

    while(m--) {
        scanf("%d%d%d", &v, &u, &c);
        v--; u--;
        g[v].push_back(make_pair(u, c));
        g[u].push_back(make_pair(v, c));
    }

    Dijkstra(0);
    if(cost[n-1] == M) puts("NO PATH EXISTS");
    else printf("%lld\n", cost[n-1]);
    
    return 0;
}
