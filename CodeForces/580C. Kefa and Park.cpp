#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m;
bool cat[N];
vector<vector<int> > g;

int dfs(int v, int p, int c, bool f) {
	if(c > m)
		return 0;

	int res = 0;
	bool ok = false;
	for(int i = 0; i < (int)g[v].size(); ++i) {
		int u = g[v][i];
		if(u != p) {
			ok = true;
			if(f && cat[u])
				res += dfs(u, v, c + 1, true);
			else if(!f && cat[u])
				res += dfs(u, v, 1, true);
			else
				res += dfs(u, v, 0, false);
		}
	}
	if(!ok)
		return 1;
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	g.resize(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", cat + i);
	for(int i = 1, a, b; i < n; ++i) {
		scanf("%d %d", &a, &b);
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	printf("%d\n", dfs(0, -1, cat[0], cat[0]));

	return 0;
}

