#include <iostream>

using namespace std;

int const N = 101;
int board[N][N];

int main() {
  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
      
      if(i > 0) board[i][j] += board[i - 1][j];
      if(j > 0) board[i][j] += board[i][j - 1];
      if(i > 0 && j > 0) board[i][j] -= board[i - 1][j - 1];
    }
  
  int res = -1e9;
  
  for(int i = 0, tmp; i < n; i++) for(int j = 0; j < n; j++)
    for(int k = i; k < n; k++) for(int l = j; l < n; l++) {
      tmp = board[k][l];
      
      if(i > 0) tmp -= board[i - 1][l];
      if(j > 0) tmp -= board[k][j - 1];
      if(i > 0 && j > 0) tmp += board[i - 1][j - 1];
      
      res = max(res, tmp);
    }
  
  cout << res << endl;
  
  return 0;
}

