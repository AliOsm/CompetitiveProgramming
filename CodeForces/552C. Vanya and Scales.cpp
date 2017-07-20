#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int w, m;
vector<long long> powers, all[2];

void rec(int i, long long sum, int end, int idx) {
	if(i == end) {
		all[idx].push_back(sum);
		return;
	}

	rec(i + 1, sum, end, idx);
	rec(i + 1, sum + powers[i], end, idx);
	rec(i + 1, sum - powers[i], end, idx);
}

int main() {
	scanf("%d %d", &w, &m);

	if(w == 2) {
		puts("YES");
		return 0;
	}

	long long cur = 1, sum = 0;
	do {
		powers.push_back(cur);
		sum += cur;
		cur *= w;
	} while (cur - sum <= m);

	rec(0, 0, powers.size() / 2, 0);
	rec(powers.size() / 2, 0, powers.size(), 1);

	sort(all[0].begin(), all[0].end());

	for(int i = 0; i < (int)all[1].size(); ++i)
		if(binary_search(all[0].begin(), all[0].end(), m + all[1][i])) {
			puts("YES");
			return 0;
		}

	puts("NO");

	return 0;
}

