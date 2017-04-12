#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int const OO = 1e9 + 7;
int n, k, d, dp[101][2];

int calc(int sum, bool take) {
  if(sum == n) return take;
  if(sum > n) return 0;
  
  int &ret = dp[sum][take];
  if(ret != -1) return ret;
  ret = 0;
  
  for(int i = 1; i <= k; i++)
    ret = (ret += calc(sum + i, (take || (i >= d)))) % OO;
  
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &k, &d);
  
  memset(dp, -1, sizeof dp);
  printf("%d\n", calc(0, 0));
  
  return 0;
}

