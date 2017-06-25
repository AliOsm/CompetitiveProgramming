#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int n, k, m;
long long dp[51][51][51][2];

enum Color {
	BLACK, WHITE
};

long long rec(int tn, int tk, int tm, int from) {
	if(tk > k || tm > m)
		return 0;

	if(tn == n) {
		if(tk == k)
			return 1;
		else
			return 0;
	}

	long long &ret = dp[tn][tk][tm][from];
	if(ret != -1) return ret;
	ret = 0;

	if(from == BLACK) {
		ret += rec(tn + 1, tk + 1, 1, WHITE);
		ret += rec(tn + 1, tk, tm + 1, BLACK);
	}

	if(from == WHITE) {
		ret += rec(tn + 1, tk, tm + 1, WHITE);
		ret += rec(tn + 1, tk + 1, 1, BLACK);
	}

	return ret;
}

int main() {
	while(scanf("%d%d%d", &n, &k, &m) != EOF) {
		memset(dp, -1, sizeof dp);
		printf("%lld\n", rec(1, 1, 1, BLACK));
	}

	return 0;
}

