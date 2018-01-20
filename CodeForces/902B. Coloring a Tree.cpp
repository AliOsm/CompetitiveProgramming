#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 1;
int c[N];
bool vis[N];
vector<vector<int> > g;

int dfs(int cur, int prv) {
	vis[cur] = true;

	int res = (prv != c[cur]);
	for(int i = 0; i < g[cur].size(); ++i)
		if(!vis[g[cur][i]])
			res += dfs(g[cur][i], c[cur]);

	return res;
}

int main() {
	int n;
	scanf("%d", &n);

	g.resize(n);

	for(int i = 1, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		g[--tmp].push_back(i);
	}

	for(int i = 0; i < n; ++i)
		scanf("%d", c + i);

	printf("%d\n", dfs(0, -1));

	return 0;
}
