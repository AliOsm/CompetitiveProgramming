#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int const N = 1e5 + 1;
int tmp;
bool vis[N];
vector<vector<int> > g;
vector<int> sols;

void DFS(int n) {
    vis[n] = true;
    tmp++;
    
    for(int i = 0; i < g[n].size(); i++)
        if(!vis[g[n][i]])
            DFS(g[n][i]);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    g.resize(n);
    
    int a, b;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int comps = 0;
    
    for(int i = 0; i < n; i++)
        if(!vis[i]) {
            comps++;
            tmp = 0;
            DFS(i);
            sols.push_back(tmp);
        }
    
    long long res = 0, sum = 0, rev = 0;
    
    // [1, 2, 3, 4]
    
    // (1 * 2) + (1 * 3) + (1 * 4) + (2 * 3) + (2 * 4) + (3 * 4)
    // 1 * (2 + 3 + 4) + 2 * (3 + 4) + 3 * (4)
    
    for(int i = 0; i < comps; i++)
        sum += sols[i];
    
    for(int i = 0; i < comps - 1; i++)  {
        sum -= sols[i];
        res += sols[i] * sum;
    }
    
    printf("%lld\n", res); 
    
    return 0;
}
