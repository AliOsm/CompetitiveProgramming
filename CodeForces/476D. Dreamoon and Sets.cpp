#include <bits/stdc++.h>

using namespace std;

int n, k, mx;
vector<vector<int> > sol;

int main() {
	scanf("%d %d", &n, &k);

	sol.resize(n);
	for(int i = 0; i < n; ++i) {
		sol[i].push_back(6 * i + 1);
		sol[i].push_back(6 * i + 2);
		sol[i].push_back(6 * i + 3);
		sol[i].push_back(6 * i + 5);
	}

	for(int i = 0; i < sol.size(); ++i)
		for(int j = 0; j < 4; ++j)
			mx = max(mx, sol[i][j] * k);

	printf("%d\n", mx);

	for(int i = 0; i < sol.size(); ++i, puts(""))
		for(int j = 0; j < 4; ++j)
			printf("%s%d", j == 0 ? "" : " ", sol[i][j] * k);

  return 0;
}
