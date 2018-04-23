#include <bits/stdc++.h>

using namespace std;

struct node {
	int rRep, len, v;

	node() {}
	node(int rRep, int len, int v) :
	rRep(rRep), len(len), v(v) {}
	
	bool operator<(const node &n) const {
		if(rRep != n.rRep)
			return rRep > n.rRep;
		if(len != n.len)
			return len > n.len;
		return false;
	}
};

int const N = 5e5 + 1;
int m, n, id, lst, rRep[N], len[N], wRep[N];
char s[N];
bool vis[N];
string tmp;
node cur;
map<string, int> mp;
priority_queue<node> q;
vector<vector<int> > g;

void Dijkstra() {
	while(!q.empty()) {
		cur = q.top();
		q.pop();

		if(cur.v < lst && (cur.rRep < rRep[cur.v] ||
											(cur.rRep == rRep[cur.v]) && cur.len < len[cur.v]))
			rRep[cur.v] = cur.rRep, len[cur.v] = cur.len;

		if(vis[cur.v])
			continue;
		vis[cur.v] = true;

		for(int i = 0; i < g[cur.v].size(); ++i) {
			if(rRep[g[cur.v][i]] < cur.rRep ||
				(rRep[g[cur.v][i]] == cur.rRep && len[g[cur.v][i]] < cur.len))
				q.push(node(rRep[g[cur.v][i]], len[g[cur.v][i]], g[cur.v][i]));
			else
				q.push(node(cur.rRep, cur.len, g[cur.v][i]));
		}
	}
}

int main() {
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		scanf("%s", s);
		tmp = s;
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
		if(mp.count(tmp) == 0) {
			mp[tmp] = id;
			for(int j = 0; j < tmp.length(); ++j)
				rRep[id] += (tmp[j] == 'r');
			len[id] = tmp.length();

			++id;
		}
		++wRep[mp[tmp]];
	}
	lst = id;

	g.resize(N);

	scanf("%d", &n);
	for(int i = 0, a, b; i < n; ++i) {
		scanf("%s", s);
		tmp = s;
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
		if(mp.count(tmp) == 0) {
			mp[tmp] = id;
			for(int j = 0; j < tmp.length(); ++j)
				rRep[id] += (tmp[j] == 'r');
			len[id] = tmp.length();

			++id;
		}
		a = mp[tmp];
		q.push(node(rRep[a], len[a], a));

		scanf("%s", s);
		tmp = s;
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
		if(mp.count(tmp) == 0) {
			mp[tmp] = id;
			for(int j = 0; j < tmp.length(); ++j)
				rRep[id] += (tmp[j] == 'r');
			len[id] = tmp.length();

			++id;
		}
		b = mp[tmp];
		q.push(node(rRep[b], len[b], b));

		g[b].push_back(a);
	}

	Dijkstra();

	long long r1 = 0, r2 = 0;
	for(int i = 0; i < lst; ++i) {
		r1 += 1ll * rRep[i] * wRep[i];
		r2 += 1ll * len[i] * wRep[i];
	}

	printf("%lld %lld\n", r1, r2);

  return 0;
}
