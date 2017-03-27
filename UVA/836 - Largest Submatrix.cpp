#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 26;
int n, m, cum[N][N];
vector<string> board;

int main() {
  bool blankline = false;
  
  int t;
  cin >> t;
  
  cin.ignore();
  
  string tmp;
  getline(cin, tmp);
  while(t--) {
    if(blankline) cout << '\n';
    
    board.clear();
    
    while(getline(cin, tmp) && tmp != "")
      board.push_back(tmp);
    
    n = board.size();
    m = board[0].length();
    
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) {
        cum[i][j] = board[i][j] - '0';
        
        if(i > 0) cum[i][j] += cum[i-1][j];
        if(j > 0) cum[i][j] += cum[i][j-1];
        if(i > 0 && j > 0) cum[i][j] -= cum[i-1][j-1];
      }
    
    int res = 0, tmp;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
      for(int k = i; k < n; k++) for(int l = j; l < m; l++) {
        tmp = cum[k][l];
        
        if(i > 0) tmp -= cum[i-1][l];
        if(j > 0) tmp -= cum[k][j-1];
        if(i > 0 && j > 0) tmp += cum[i-1][j-1];
        
        if(tmp == (k - i + 1) * (l - j + 1))
          res = max(res, tmp);
      }
    
    cout << res << '\n';
    
    blankline = true;
  }
  
  return 0;
}
