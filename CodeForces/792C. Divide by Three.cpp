#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

int dp[100001][3][2];
string s, sol;

int calc(int i, int number, bool take) {
  if(i == s.length())
    return (number == 0 && take) ? 0 : 1e7;
  
  int &res = dp[i][number][take];
  if(res != -1) return res;
  
  res = 1 + calc(i + 1, number, take);
  
  if(s[i] == '0') {
    if(take)
      res = min(res, calc(i + 1, (number + (s[i] - '0')) % 3, take));
  } else
    res = min(res, calc(i + 1, (number + (s[i] - '0')) % 3, true));
  
  return res;
}

void path(int i, int number, bool take) {
  if(i == s.length()) return;
  
  int res = calc(i, number, take);
  
  if(res == 1 + calc(i + 1, number, take))
    path(i + 1, number, take);
  else
    if(res == calc(i + 1, (number + (s[i] - '0')) % 3, take)) {
      sol += s[i];
      path(i + 1, (number + (s[i] - '0')) % 3, take);
    } else {
      sol += s[i];
      path(i + 1, (number + (s[i] - '0')) % 3, 1);
    }
}

int main() {
  cin >> s;
  
  memset(dp, -1, sizeof dp);
  int res = calc(0, 0, 0);
  if(res >= 1e7)
    if(s.find('0') != string::npos)
      cout << 0 << endl;
    else
      cout << -1 << endl;
  else {
    path(0, 0, 0);
    cout << sol << endl;
  }
  
  return 0;
}

