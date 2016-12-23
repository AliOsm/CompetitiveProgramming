#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int const N = 201;
int const M = 2 * 1e9 + 1;
int n, m;
pair<int, int> cost[N];
bool vis[N];
vector<vector<pair<int, int> > > g;
priority_queue<pair<int, int> > q;

void Dijkstra(int src) {
    int v, c;
    
    cost[0].first = 0;
    cost[0].second = 0;
    q.push(make_pair(0, src));
    
    while(!q.empty()) {
        v = q.top().second;
        c = -q.top().first;
        q.pop();
        
        if(vis[v]) continue;
        vis[v] = true;
        
        for(int i = 0; i < g[v].size(); i++) {
            if(g[v][i].second + c < cost[g[v][i].first].first) {
                cost[g[v][i].first].first = g[v][i].second + c;
                q.push(make_pair(-cost[g[v][i].first].first, g[v][i].first));
            }
        }
    }
}

int main() {
    while(scanf("%d", &n) && n) {
        scanf("%d", &m);
        
        g.clear();
        g.resize(n);
        while(!q.empty()) q.pop();
        for(int i = 0; i < n; i++) {
            cost[i].first = M;
            cost[i].second = i;
        }
        memset(vis, false, sizeof vis);
        
        int v, u, c;
        
        while(m--) {
            scanf("%d%d%d", &v, &u, &c);
            g[v].push_back(make_pair(u, c));
            g[u].push_back(make_pair(v, c));
        }
        
        Dijkstra(0);
        
        scanf("%d", &v);
        sort(cost, cost + n);
        printf("%d\n", cost[v].second);
    }
}
