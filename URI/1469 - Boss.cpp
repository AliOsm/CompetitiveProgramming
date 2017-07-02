#include <stdio.h>
#include <vector>
#include <bitset>
#include <memory.h>
#include <algorithm>

using namespace std;

struct node {
	int id, age;
	bitset<501> parents;

	node(int id, int age) {
		this->id = id;
		this->age = age;
		parents.reset();
	}
};

int n, m, q;
bool vis[501];
char ch;
vector<node> nodes;

int get_min_age(int x) {
	vis[x] = true;
	int res = 101;
	for(int i = 0; i < n; ++i)
		if(nodes[x].parents[i] && !vis[i])
			res = min(res, min(nodes[i].age, get_min_age(i)));
	return res;
}

int find(int x) {
	for(int i = 0; i < n; ++i)
		if(nodes[i].id == x)
			return i;
	return 0;
}

int main() {
	while(scanf("%d %d %d", &n, &m, &q) != EOF) {
		nodes.clear();

		for(int i = 0, age; i < n; ++i) {
			scanf("%d", &age);
			nodes.push_back(node(i, age));
		}

		for(int i = 0, a, b; i < m; ++i) {
			scanf("%d %d", &a, &b);
			--a, --b;
			nodes[b].parents[a] = 1;
		}

		for(int i = 0, a, b; i < q; ++i) {
			scanf(" %c", &ch);

			if(ch == 'T') {
				scanf("%d %d", &a, &b);
				--a, --b;
				a = find(a);
				b = find(b);
				swap(nodes[a].id, nodes[b].id);
				swap(nodes[a].age, nodes[b].age);
			} else {
				scanf("%d", &a);
				--a;
				a = find(a);
				if(nodes[a].parents.none()) puts("*");
				else {
					memset(vis, false, sizeof vis);
					printf("%d\n", get_min_age(a));
				}
			}
		}
	}

	return 0;
}

