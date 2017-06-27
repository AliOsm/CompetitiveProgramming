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

int n, m, to, ta, ds[61];
vector<edge> edges;

int find(int x) {
	return ds[x] == x ? x : ds[x] = find(ds[x]);
}

int main() {
	for(int i = 0; i < 61; ++i)
		ds[i] = i;

	scanf("%d %d", &n, &m);
	for(int i = 0, a, b, c; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back(edge(a, b, c));
	}
	sort(edges.begin(), edges.end());

	to = ta = 0;
	for(int i = 0, a, b; i < m && ta < n - 1; ++i) {
		a = find(edges[i].from);
		b = find(edges[i].to);

		if(a != b) {
			ds[a] = b;
			++ta;
			to += edges[i].cost;
		}
	}

	printf("%d\n", to);

	return 0;
}

