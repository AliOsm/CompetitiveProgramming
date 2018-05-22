/*
  Idea:
    - Greedy.
    - Sort the given array and try to find the maximum number of elements
      such that the subtraction value between the maximum and the minimum
      is less than or equal to `l`.
    - From the set of elements in the previous step we need to choose `n`
      of them to use them as the minimum staves in each barrel.
*/

#include <bits/stdc++.h>

using namespace std;

int n, k, l, mn = 2e9, have, a[100001];

int main() {
  cin >> n >> k >> l;
  for(int i = 0; i < n * k; ++i) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }

  sort(a, a + n * k);
  for(int i = 0; i < n * k; ++i) {
    if(a[i] - mn > l)
      break;
    have = i + 1;
  }

  if(have < n) {
    puts("0");
    return 0;
  }

  int rem = n * k - have, take = 0;
  long long tot = 0;
  for(int i = have - 1; take < n && i >= 0; --i) {
    if(rem < k - 1) {
      ++rem;
      continue;
    }
    rem -= k - 1;
    tot += a[i];
    ++take;
  }

  cout << tot << endl;

  return 0;
}
