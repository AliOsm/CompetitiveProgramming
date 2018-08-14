/*
  Idea:
    - Using topological sort we can check if there is 0 solutions, 1 solution
      or more than 2 solutions.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;
int n, m, in[N];
vector<vector<int> > g;
queue<int> q;

int main() {
  while(scanf("%d %d", &n, &m) && (n != 0 || m != 0)) {
    memset(in, 0, sizeof in);
    g.clear();
    g.resize(n);
    for(int i = 0, a, b; i < m; ++i) {
      scanf("%d %d", &a, &b);
      --a, --b;
      g[a].push_back(b);
      ++in[b];
    }

    while(!q.empty()) q.pop();

    for(int i = 0; i < n; ++i)
      if(in[i] == 0)
        q.push(i);

    bool two = false;
    int size = 0;
    while(!q.empty()) {
      if(q.size() > 1)
        two = true;

      int fr = q.front();
      q.pop();
      ++size;

      for(int i = 0, v; i < g[fr].size(); ++i) {
        v = g[fr][i];
        if(--in[v] == 0)
          q.push(v);
      }
    }

    if(size != n)
      puts("0");
    else if(two)
      puts("2");
    else
      puts("1");
  }

  return 0;
}
