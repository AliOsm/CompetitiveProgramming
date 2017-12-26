#include <bits/stdc++.h>

using namespace std;

struct node {
	int id, num, siz;
	node() {}
	node(int id, int num, int siz) :
		id(id), num(num), siz(siz) {}
	bool operator<(const node &n) const {
		if(n.siz != siz)
			return n.siz < siz;
		return n.id > id;
	}
};

int const N = 2e5 + 1, INF = 1e9 + 1;
int n, a[N], id, res;
vector<node> all;
set<node> st;
map<int, pair<int, int> > nxt, prv;
set<node>::iterator cur, l, r;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	for(int i = 0; i < n;) {
		int j = i;
		for(; j < n && a[j] == a[i]; ++j);
		all.push_back(node(id++, a[i], j - i));
		i = j;
	}

	for(int i = 0; i < (int)all.size(); ++i)
		st.insert(all[i]);

	for(int i = 0; i < (int)all.size() - 1; ++i)
		nxt[all[i].id] = make_pair(all[i + 1].id, all[i + 1].siz);
	nxt[all.back().id] = make_pair(-1, -1);

	for(int i = all.size() - 1; i > 0; --i)
		prv[all[i].id] = make_pair(all[i - 1].id, all[i - 1].siz);
	prv[all.front().id] = make_pair(-1, -1);

	res = 0;
	while(!st.empty()) {
		// cout << st.size() << endl;

		cur = st.begin();

		// cout << "CUR: " << cur->id << ' ' << cur->num << ' ' << cur->siz << endl;
		// cout << prv[cur->id].first << endl;
		// cout << nxt[cur->id].first << endl;

		if(prv[cur->id].first != -1 && nxt[cur->id].first != -1) {
			l = st.lower_bound(node(prv[cur->id].first, INF, prv[cur->id].second));
			r = st.lower_bound(node(nxt[cur->id].first, INF, nxt[cur->id].second));

			// cout << "L: " << l->id << ' ' << l->num << ' ' << l->siz << endl;
			// cout << "R: " << r->id << ' ' << r->num << ' ' << r->siz << endl;

			if(l->num == r->num) {
				id = l->id;

				st.insert(node(id, l->num, l->siz + r->siz));

				if(prv[l->id].first != -1) {
					nxt[prv[l->id].first] = make_pair(id, l->siz + r->siz);
					prv[id] = prv[l->id];
				} else
					prv[id] = make_pair(-1, -1);

				if(nxt[r->id].first != -1) {
					prv[nxt[r->id].first] = make_pair(id, l->siz + r->siz);
					nxt[id] = nxt[r->id];
				} else
					nxt[id] = make_pair(-1, -1);

				st.erase(l);
				st.erase(r);
			} else {
				nxt[l->id] = make_pair(r->id, r->siz);
				prv[r->id] = make_pair(l->id, l->siz);
			}
		} else if(prv[cur->id].first != -1 && nxt[cur->id].first == -1) {
			nxt[prv[cur->id].first] = make_pair(-1, -1);
		} else if(prv[cur->id].first == -1 && nxt[cur->id].first != -1) {
			prv[nxt[cur->id].first] = make_pair(-1, -1);
		}

		st.erase(cur);
		++res;
	}

	printf("%d\n", res);

	return 0;
}
