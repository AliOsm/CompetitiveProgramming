/*
  Idea:
    - If you find the all differences between all elements
      in array `a` where the subtraction result greater than 0,
      then you can choose any two differences as results of
      the first two rounds, then to win the third game by the
      second player and to have sum greater than the sum of the
      first player we should choose a difference greater than
      the sum of the results in the first two round.
    - Calculate the previous point :) and divide it by the
      total number of probabilities.
    - The total number of probabilities equal to:
      ((n * (n - 1)) / 2)^3
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e3 + 1;
int n, a[N], fr[3 * N + 1];
vector<int> diff;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  sort(a, a + n);

  for(int i = 0; i < n; ++i)
    for(int j = i + 1; j < n; ++j)
      diff.push_back(a[j] - a[i]);

  for(int i = 0; i < diff.size(); ++i)
    ++fr[diff[i]];

  for(int i = 1; i <= 3 * N; ++i)
    fr[i] += fr[i - 1];

  long long res = 0, all;
  for(int i = 1, sum; i < 5001; ++i)
    for(int j = 1; j < 5001; ++j) {
      all = 1ll * (fr[i] - fr[i - 1]) * (fr[j] - fr[j - 1]);
      sum = i + j;

      if(all == 0 || sum >= 5000)
        continue;

      res += all * (fr[3 * N] - fr[sum]);
    }

  unsigned long long div = n * (n - 1) / 2;
  div *= n * (n - 1) / 2;
  div *= n * (n - 1) / 2;

  printf("%0.10lf\n", 1.0 * res / div);

  return 0;
}
