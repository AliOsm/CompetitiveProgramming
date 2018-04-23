#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1, MOD = 1e9 + 7;
int n, m, a[N], dfs, comp, idx[N], low[N];
bool in[N];
vector<int> st;
vector<vector<int> > g, comps;

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
	scanf("%d", &n);
	g.resize(n);
	comps.resize(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);
	scanf("%d", &m);
	for(int i = 0, a, b; i < m; ++i) {
		scanf("%d %d", &a, &b);
		--a, --b;
		g[a].push_back(b);
	}

	memset(idx, -1, sizeof idx);
	memset(in, false, sizeof in);
	dfs = comp = 0;
  for(int i = 0; i < n; i++)
    if(idx[i] == -1)
			DFS(i);

	long long res = 0, ways = 1;
	for(int i = 0; i < comps.size(); ++i, puts("")) {
		if(comps[i].empty())
			break;

		int mnv = 2e9, mni;
		for(int j = 0; j < comps[i].size(); ++j)
			if(a[comps[i][j]] < mnv)
				mnv = a[comps[i][j]], mni = comps[i][j];
		res += a[mni];

		int rep = 0;
		for(int j = 0; j < comps[i].size(); ++j)
			if(a[comps[i][j]] == a[mni])
				++rep;
		ways = ways * rep % MOD;
	}

	printf("%lld %lld\n", res, ways);

  return 0;
}
