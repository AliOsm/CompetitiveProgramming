/*
  Idea:
    - Using cumulative sum we can try split the array
      in all possible indexes.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, a[N];
long long cs[N];

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  
  for(int i = 1; i <= n; ++i)
    cs[i] = cs[i - 1] + a[i - 1];
  
  long long res = 0;
  for(int i = n, idx; i >= 1; --i) {
    long long cur = cs[n] - cs[i - 1];

    idx = lower_bound(cs, cs + n - (n - i + 1), cur) - cs;
    if(cs[idx] == cur)
      res = max(res, cur);
  }

  cout << res << endl;

  return 0;
}
