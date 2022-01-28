#include <bits/stdc++.h>
 
using namespace std;
 
int const OO = 1e9 + 7;
int const N = 1e6 + 1;
int n, dp[N];
 
int rec(int rem) {
	if(rem == 0) {
		return 1;
	}
 
	if(rem < 0) {
		return 0;
	}
 
	int &res = dp[rem];
	if(res != -1) {
		return res;
	}
	res = 0;
 
	for(int i = 1; i <= 6; ++i) {
		res = (res + rec(rem - i)) % OO;
	}
 
	return res % OO;
}
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
 
	scanf("%d", &n);
 
	memset(dp, -1, sizeof dp);
 
	printf("%d\n", rec(n) % OO);
 
	return 0;
}

