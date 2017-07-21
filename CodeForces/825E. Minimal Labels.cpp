#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int const N = 1e5 + 1;
int n, m, in[N];
vector<vector<int> > g;
vector<int> sol;
priority_queue<int> q;

int main() {
	scanf("%d %d", &n, &m);
	g.resize(n);
	for(int i = 0, a, b; i < m; ++i) {
		scanf("%d %d", &a, &b);
		--a, --b;
		g[b].push_back(a);
		++in[a];
	}

	for(int i = 0; i < n; ++i)
		if(in[i] == 0)
			q.push(i);

	sol.resize(n);
	int cnt = n - 1;
	while(!q.empty()) {
		int fr = q.top();
		q.pop();
		sol[fr] = cnt--;
		for(int i = 0; i < (int)g[fr].size(); ++i) {
			int node = g[fr][i];
			if(--in[node] == 0)
				q.push(node);
		}
	}

	for(int i = 0; i < (int)sol.size(); ++i)
		printf("%d ", sol[i] + 1);
	puts("");

	return 0;
}

