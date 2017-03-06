#include <iostream>
#include <string>

using namespace std;

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int n, m;
string wall[101];

void DFS(int i, int j) {
    wall[i][j] = '.';
    
    for(int k = 0; k < 8; k++) {
        int nx, ny;
        nx = i + dx[k];
        ny = j + dy[k];
        
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && wall[nx][ny] != '.')
            DFS(nx, ny);
    }
}

int main() {
    int c = 0;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) cin >> wall[i];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(wall[i][j] == 'B') {
                c++;
                DFS(i, j);
            }
    
    cout << c << endl;
    
    return 0;
}
