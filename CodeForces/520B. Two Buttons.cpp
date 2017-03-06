#include <iostream>
#include <queue>
#include <cmath>
#include <memory.h>

using namespace std;

int n, m;
const int N = 1e5;
bool vis[N];
queue<int> q;

int BFS() {
    memset(vis, false, sizeof vis);
    
    q.push(n);
    
    int cost = 0, size;
    
    while(!q.empty()) {
        size = q.size();
        
        while(size--) {
            int fr = q.front();
            vis[fr] = true;
            q.pop();
            
            if(fr == m) return cost;
            
            if(fr - 1 > 0 && !vis[fr - 1]) q.push(fr - 1);
            if(fr * 2 <= m * 2 && !vis[fr * 2]) q.push(fr * 2);
        }
        
        cost++;
    }
}

int main() {
    cin >> n >> m;
    
    cout << BFS() << endl;
    
    return 0;
}
