#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int const N = 1e5 + 1;
int n, m, k, res;
long long cost[N];
bool vis[N];
vector<vector<pair<int, int> > > g;
priority_queue<pair<pair<long long, int>, bool> > q;

void Dijkstra(int src) {
	fill(cost, cost + N, 1e18);
	q.push(make_pair(make_pair(0, src), false));
	cost[src] = 0;

	while(!q.empty()) {
		int v = q.top().first.second;
		long long c = -q.top().first.first;
		bool train = q.top().second;
		q.pop();

		if(cost[v] <= c && train) {
			++res;
			continue;
		} else if(cost[v] > c && train)
			cost[v] = c;

		if(vis[v])
			continue;
		vis[v] = true;

		for(int i = 0, u; i < (int)g[v].size(); ++i) {
			u = g[v][i].first;
			if(1LL * c + g[v][i].second < cost[u]) {
				cost[u] = 1LL * c + g[v][i].second;
				q.push(make_pair(make_pair(-cost[u], u), false));
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	g.resize(n);

	for(int i = 0, a, b, c; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		--a, --b;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}

	for(int i = 0, a, c; i < k; ++i) {
		scanf("%d %d", &a, &c);
		--a;
		q.push(make_pair(make_pair(-c, a), true));
	}

	Dijkstra(0);

	printf("%d\n", res);

	return 0;
}

