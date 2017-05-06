#include <iostream>
#include <string>
#include <sstream>
#include <memory.h>
#include <algorithm>

using namespace std;

int const N = 1e3 + 1;
int w, n, dp[N][N];

int calc(int i, int j) {
  if(i < 0 || i >= w || j < 0 || j >= n)
    return 1e9;
  
  if(i == w - 1 && j == n - 1)
    return 0;
  
  int &res = dp[i][j];
  if(res == -2) return 1e9;
  if(res != -1) return res;
  res = 0;
  
  int r1 = calc(i + 1, j);
  int r2 = calc(i, j + 1);
  
  return res = 1 + min(r1, r2);
}

int paths(int i, int j) {
  if(i < 0 || i >= w || j < 0 || j >= n)
    return 0;
  
  if(i == w - 1 && j == n - 1)
    return 1;
  
  int r1 = 0;
  if(calc(i + 1, j) + 1 == calc(i, j))
    r1 = paths(i + 1, j);
  
  int r2 = 0;
  if(calc(i, j + 1) + 1 == calc(i, j))
    r2 = paths(i, j + 1);
  
  return r1 + r2;
}

int main() {
  bool blankline = false;
  
  int t;
  cin >> t;
  
  string s;
  int tmp;
  while(t-- != 0) {
    if(blankline) cout << endl;
    
    memset(dp, -1, sizeof dp);
    
    cin >> w >> n;
    
    cin.ignore();
    for(int i = 0; i < w; ++i) {
      getline(cin, s);
      stringstream ss(s);
      
      ss >> tmp;
      while(ss >> tmp) {
        --tmp;
        dp[i][tmp] = -2;
      }
    }
    
    calc(0, 0);
    cout << paths(0, 0) << endl;
    
    blankline = true;
  }
  
  return 0;
}

