/*
	Idea:
		- Greedy.
		- Start DFS from node 0 and for each node count the number of nodes in each
			subtree below it.
		- If the number of nodes is even then add 1 to the result.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, res;
bool vis[N];
vector<vector<int> > g;

int DFS(int u) {
	vis[u] = true;

	bool ok = false;
	int ret = 1;
	for(int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];

		if(!vis[v]) {
			int tmp = DFS(v);
			if(tmp % 2 == 0)
				++res;
			ret += tmp;
		}
	}

	return ret;
}

int main() {
 	cin >> n;
 	g.resize(n);
 	for(int i = 0, a, b; i < n-1; ++i) {
 		cin >> a >> b;
 		--a, --b;
 		g[a].push_back(b);
 		g[b].push_back(a);
 	}
 	
 	if(n & 1) {
 		cout << -1 << endl;
 		return 0;
 	}

 	DFS(0);
 	cout << res << endl;

  return 0;
}
