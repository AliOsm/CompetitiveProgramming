#include <bits/stdc++.h>

using namespace std;

int n, dp[int(1e6 + 1)][2];

int rec(int sum, bool f) {
  if(sum > n)
    return 1e9;
  
  if(sum == n)
    return 0;
  
  int &ret = dp[sum][f];
  if(ret != -1)
    return ret;
  ret = 0;
  
  ret = min(rec(sum + (!f ? 4 : 7), 0) + 1, rec(sum + (!f ? 4 : 7), 1) + 1);
  
  return ret;
}

void print(int sum, bool f) {
  if(sum > n)
    return;
  
  if(sum == n)
    return;
  
  if(!f)
    putchar('4');
  else
    putchar('7');
  
  int opt = min(rec(sum + (!f ? 4 : 7), 0) + 1, rec(sum + (!f ? 4 : 7), 1) + 1);
  
  if(opt == rec(sum + (!f ? 4 : 7), 0) + 1)
    print(sum + (!f ? 4 : 7), 0);
  else
    print(sum + (!f ? 4 : 7), 1);
}

int main() {
  scanf("%d", &n);
  memset(dp, -1, sizeof dp);
  int mn = min(rec(0, 0), rec(0, 1));
  if(mn >= 1e9) {
    puts("-1");
    return 0;
  } else if(mn == rec(0, 0))
    print(0, 0);
  else
    print(0, 1);
  puts("");
  
  return 0;
}
