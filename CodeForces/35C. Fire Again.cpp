#include <stdio.h>
#include <queue>

using namespace std;

pair<int, int> res;
int n, m, k;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool vis[2001][2001];
queue<pair<int, int> > q;

void BFS() {
    while(!q.empty()) {
        int x, y, nx, ny;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if(vis[x][y]) continue;
        vis[x][y] = true;
        
        res.first = x;
        res.second = y;
        
        for(int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
                q.push(make_pair(nx, ny));
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int a, b;
    scanf("%d%d%d", &n, &m, &k);
    
    while(k--) {
        scanf("%d%d", &a, &b);
        a--; b--;
        q.push(make_pair(a, b));
    }
    
    BFS();
    
    printf("%d %d", res.first + 1, res.second + 1);
}
