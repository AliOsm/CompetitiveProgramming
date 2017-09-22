#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1, oo = 2e9;
int n, m, q, k, x, y, s1, s2;
vector<vector<int> > g;

void DFS(int v, int p, int lvl) {
	s1 += (lvl % 2 == 0);
	s2 += (lvl % 2 == 1);

	for(int i = 0; i < (int)g[v].size(); ++i) {
		int u = g[v][i];
		if(u != p)
			DFS(u, v, lvl + 1);
	}
}

int main() {
	scanf("%d", &n);
	g.resize(n);
	for(int i = 0, a, b; i < n - 1; ++i) {
		scanf("%d %d", &a, &b);
		--a, --b;
		g[a].push_back(b);
		swap(a, b);
		g[a].push_back(b);
	}

	DFS(0, -1, 0);

	printf("%lld\n", (1ll * s1 * s2) - (n - 1));

	return 0;
}
