#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

bool vis[26];
vector<vector<int> > g, comps;
vector<int> tmp;

void DFS(int node) {
	tmp.push_back(node);
	vis[node] = true;

	for(int i = 0; i < (int)g[node].size(); ++i)
		if(!vis[g[node][i]])
			DFS(g[node][i]);
}

int main() {
	int t;
	scanf("%d", &t);
	int n, m;
	char a, b;
	for(int cnt = 1; t-- != 0; ++cnt) {
		scanf("%d %d", &n, &m);

		g.clear();
		g.resize(n);
		for(int i = 0; i < m; ++i) {
			scanf(" %c %c", &a, &b);
			g[a - 'a'].push_back(b - 'a');
			g[b - 'a'].push_back(a - 'a');
		}

		memset(vis, false, sizeof vis);
		comps.clear();
		for(int i = 0; i < n; ++i)
			if(!vis[i]) {
				tmp.clear();
				DFS(i);
				comps.push_back(tmp);
			}

		printf("Case #%d:\n", cnt);
		for(int i = 0; i < (int)comps.size(); ++i, puts("")) {
			sort(comps[i].begin(), comps[i].end());
			for(int j = 0; j < (int)comps[i].size(); ++j)
				printf("%c,", char(comps[i][j] + 'a'));
		}
		printf("%d connected components\n\n", (int)comps.size());
	}

	return 0;
}

