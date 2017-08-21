#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;

char s[101];
int n, m, dp[101][101][101][51];

int rec(int idx, int a, int b, int cnt, int add, char lst) {
	if(idx == m)
		return cnt == n ? max(a, b) : -1e9;

	if(cnt > n)
		return -1e9;

	int &ret = dp[idx][a][b][cnt];
	if(ret != -1)
		return ret;
	ret = 0;

	int r1, r2;
	if(lst == 'F') {
		r1 = rec(idx + 1, a + add, b - add, cnt, add, s[idx + 1]);
		r2 = rec(idx, a, b, cnt + 1, add, 'T');
	} else {
		r1 = rec(idx + 1, a, b, cnt, -add, s[idx + 1]);
		r2 = rec(idx, a, b, cnt + 1, add, 'F');
	}

	return ret = max(r1, r2);
}

int main() {
	scanf("%s\n%d", s, &n);
	m = strlen(s);
	memset(dp, -1, sizeof dp);
	printf("%d\n", rec(0, 0, 0, 0, 1, s[0]));

	return 0;
}

