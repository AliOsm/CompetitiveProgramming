#include <iostream>
#include <vector>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++)
       cin >> grid[i];
    
    int nx, ny;
    bool f;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            f = true;
            for(int k = 0; k < 4; k++) {
                nx = i + dx[k];
                ny = j + dy[k];
                
                if(!(nx < n && nx >= 0 && ny < n && ny >= 0 && grid[nx][ny] != 'X' && grid[nx][ny] < grid[i][j])) {
                    f = false;
                    break;
                }
            }
            if(f) grid[i][j] = 'X';
        }
    }
    
    for(int i = 0; i < n; i++)
       cout << grid[i] << endl;
    
    return 0;
}
