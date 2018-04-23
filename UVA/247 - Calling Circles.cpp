#include <bits/stdc++.h>

using namespace std;

int n, m, id, dfs, comp, idx[26], low[26];
bool in[26];
char s[26];
string tmp;
vector<int> st;
vector<vector<int> > g, comps;
map<string, int> mp;
map<int, string> mps;

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
      comps[comp].push_back(node);
    } while(node != v);

    comp++;
  }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	bool blank = false;
	for(int cnt = 1; scanf("%d %d", &n, &m) && n != 0 && m != 0; ++cnt) {
		if(blank)
			puts("");

		printf("Calling circles for data set %d:\n", cnt);
		g.clear();
		g.resize(n);
		comps.clear();
		comps.resize(n);

		id = 0;
		mp.clear();
		mps.clear();
		for(int i = 0, a, b; i < m; ++i) {
			scanf("%s", s);
			tmp = s;
			if(mp.count(tmp) == 0)
				mp[tmp] = id++, mps[id - 1] = tmp;;
			a = mp[tmp];

			scanf("%s", s);
			tmp = s;
			if(mp.count(tmp) == 0)
				mp[tmp] = id++, mps[id - 1] = tmp;
			b = mp[tmp];

			g[a].push_back(b);
		}

		memset(idx, -1, sizeof idx);
		memset(in, false, sizeof in);
		dfs = comp = 0;
    for(int i = 0; i < n; i++)
      if(idx[i] == -1)
				DFS(i);

		for(int i = 0; i < comps.size(); ++i, puts("")) {
			if(comps[i].empty())
				break;
			for(int j = 0; j < comps[i].size(); ++j)
				printf("%s%s", j == 0 ? "" : ", ", mps[comps[i][j]].c_str());
		}

		blank = true;
	}

  return 0;
}
