#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int n, m;
bool vis[20], blankline;
vector<vector<int> > g;

void DFS(int node, int depth) {
	vis[node] = true;

	for(int i = 0; i < (int)g[node].size(); ++i)
		if(!vis[g[node][i]]) {
			blankline = true;
			for(int j = 0; j < depth; ++j)
				printf("  ");
			printf("%d-%d pathR(G,%d)\n", node, g[node][i], g[node][i]);
			DFS(g[node][i], depth + 1);
		} else {
			for(int j = 0; j < depth; ++j)
				printf("  ");
			printf("%d-%d\n", node, g[node][i]);
		}
}

int main() {
	int t;
	scanf("%d", &t);
	for(int cnt = 1; t-- != 0; ++cnt) {
		scanf("%d %d", &n, &m);
		g.clear();
		g.resize(n);
		for(int i = 0, a, b; i < m; ++i) {
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
		}

		for(int i = 0; i < n; ++i)
			sort(g[i].begin(), g[i].end());

		printf("Caso %d:\n", cnt);

		memset(vis, false, sizeof vis);
		for(int i = 0; i < n; ++i)
			if(!vis[i]) {
				blankline = false;
				DFS(i, 1);
				blankline ? puts("") : NULL;
			}
	}

	return 0;
}

