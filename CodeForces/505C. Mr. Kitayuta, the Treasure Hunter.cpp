/*
  Idea:
    - Dynamic Programming.
    - The regular DP using NxN time and memory complexity does not work. It is give correct solutions, but it does not fit the time
      and memory limits.
    - To change this solution to accepted one we need to reduce the size of our DP, we need the index where we are now, but the
      distance we want to jump we can always write it as d + offset, where d is the original d from the question and offset if some
      value maybe negative or positive. Now we can take the offset with us in the DP and leave d, but what is the lower and upper
      limits for offset?
    - To calculate this imagine that we always take the +1 step, so in the first step we are add d then add d + 1, d + 2, ..., d + x.
    - x value equals to ~245, why? because (d + (d + 1) + (d + 2) + ... + (d + 245)) = 30135 > 30001 (d = 1), so we can take the offset
      in the DP array and solve the problem.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 3e4 + 10;
int n, d, a[N], dp[N][600];

int rec(int cur, int off) {
  if(cur >= N)
    return 0;
  
  int &ret = dp[cur][300 + off];
  if(ret != -1)
    return ret;
  ret = 0;

  if(cur + d + off - 1 > cur)
    ret = max(ret, rec(cur + (d + off - 1), off - 1) + a[cur]);
  ret = max(ret, rec(cur + d + off, off) + a[cur]);
  ret = max(ret, rec(cur + (d + off + 1), off + 1) + a[cur]);

  return ret;
}

int main() {
  scanf("%d %d", &n, &d);
  for(int i = 0, tmp; i < n; ++i) {
    scanf("%d", &tmp);
    ++a[tmp];
  }

  memset(dp, -1, sizeof dp);
  printf("%d\n", rec(d, 0));

  return 0;
}
