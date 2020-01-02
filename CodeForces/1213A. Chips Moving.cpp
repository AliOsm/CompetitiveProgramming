#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	int even = 0, odd = 0;
	for(int i = 0, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		if(tmp % 2 == 0) ++even;
		else ++odd;
	}

	if(even == 0 || odd == 0)
		puts("0");
	else
		printf("%d\n", min(odd, even));

	return 0;
}