/*
	Idea:
		- If we define f(X, k) as the number of integers less than X and have
			k 1-bits in the binary representation.
		- We can do a binary search on f(X, k), we can proof that f(X, k) is
			a monoton function.
		- To count the number of integers less than X and have k 1-bits in the
			binary representation we can iterate over the binary representation
			of X and in each 1-bit in X we can set it to 0 and try to put k 1-bits
			after it, we can calculate this value using (i)C(k-cnt) where i is the
			0-index of the 1-bit and cnt is the number of 1-bits before he current
			one.
*/

#include <bits/stdc++.h>

using namespace std;

long long m, k, c[65][65];

long long calc(long long x, int k) {
	long long ret = (__builtin_popcount(x) == k);
	for(int i = 63; i >= 0 && k > 0; --i)
		if(((x >> i) & 1) == 1)
			ret += c[i][k--];
	return ret;
}

long long can(long long mid) {
	return calc(mid * 2, k) - calc(mid, k);
}

int main() {
	for(int i = 0; i <= 64; ++i)
		for(int j = 0; j <= i; ++j)
			if(j == 0 || j == i)
				c[i][j] = 1;
			else
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];

	scanf("%lld %lld", &m, &k);

	if(m == 0) {
		puts("1");
		return 0;
	}

	long long l = 0, r = 2e18, mid, res;
	while(l <= r) {
		mid = (l + r) / 2;
		res = can(mid);
		if(res == m) {
			printf("%lld\n", mid);
			return 0;
		} else if(res > m)
			r = mid - 1;
		else
			l = mid + 1;
	}

  return 0;
}
