#include <stdio.h>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

int const N = 1e5 + 1;
int n;
vector<vector<int> > g;
queue<int> q;
bool vis[N];

int BFS(int a, int b) {
    while(!q.empty()) q.pop();
    memset(vis, false, N);
    q.push(a);
    vis[a] = 1;
    int cost = 0, size = 0;
    
    while(!q.empty()) {
        size = q.size();
        while(size--) {
            int fr = q.front();
            q.pop();
            for(int i = 0, len = g[fr].size(); i < len; i++) {
                int v = g[fr][i];
                if(v == b) return cost;
                vis[v] = 1;
                q.push(v);
            }
        }
        cost++;
    };
}

int main() {
    int t, a, b, tmp;
    scanf("%i", &t);
    
    while(t--) {
        scanf("%i", &n);
        g.clear();
        g.resize(n);
        
        for(int i = 0; i < n; i++) {
            scanf("%i %i", &a, &b);
            
            while(b--) {
                scanf("%i", &tmp);
                g[a].push_back(tmp);
            }
        }
        
        scanf("%i %i", &a, &b);
        
        printf("%i %i %i\n", a, b, BFS(a, b));
        
        if(t) putchar('\n');
    }
    
    return 0;
}
