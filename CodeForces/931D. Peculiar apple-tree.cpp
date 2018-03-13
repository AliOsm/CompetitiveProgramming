#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int> > g;
queue<int> q;
bool vis[100001];

int BFS(int src) {
	q.push(src);
	vis[src] = true;

	int res = 0;
	while(!q.empty()) {
		int size = q.size();

		if(size & 1)
			++res;

		while(size-- != 0) {
			int fr = q.front();
			q.pop();

			for(int i = 0; i < g[fr].size(); ++i) {
				if(!vis[g[fr][i]]) {
					vis[g[fr][i]] = true;
					q.push(g[fr][i]);
				}
			}
		}
	}

	return res;
}

int main() {
	cin >> n;
	g.resize(n);

	for(int i = 1; i < n; ++i) {
		int tmp;
		cin >> tmp;
		g[--tmp].push_back(i);
	}

	cout << BFS(0) << endl;

	return 0;
}