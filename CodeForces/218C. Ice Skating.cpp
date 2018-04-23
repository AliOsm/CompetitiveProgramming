#include <bits/stdc++.h>

using namespace std;

int n, a[101], b[101];
bool vis[101];
vector<vector<int> > g;

void dfs(int v) {
	vis[v] = true;

	for(int i = 0, u; i < g[v].size(); ++i) {
		u = g[v][i];
		if(!vis[u])
			dfs(u);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d %d", a + i, b + i);

	g.resize(n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(a[i] == a[j] || b[i] == b[j]) {
				g[i].push_back(j);
				g[j].push_back(i);
			}

	int res = 0;
	for(int i = 0; i < n; ++i)
		if(!vis[i]) {
			++res;
			dfs(i);
		}

	printf("%d\n", res - 1);

  return 0;
}
