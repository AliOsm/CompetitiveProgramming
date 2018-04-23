#include <bits/stdc++.h>

using namespace std;

int const N = 26;
int n, low[N], idx[N], dfs, id;
char q[5], cur;
bool in[N], vis[N];
vector<int> st;
vector<vector<int> > g, comp;

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
      comp[id].push_back(node);
    } while(node != v);

    id++;
  }
}

int main() {
	bool blank = false;
	while(scanf("%d", &n) && n != 0) {
		if(blank)
			puts("");

		memset(vis, false, sizeof vis);
		g.clear();
		g.resize(N);

		while(n-- != 0) {
			for(int i = 0; i < 5; ++i)
				scanf(" %c", q + i);
			scanf(" %c", &cur);
			vis[cur - 'A'] = true;
			for(int i = 0; i < 5; ++i) {
				vis[q[i] - 'A'] = true;
				if(q[i] != cur)
					g[cur - 'A'].push_back(q[i] - 'A');
			}
		}

		comp.clear();
		comp.resize(N);

		memset(idx, -1, sizeof idx);
    memset(in, false, sizeof in);
    dfs = id = 0;
    for(int i = 0; i < N; i++)
      if(vis[i] && idx[i] == -1)
				DFS(i);

		for(int i = 0; i < comp.size(); ++i)
			sort(comp[i].begin(), comp[i].end());
		sort(comp.begin(), comp.end());

		for(int i = 0; i < comp.size(); ++i) {
			if(comp[i].empty())
				continue;
			for(int j = 0; j < comp[i].size(); ++j)
				printf("%s%c", j == 0 ? "" : " ", comp[i][j] + 'A');
			puts("");
		}

		blank = true;
	}

  return 0;
}
