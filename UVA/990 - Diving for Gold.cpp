#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int t, w, n, dp[1001][31];
pair<int, int> treasures[31];
vector<int> sol;

int rec(int time, int index) {
	if(time < 0)
		return -1e5;

	if(index == n)
		return 0;

	int &ret = dp[time][index];
	if(ret != -1) return ret;
	ret = 0;

	int r1, r2;

	r1 = rec(time - (3 * w * treasures[index].first), index + 1) + treasures[index].second;
	r2 = rec(time, index + 1);

	return ret = max(r1, r2);
}

void build_path(int time, int index) {
	if(time < 0)
		return;

	if(index == n)
		return;

	if(rec(time, index) == rec(time - (3 * w * treasures[index].first), index + 1) + treasures[index].second) {
		sol.push_back(index);
		build_path(time - (3 * w * treasures[index].first), index + 1);
	} else {
		build_path(time, index + 1);
	}
}

int main() {
	bool blankline = false;
	while(scanf("%d %d", &t, &w) != EOF) {
		if(blankline) puts("");
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d %d", &treasures[i].first, &treasures[i].second);

		memset(dp, -1, sizeof dp);
		printf("%d\n", rec(t, 0));

		sol.clear();
		build_path(t, 0);

		printf("%d\n", (int)sol.size());
		for(int i = 0; i < (int)sol.size(); ++i)
			printf("%d %d\n", treasures[sol[i]].first, treasures[sol[i]].second);
		blankline = true;
	}

	return 0;
}

