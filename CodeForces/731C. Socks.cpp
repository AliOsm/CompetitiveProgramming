#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int const N = 2e5 + 1;
int nodes, mx;
vector<int> a;
vector<vector<int> > g;
map<int, int> freq;
bool vis[N][2];

void DFS(int n, bool type) {
	vis[n][type] = 1;

	if (type) {
		nodes++;
		mx = max(mx, ++freq[a[n]]);
	}
	else
		freq[a[n]] = 0;

	for (int i = 0; i < g[n].size(); i++)
		if (!vis[g[n][i]][type])
			DFS(g[n][i], type);
}

int main() {
	freopen("input.txt", "r", stdin);

	int n, m, k;
	cin >> n >> m >> k;

	a.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	g.resize(n + 1);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i][0]) {
			nodes = mx = 0;
			DFS(i, true);
			res += nodes - mx;
			DFS(i, false);
		}
	}

	cout << res << endl;

	return 0;
}
