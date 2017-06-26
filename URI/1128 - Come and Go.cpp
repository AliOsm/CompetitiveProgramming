#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int n, m, low[2001], idx[2001], id, dfs;
bool in[2001];
vector<vector<int> > g;
vector<int> st;

void DFS(int node) {
	low[node] = idx[node] = dfs++;
	in[node] = true;
	st.push_back(node);

	for(int i = 0; i < (int)g[node].size(); ++i)
		if(idx[g[node][i]] == -1) {
			DFS(g[node][i]);
			low[node] = min(low[node], low[g[node][i]]);
		} else if(in[g[node][i]])
			low[node] = min(low[node], low[g[node][i]]);

	if(low[node] == idx[node]) {
		int cur;
		do {
			cur = st.back();
			st.pop_back();
			in[cur] = false;
		} while(cur != node);
		++id;
	}
}

int main() {
	while(scanf("%d %d", &n, &m) && n != 0 && m != 0) {
		g.clear();
		g.resize(n);
		for(int i = 0, a, b, c; i < m; ++i) {
			scanf("%d %d %d", &a, &b, &c);
			--a, --b;
			g[a].push_back(b);
			if(c == 2)
				g[b].push_back(a);
		}

		memset(idx, -1, sizeof idx);
	    	st.clear();
	    	id = dfs = 0;
		for(int i = 0; i < n; ++i)
			if(idx[i] == -1)
				DFS(i);

		if(id == 1)
			puts("1");
		else
			puts("0");
	}

	return 0;
}

