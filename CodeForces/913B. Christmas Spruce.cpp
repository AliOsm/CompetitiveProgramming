#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n;
vector<vector<int> > g;

int main() {
	scanf("%d", &n);

	g.resize(n);

	for(int i = 1, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		g[--tmp].push_back(i);
	}

	for(int i = 0, cnt; i < n; ++i) {
		cnt = 0;
		if(g[i].empty())
			continue;
		for(int j = 0; j < g[i].size(); ++j)
			if(g[g[i][j]].empty())
				++cnt;
		if(cnt < 3) {
			puts("No");
			return 0;
		}
	}

	puts("Yes");

	return 0;
}
