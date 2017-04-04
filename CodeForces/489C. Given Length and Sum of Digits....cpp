#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

string res;
bool go;
int m, s, dp[101][901][2];

bool calc1(int idx, int sum, bool taken) {
  if(sum > s) return false;
  if(idx == m && sum != s) return false;
  
  if(idx == m && sum == s) {
    go = false;
    return true;
  }
  
  int &ret = dp[idx][sum][taken];
  if(ret != -1) return ret;
  ret = false;
  
  for(int i = 0; go && i <= 9; i++) {
    if(!i) {
      if(taken) {
        res += char('0' + i);
        ret = calc1(idx + 1, sum + i, taken);
        if(ret) return true;
        res.pop_back();
      }
    } else {
      res += char('0' + i);
      ret = calc1(idx + 1, sum + i, 1);
      if(ret) return true;
      res.pop_back();
    }
  }
  
  return ret;
}

bool calc2(int idx, int sum, bool taken) {
  if(sum > s) return false;
  if(idx == m && sum != s) return false;
  
  if(idx == m && sum == s) {
    go = false;
    return true;
  }
  
  int &ret = dp[idx][sum][taken];
  if(ret != -1) return ret;
  ret = false;
  
  for(int i = 9; go && i >= 0; i--) {
    if(!i) {
      if(taken) {
        res += char('0' + i);
        ret = calc2(idx + 1, sum + i, taken);
        if(ret) return true;
        res.pop_back();
      }
    } else {
      res += char('0' + i);
      ret = calc2(idx + 1, sum + i, 1);
      if(ret) return true;
      res.pop_back();
    }
  }
  
  return ret;
}

int main() {
  cin >> m >> s;
  
  if(m == 1 && s == 0) {
    cout << 0 << ' ' << 0 << endl;
    return 0;
  }
  
  res = "";
  go = true;
  memset(dp, -1, sizeof dp);
  if(calc1(0, 0, 0)) cout << res << ' ';
  else cout << -1 << ' ';
  
  res = "";
  go = true;
  memset(dp, -1, sizeof dp);
  if(calc2(0, 0, 0)) cout << res << endl;
  else cout << -1 << endl;
  
  return 0;
}

