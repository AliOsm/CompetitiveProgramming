/*
  Idea:
    - We need to count how many pair of points in the same x-axis or y-axis.
    - We can do this using frequency arrays for x-axis and y-axis.
    - We need to subtract the number of invalid pairs when more than one point
      lies on the same coordinate.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, x[N], y[N], fr[2 * N][2];
vector<int> all;
map<pair<int, int>, int > mp;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
  	scanf("%d %d", x + i, y + i);
  	all.push_back(x[i]);
  	all.push_back(y[i]);
  }

  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());

  for(int i = 0; i < n; ++i) {
  	x[i] = lower_bound(all.begin(), all.end(), x[i]) - all.begin();
  	y[i] = lower_bound(all.begin(), all.end(), y[i]) - all.begin();
  	++fr[x[i]][0], ++fr[y[i]][1];
  	++mp[make_pair(x[i], y[i])];
  }

  long long sub = 0;
  for(map<pair<int, int>, int >::iterator it = mp.begin(); it != mp.end(); ++it)
  	sub += 1ll * it->second * (it->second - 1) / 2;

  long long res = 0;
  for(int i = 0; i < 2 * N; ++i) {
  	res += 1ll * fr[i][0] * (fr[i][0] - 1) / 2;
  	res += 1ll * fr[i][1] * (fr[i][1] - 1) / 2;
  }

  printf("%lld\n", res - sub);

  return 0;
}
