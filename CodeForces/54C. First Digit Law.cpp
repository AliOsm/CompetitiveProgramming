/*
  Idea:
    - The solution splitted into two parts.
    - The first part is how to count the number of ones in each range
      of each variable.
    - The second part is how to computer the probability.
    - To solve the first part we can generate the ranges of the good numbers,
      [1, 1]
      [10, 19]
      [100, 199]
      .
      .
      .
      [1000000000000000000, 1999999999999999999]
    - To solve the second part we can do DP, the state is how many
      variables you have take numbers for them till now and how many
      of them start with 1.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;
int n, k;
long long l[N], r[N], ones[N], gl[19], gr[19];
double dp[N][N];

int first_digit(long long x) {
  int ret;
  while(x != 0)
    ret = x % 10, x /= 10;
  return ret;
}

long long bf(int i) {
  long long ret = 0;
  for(long long j = l[i]; j <= r[i]; ++j)
    if(first_digit(j) == 1)
      ++ret;
  return ret;
}

long long calc(int i) {
  long long ret = 0;
  for(int j = 0; j < 19; ++j) {
    if(gl[j] >= l[i] && gr[j] <= r[i])
      ret += gr[j] - gl[j] + 1;
    else if(gl[j] >= l[i] && gl[j] <= r[i])
      ret += r[i] - gl[j] + 1;
    else if(gr[j] >= l[i] && gr[j] <= r[i])
      ret += gr[j] - l[i] + 1;
    else if(l[i] >= gl[j] && r[i] <= gr[j])
      ret += r[i] - l[i] + 1;
  }
  return ret;
}

double rec(int idx, int cnt) {
  if(idx == n)
    return (1.0 * cnt / n * 100.0) >= k;

  double &ret = dp[idx][cnt];
  if(ret == ret)
    return ret;
  ret = 0;

  return ret = 1.0 * ones[idx] / (r[idx] - l[idx] + 1) * rec(idx + 1, cnt + 1) + 1.0 * ((r[idx] - l[idx] + 1) - ones[idx]) / (r[idx] - l[idx] + 1) * rec(idx + 1, cnt);
}

int main() {
  gl[0] = gr[0] = 1;
  for(int i = 1; i < 19; ++i) {
    gl[i] = gl[i - 1] * 10;
    gr[i] = gl[i] * 2 - 1;
  }

  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%lld %lld", l + i, r + i);
    ones[i] = calc(i);
    // cout << ones[i] << ' ' << bf(i) << endl;
  }
  scanf("%d", &k);

  memset(dp, -1, sizeof dp);
  printf("%0.10lf\n", rec(0, 0));

  return 0;
}
