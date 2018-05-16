#include <bits/stdc++.h>

using namespace std;

int const N = 51;
int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char s[N][N];
bool vis[N][N];

void DFS(int i, int j) {
    vis[i][j] = true;
    
    for(int k = 0, nx, ny; k < 4; ++k) {
        nx = i + dx[k];
        ny = j + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || s[nx][ny] == '.')
            continue;
        DFS(nx, ny);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    
    int tmp = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            tmp += (s[i][j] == '#');
    if(tmp <= 2) {
        puts("-1");
        return 0;
    }
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(s[i][j] == '#') {
                memset(vis, false, sizeof vis);
                s[i][j] = '.';
                int comp = 0;
                for(int k = 0; k < n; ++k)
                    for(int l = 0; l < m; ++l)
                        if(!vis[k][l] && s[k][l] == '#') {
                            ++comp;
                            DFS(k, l);
                        }
                if(comp > 1) {
                    puts("1");
                    return 0;
                }
                s[i][j] = '#';
            }
    
    puts("2");
    
    return 0;
}
