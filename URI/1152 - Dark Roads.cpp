#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
	int from, to, cost;
	edge(int from, int to, int cost) :
		from(from), to(to), cost(cost) {}
	bool operator<(const edge &e) const {
		return cost < e.cost;
	}
};

int const N = 2e5 + 1;
int n, m, a, b, c, taken, res, ds[N];
vector<edge> edges;

int find(int x) {
	return x == ds[x] ? x : ds[x] = find(ds[x]);
}

int main() {
	while(scanf("%d %d", &n, &m) && n != 0 && m != 0) {
		res = 0;
		edges.clear();
		for(int i = 0; i < m; ++i) {
			scanf("%d %d %d", &a, &b, &c);
			edges.push_back(edge(a, b, c));
			res += c;
		}
		sort(edges.begin(), edges.end());

		for(int i = 0; i < n; ++i)
			ds[i] = i;

		taken = 0;
		for(int i = 0; i < m && taken < n - 1; ++i)
			if(find(edges[i].from) != find(edges[i].to)) {
				ds[find(edges[i].from)] = find(edges[i].to);
				++taken;
				res -= edges[i].cost;
			}

		printf("%d\n", res);
	}

    return 0;
}

