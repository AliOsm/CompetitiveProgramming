#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

int const N = 10;
int n, m, p, i, j, res;
string board[N];
bool vis[N][N];

bool DFS(int &i, int &j, int &res) {
    if(vis[i][j]) return true;
    vis[i][j] = true;
    res++;
    
    if(board[i][j] == 'N' && i - 1 >= 0)
        return DFS(--i, j, res);
    else if(board[i][j] == 'S' && i + 1 < n)
        return DFS(++i, j, res);
    else if(board[i][j] == 'E' && j + 1 < m)
        return DFS(i, ++j, res);
    else if(board[i][j] == 'W' && j - 1 >= 0)
        return DFS(i, --j, res);
    else
        return false;
}

int main() {
    while(cin >> n >> m >> p && n && m && p) {
        for(int i = 0; i < n; i++) cin >> board[i];
        
        memset(vis, false, sizeof vis);
        i = 0;
        j = p - 1;
        res = 0;
        
        if(DFS(i, j, res)) {
            memset(vis, false, sizeof vis);
            p = 0;
            DFS(i, j, p);
            cout << res - p << " step(s) before a loop of " << p << " step(s)" << endl;
        } else
            cout << res << " step(s) to exit" << endl;
    }
    
    return 0;
}
