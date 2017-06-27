#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int x, y;

	point(int x, int y) :
		x(x), y(y) {}
};

struct edge {
	int from, to, cost;

	edge(int from, int to, int cost) :
		from(from), to(to), cost(cost) {}

	bool operator<(const edge &e) const {
		return cost < e.cost;
	}
};

int n, ta, ds[501];
double to;
vector<edge> edges;
vector<point> points;

int dist(point a, point b) {
	return ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
}

int find(int x) {
	return ds[x] == x ? x : x = find(ds[x]);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t-- != 0) {
		to = ta = 0;
		edges.clear();
		points.clear();

		scanf("%d", &n);

		for(int i = 0, a, b; i < n; ++i) {
			ds[i] = i;
			scanf("%d %d", &a, &b);
			points.push_back(point(a, b));
		}

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(i != j)
					edges.push_back(edge(i, j, dist(points[i], points[j])));
		sort(edges.begin(), edges.end());

		for(int i = 0, a, b; i < (int)edges.size() && ta < n - 1; ++i) {
			a = find(edges[i].from);
			b = find(edges[i].to);

			if(ds[a] != ds[b]) {
				ds[a] = b;
				++ta;
				to += sqrt(edges[i].cost);
			}
		}

		printf("%.2lf\n", to / 100);
	}

	return 0;
}

