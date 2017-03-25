#include <stdio.h>
#include <memory.h>

using namespace std;

int const N = 101;
int board[N][N];
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
bool uni[N];

int main() {
  int t;
  scanf("%d", &t);
  
  int n, m, nx, ny, res;
  while(t--) {
    memset(uni, false, sizeof uni);
    res = 0;
    
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        scanf("%d", &board[i][j]);
    
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) {
        if(board[i][j] == -1) continue;
        
        for(int k = 0; k < 8; k++) {
          nx = i + dx[k];
          ny = j + dy[k];
          
          if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[i][j] == board[nx][ny])
            uni[board[i][j]] = true;
        }
      }
    
    for(int i = 0; i < N; i++)
      if(uni[i])
        res++;
    
    printf("%d\n", res);
  }
  
  return 0;
}

