#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <memory.h>

using namespace std;

int const N = 1001;
int n, m, low[N], idx[N], dfs, id;
bool in[N];
vector<int> st;
vector<vector<int> > g;
map<string, int> mp;

void DFS(int v) {
  low[v] = idx[v] = dfs++;
  in[v] = true;
  st.push_back(v);

  for(int i = 0; i < g[v].size(); i++)
    if(idx[g[v][i]] == -1) {
      DFS(g[v][i]);
      low[v] = min(low[v], low[g[v][i]]);
    } else if(in[g[v][i]])
      low[v] = min(low[v], low[g[v][i]]);

  if(low[v] == idx[v]) {
    int node;
    do {
      node = st.back();
      in[node] = false;
      st.pop_back();
    } while(node != v);

    id++;
  }
}

int main() {
  string s1, s2, tmp;
  while(cin >> n >> m && (n || m)) {
    g.clear();
    g.resize(n);
    mp.clear();

    for(int i = 0; i < n; i++) {
      cin >> s1 >> s2;
      mp[(s1 + s2)] = i;
    }

    for(int i = 0; i < m; i++) {
      cin >> s1 >> s2;
      tmp = s1 + s2;
      cin >> s1 >> s2;
      g[mp[tmp]].push_back(mp[(s1 + s2)]);
    }

    memset(idx, -1, sizeof idx);
    memset(in, false, sizeof in);
    st.clear();
    dfs = id = 0;
    for(int i = 0; i < n; i++)
      if(idx[i] == -1)
        DFS(i);

    cout << id << endl;
  }

  return 0;
}

