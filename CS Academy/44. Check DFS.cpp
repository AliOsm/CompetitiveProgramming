#include <stdio.h>
#include <vector>

using namespace std;

int const N = 1e5 + 1;
int n, m, p[N], order[N], dfs, dfs_order[N];
bool vis[N];
vector<vector<int> > g;

bool cmp(int a, int b) {
	return order[a] < order[b];
}

void DFS(int v) {
	dfs_order[dfs++] = v;
	vis[v] = true;
	for(int i = 0; i < (int)g[v].size(); ++i)
		if(!vis[g[v][i]])
			DFS(g[v][i]);
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%d", p + i);
		order[p[i]] = i;
	}
	g.resize(n + 1);
	for(int i = 0, a, b; i < m; ++i) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for(int i = 0; i < (int)g.size(); ++i)
		sort(g[i].begin(), g[i].end(), cmp);

	DFS(1);

	bool ok = true;
	for(int i = 0; i < n; ++i)
		if(p[i] != dfs_order[i]) {
			ok = false;
			break;
		}

	printf("%d\n", ok);

    return 0;
}

