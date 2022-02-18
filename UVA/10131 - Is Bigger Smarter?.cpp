#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;
int n, dp[N];
vector<int> tmp;
vector<vector<int> > elephants;

int rec(int idx) {
	if(idx == n) {
		return 0;
	}

	int &res = dp[idx];
	if(res != -1) {
		return res;
	}
	res = 0;

	for(int i = idx + 1; i < n; ++i) {
		if(elephants[i][0] > elephants[idx][0] && elephants[i][1] < elephants[idx][1]) {
			res = max(res, rec(i) + 1);
		}
	}

	return res;
}

void path(int idx) {
	printf("%d\n", elephants[idx][2]);

	for(int i = idx + 1; i < n; ++i) {
		if(elephants[i][0] > elephants[idx][0] && elephants[i][1] < elephants[idx][1] && rec(idx) == rec(i) + 1) {
			path(i);
			return;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	tmp.resize(3);
	for(int i = 1; scanf("%d %d", &tmp[0], &tmp[1]) == 2; ++i) {
		tmp[2] = i;
		elephants.push_back(tmp);
	}

	sort(elephants.begin(), elephants.end());
	n = elephants.size();

	memset(dp, -1, sizeof dp);

	int res = 0, bestI = -1;
	for(int i = 0; i < n; ++i) {
		if(rec(i) + 1 > res) {
			res = rec(i) + 1;
			bestI = i;
		}
	}

	printf("%d\n", res);

	path(bestI);

	return 0;
}
