/*
  Idea:
    - Using recursion we can build the tree from the input.
    - When the tree is ready to use we can use priority queue
      to track the leaf nodes.
    - Each time we remove a node from the tree we can remove it
      from the `vector` of the parent node.
*/

#include <bits/stdc++.h>

using namespace std;

char s[10001];
int n, len;
vector<int> sol;
vector<vector<int> > g;
priority_queue<int> pq;

int getInt(int idx) {
  int ret = 0;
  while(isdigit(s[idx]))
    ret *= 10, ret += (s[idx++] - '0');
  return ret;
}

void build(int idx, int par) {
  int cur = getInt(idx);
  n = max(n, cur);
  
  if(par != -1)
    g[par].push_back(cur),
    g[cur].push_back(par);

  for(int i = idx, cnt = 1; i < len; ++i) {
    cnt += s[i] == '(';
    cnt -= s[i] == ')';
    if(cnt == 0)
      break;
    if(s[i] == '(' && cnt == 2)
      build(i + 1, cur);
  }
}

void rmv(int from, int target) {
  for(int i = 0; i < g[from].size(); ++i)
    if(g[from][i] == target) {
      g[from].erase(g[from].begin() + i);
      break;
    }
}

int main() {
  while(fgets(s, sizeof s, stdin)) {
    n = 0;
    len = strlen(s);
    g.clear();
    g.resize(1001);
    build(1, -1);

    for(int i = 1; i <= n; ++i)
      if(g[i].size() == 1)
        pq.push(-i);

    sol.clear();
    while(!pq.empty()) {
      int top = -pq.top();
      pq.pop();

      sol.push_back(g[top][0]);
      rmv(g[top][0], top);
      if(g[g[top][0]].size() == 1)
        pq.push(-g[top][0]);
    }

    for(int i = 0; i < int(sol.size()) - 1; ++i)
      printf("%s%d", i == 0 ? "" : " ", sol[i]);
    puts("");
  }

  return 0;
}
