#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;

int const N = 101;
vector<vector<int> > g;
vector<int> res;
bool vis[N];

void DFS(int src) {
    for(int i = 0; i < g[src].size(); i++)
        if(!vis[g[src][i]]) {
            vis[g[src][i]] = true;
            DFS(g[src][i]);
        }
}

int main() {
    int n;
    
    while(scanf("%d", &n) == 1 && n) {
        g.clear();
        g.resize(n);
        
        int a, b, c;
        
        while(scanf("%d", &a) == 1 && a) {
            a--;
            while(scanf("%d", &b) == 1 && b)
                g[a].push_back(--b);
        }
        
        scanf("%d", &a);
        
        while(a--) {
            res.clear();
            memset(vis, false, sizeof vis);
            scanf("%d", &b);
            DFS(--b);
            
            c = 0;
            
            for(int i = 0; i < n; i++)
                if(!vis[i]) {
                    c++;
                    res.push_back(i+1);
                }
            
            printf("%d", c);
            for(int i = 0; i < res.size(); i++)
                printf(" %d", res[i]);
            putchar('\n');
        }
    }
    
    return 0;
}
