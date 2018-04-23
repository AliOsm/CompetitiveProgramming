#include <bits/stdc++.h>

using namespace std;

int const N = 301;
int a[3];
char s[101];
long long dp[N][N][N], res;

long long rec(int idx, int cur, int rem) {
	if(idx == 0)
		return rem == 0;
	if(idx < 0 || cur >= N || rem <= 0)
		return 0;

	long long &ret = dp[idx][cur][rem];
	if(ret != -1)
		return ret;

	return ret = rec(idx - cur, cur, rem - 1) + rec(idx, cur + 1, rem);
}

int main() {
	memset(dp, -1, sizeof dp);
	while(fgets(s, sizeof s, stdin)) {
		stringstream ss(s);
		memset(a, -1, sizeof a);
		for(int i = 0; i < 3 && ss >> a[i]; ++i);

		res = 0;
		if(a[1] == -1) {
			for(int i = 0; i < N; ++i)
				res += rec(a[0], 1, i);
			printf("%lld\n", res);
		} else if(a[2] == -1) {
			if(a[1] > 300)
				a[1] = 300;

			for(int i = 0; i <= a[1]; ++i)
				res += rec(a[0], 1, i);
			printf("%lld\n", res);
		} else {
			if(a[1] > 300)
				a[1] = 300;
			if(a[2] > 300)
				a[2] = 300;

			for(int i = a[1]; i <= a[2]; ++i)
				res += rec(a[0], 1, i);
			printf("%lld\n", res);
		}
	}

  return 0;
}
