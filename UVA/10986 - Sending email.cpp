#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int const N = 2 * 1e4 + 1;
int const M = 2 * 1e9;
int n, m, cost[N];
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
            if(g[v][i].second + c < cost[g[v][i].first]) {
                cost[g[v][i].first] = g[v][i].second + c;
                q.push(make_pair(-(g[v][i].second + c), g[v][i].first));
            }
    }
}

int main() {
    int t, src, dest, i = 1;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d%d%d%d", &n, &m, &src, &dest);
        
        g.clear();
        g.resize(n);
        while(!q.empty()) q.pop();
        for(int i = 0; i < n; i++) cost[i] = M;
        memset(vis, false, sizeof vis);
        
        int v, u, c;
        
        while(m--) {
            scanf("%d%d%d", &v, &u, &c);
            g[v].push_back(make_pair(u, c));
            g[u].push_back(make_pair(v, c));
        }
        
        Dijkstra(src);
        
        printf("Case #%d: ", i++);
        if(cost[dest] == M) puts("unreachable");
        else printf("%d\n", cost[dest]);
    }
    
    return 0;
}
