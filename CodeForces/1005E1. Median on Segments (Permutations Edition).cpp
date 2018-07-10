/*
  Idea:
    - If we calculate for each index `i` the value cs[i] which is
      represents the difference between the number of elements in `A`
      till index `i` less than `m` subtracted from the number of elements
      in `A` till index `i` greater than `m`, then we can calculate the
      number of indexes `(l, r)` in `A` such that `m` in median.
    - We can calculate the value in the previous point using cumulative sum,
    - Now we can calculate the frequency of each number in `cs` array
      before the index of element `m`,
    - Finally for each index after the index of element `m` we can pair it
      with all indexes before the index of element `m` if and only if
      the difference between `cs[l]` and `cs[r]` is les than or equal to
      1.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, m, idx, sum, a[N], cs[N];
long long res;
map<int, int> fr;

int main() {
  scanf("%d %d", &n, &m);
  idx = -1, sum = 0, res = 0;
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);

    if(a[i] == m)
      idx = i;

    if(idx == -1) {
      sum += a[i] > m;
      sum -= a[i] < m;
      ++fr[sum];
    }
  }

  ++fr[0];
  for(int i = idx; i < n; ++i) {
    sum += a[i] > m;
    sum -= a[i] < m;
    res += fr[sum] + fr[sum - 1];
  }

  printf("%lld\n", res);

  return 0;
}
