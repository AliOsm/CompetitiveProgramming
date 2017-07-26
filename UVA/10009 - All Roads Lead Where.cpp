#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <memory.h>

using namespace std;

int const N = 1e6 + 1;
int n, m;
int parent[N];
bool vis[N];
string a, b;
vector<vector<int> > g;
vector<int> path;
map<string, int> si;
map<int, string> is;
queue<int> q;

void BFS(int src, int dest) {
	memset(parent, -1, sizeof parent);
	memset(vis, false, sizeof vis);
	while(!q.empty()) q.pop();

	q.push(src);
	vis[src] = true;

	while(!q.empty()) {
		int fr = q.front();
		q.pop();

		for(int i = 0; i < (int)g[fr].size(); ++i) {
			int u = g[fr][i];
			if(!vis[u]) {
				parent[u] = fr;
				vis[u] = true;
				q.push(u);
			}
		}
	}
}

void buildPath(int v) {
	path.clear();
	while(v != -1) {
		path.push_back(v);
		v = parent[v];
	}
}

int main() {
	int t;
	cin >> t;
	while(t-- != 0) {
		g.clear();
		g.resize(N);
		si.clear();
		is.clear();

		cin >> n >> m;

		for(int i = 0, cnt = 0; i < n; ++i) {
			cin >> a >> b;

			if(!si.count(a)) {
				si[a] = cnt;
				is[cnt] = a;
				++cnt;
			}

			if(!si.count(b)) {
				si[b] = cnt;
				is[cnt] = b;
				++cnt;
			}

			g[si[a]].push_back(si[b]);
			g[si[b]].push_back(si[a]);
		}

		for(int i = 0; i < m; ++i) {
			cin >> a >> b;
			BFS(si[a], si[b]);
			buildPath(si[b]);
			for(int i = path.size() - 1; i >= 0; --i)
				cout << is[path[i]][0];
			cout << endl;
		}

		if(t != 0)
			cout << endl;
	}

	return 0;
}

