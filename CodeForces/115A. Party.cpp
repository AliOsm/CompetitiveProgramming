#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

int const N = 2001;
vector<vector<int> > g;
queue<int> q;
bool vis[N];

int BFS() {
    int cost = 0, size;
    
    while(!q.empty()) {
        size = q.size();
        
        while(size--) {
            int fr = q.front();
            q.pop();
        
            for(int i = 0; i < g[fr].size(); i++) {
                if(vis[g[fr][i]]) continue;
                vis[g[fr][i]] = true;
                q.push(g[fr][i]);
            }
        }
        
        cost++;
    }
    
    return cost;
}

int main() {
    int n, tmp;
    cin >> n;
    g.resize(n);
    memset(vis, false, sizeof vis);
    
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        
        if(tmp == -1) {
            q.push(i);
            vis[i] = true;
        } else {
            tmp--;
            g[i].push_back(tmp);
            g[tmp].push_back(i);
        }
    }
    
    cout << BFS() << endl;
    
    return 0;
}
