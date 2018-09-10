/*
  Idea:
    - Brute force the divisors of the first pair, is there is no
      answer, then print "No", otherwise print "Yes".
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n;
pair<int, int> a[N];
vector<int> d;
set<int> st;

void calc_div(int x) {
  d.clear();
  int sqrtx = sqrt(x) + 1;
  for(int i = 1; i <= sqrtx; ++i) {
    if(x % i == 0) {
      d.push_back(i);

      if(x / i != i)
        d.push_back(x / i);
    }
  }
}

void solve() {
  for(int i = 0, cur, dd; i < d.size(); ++i) {
    if(d[i] == 1)
      continue;
    cur = 0;
    dd = d[i];

    if(st.count(dd) == 1)
      continue;
    st.insert(dd);

    for(int j = 1; j < n; ++j)
      if(a[j].first % dd == 0 || a[j].second % dd == 0)
        ++cur;
      else
        break;

    if(cur == n - 1) {
      printf("%d\n", dd);
      exit(0);
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d %d", &a[i].first, &a[i].second);

  sort(a, a + n);
  reverse(a, a + n);

  calc_div(a[0].first);
  solve();

  calc_div(a[0].second);
  solve();

  puts("-1");

  return 0;
}
