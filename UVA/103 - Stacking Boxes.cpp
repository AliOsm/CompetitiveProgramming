#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

int const N = 31;
int dp[N], n, k;
std::vector<std::pair<std::vector<int>, int > > boxes;
std::vector<int> tmp;

int rec(int i) {
	if(i == n) return 0;

	int &ret = dp[i];
	if(ret != -1) return ret;
	ret = 0;

	for(int j = i + 1; j < n; ++j) {
		bool ok = true;
		for(int k = 0; k < ::k; ++k)
			if(boxes[i].first[k] >= boxes[j].first[k]) {
				ok = false;
				break;
			}

		if(ok)
			ret = std::max(ret, rec(j) + 1);
	}

	return ret;
}

void path(int i) {
	if(i == n) return;

	for(int j = i + 1; j < n; ++j) {
		bool ok = true;
		for(int k = 0; k < ::k; ++k)
			if(boxes[i].first[k] >= boxes[j].first[k]) {
				ok = false;
				break;
			}

		if(ok && rec(i) == rec(j) + 1) {
			printf(" %d", boxes[j].second);
			path(j);
			return;
		}
	}
}

int main() {
	int res, indx;
	while(scanf("%d%d", &n, &k) == 2) {
		boxes.clear();
		boxes.resize(n);

		for(int i = 0; i < n; ++i) {
			tmp.clear();
			tmp.resize(k);
			for(int j = 0; j < k; ++j)
				scanf("%d", &tmp[j]);
			std::sort(tmp.rbegin(), tmp.rend());

			boxes[i] = std::make_pair(tmp, i + 1);
		}

		std::sort(boxes.begin(), boxes.end());

		memset(dp, -1, sizeof dp);
		res = 0;
		for(int i = 0; i < n; ++i)
			if(rec(i) + 1 > res) {
				res = rec(i) + 1;
				indx = i;
			}

		printf("%d\n%d", res, boxes[indx].second);
		path(indx);
		puts("");
	}

	return 0;
}

