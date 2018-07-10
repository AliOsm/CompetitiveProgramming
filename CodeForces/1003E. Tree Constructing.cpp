/*
  Idea:
    - Greedy.
    - Create chain tree with `d + 1` nodes.
    - Each node in the chain can connected to another chain with length
      equal to `min(node_number - 1, (d + 1) - node_number)`
    - After the last step you have created the biggest tree you can create
      with diameter equal to `d`.
    - Now iterate over the nodes and try to connect the remaining nodes
      to them without make the diameter bigger than `d`.
    - If you cannot do it, then print NO.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 4e5 + 1;
int n, d, k, fr[N], p[N];
vector<pair<int, int> > edges;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif

  scanf("%d %d %d", &n, &d, &k);

  if(n < d + 1) {
    puts("NO");
    return 0;
  }

  for(int i = 1; i <= n; ++i)
    fr[i] = k;

  int s = 1, e = d + 1;

  for(int i = 1; i < e; ++i) {
    if(fr[i] > 0 && fr[i + 1] > 0) {
      edges.push_back({i, i + 1});
      --fr[i], --fr[i + 1];
      p[i] = max(i - s, e - i);
    } else {
      puts("NO");
      return 0;
    }
  }

  int cnt = e;
  for(int i = s + 1, cur, node; i < e; ++i) {
    cur = min(i - s, e - i), node = i;
    while(cnt < n && cur > 0 && fr[node] > 0) {
      if(fr[cnt + 1] < 1) {
        puts("NO");
        return 0;
      }

      edges.push_back({node, ++cnt});
      --fr[node], --fr[cnt];
      --cur;
      p[cnt] = p[node] + 1;
      node = cnt;
    }
  }

  for(int i = 1; i <= n; ++i) {
    if(i == s || i == e || p[i] == d)
      continue;
    while(cnt < n && fr[i] > 0) {
      if(cnt + 1 == i || fr[cnt + 1] < 1)
        break;
      edges.push_back({i, ++cnt});
      --fr[i], --fr[cnt];
      p[cnt] = p[i] + 1;
    }
  }

  if(edges.size() != n - 1 && cnt < n) {
    puts("NO");
    return 0;
  }

  puts("YES");
  for(int i = 0; i < edges.size(); ++i)
    printf("%d %d\n", edges[i].first, edges[i].second);

  return 0;
}
