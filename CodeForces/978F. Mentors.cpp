#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;
int n, m, a[N], fr[N], cs[N], sol[N];
vector<int> all;
vector<vector<int> > g;

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    cin >> a[i], all.push_back(a[i]);

  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());

  for(int i = 0; i < n; ++i) {
    a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
    ++fr[a[i]];
  }

  for(int i = 1; i < N; ++i)
    cs[i] = cs[i - 1] + fr[i - 1];

  g.resize(n);
  for(int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    swap(a, b);
    g[a].push_back(b);
  }

  for(int i = 0; i < n; ++i) {
    sol[i] = cs[a[i]];

    for(int j = 0; j < g[i].size(); ++j)
      if(a[g[i][j]] < a[i])
        --sol[i];
  }

  for(int i = 0; i < n; ++i)
    cout << sol[i] << ' ';
  cout << endl;

  return 0;
}
