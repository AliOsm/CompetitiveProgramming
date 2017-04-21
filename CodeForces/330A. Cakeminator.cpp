#include <stdio.h>

using namespace std;

char board[11][11];
bool rows[10], cols[10];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      scanf(" %c", &board[i][j]);
      if(board[i][j] == 'S')
        rows[i] = cols[j] = true;
    }

  int res = 0;

  for(int i = 0; i < n; i++)
    if(!rows[i])
      for(int j = 0; j < m; j++) {
        res += (board[i][j] != '#');
        board[i][j] = '#';
      }

  for(int i = 0; i < m; i++)
    if(!cols[i])
      for(int j = 0; j < n; j++) {
        res += (board[j][i] != '#');
        board[j][i] = '#';
      }

  printf("%d\n", res);

  return 0;
}

