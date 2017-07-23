#include <stdio.h>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <memory.h>

using namespace std;

struct node {
	int x, y, need;
	node(int x, int y, int need) :
		x(x), y(y), need(need) {}
};

queue<pair<int, int> > qu;
map<long long, node> mp[2];
set<long long> st;
int cost;

void add(int x, int y, int idx) {
	long long area = 1LL * x * y;
	if(st.count(area))
		return;
	qu.push(make_pair(x, y));
	mp[idx].insert(make_pair(area, node(x, y, cost)));
	st.insert(area);
}

void BFS(int x, int y, int idx) {
	while(!qu.empty()) qu.pop();
	st.clear();

	qu.push(make_pair(x, y));
	mp[idx].insert(make_pair(1LL * x * y, node(x, y, 0)));
	st.insert(x * y);

	cost = 1;
	int size;
	while(!qu.empty()) {
		size = qu.size();

		while(size--) {
			pair<int, int> fr = qu.front();
			qu.pop();

			if(fr.first % 2 == 0)
				add(fr.first / 2, fr.second, idx);
			else if(fr.second % 2 == 0)
				add(fr.first, fr.second / 2, idx);

			if(fr.first % 3 == 0)
				add(fr.first / 3 * 2, fr.second, idx);
			else if(fr.second % 3 == 0)
				add(fr.first, fr.second / 3 * 2, idx);
		}

		++cost;
	}
}

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	BFS(a, b, 0);
	BFS(c, d, 1);

	cost = 2e9;
	for(map<long long, node>::iterator it = mp[0].begin(); it != mp[0].end(); ++it) {
		map<long long, node>::iterator tmp = mp[1].find(it->first);
		if(tmp != mp[1].end() && it->second.need + tmp->second.need <= cost) {
			cost = it->second.need + tmp->second.need;
			a = it->second.x;
			b = it->second.y;
			c = tmp->second.x;
			d = tmp->second.y;
		}
	}

	if(cost == 2e9) {
		puts("-1");
		return 0;
	}

	printf("%d\n%d %d\n%d %d", cost, a, b, c, d);

	return 0;
}

