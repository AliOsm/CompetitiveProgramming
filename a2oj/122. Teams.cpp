#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t-- != 0) {
		int a, b;
		scanf("%d %d", &a, &b);
		int gcd = __gcd(a, b);
		printf("%d %d\n", gcd, (a / gcd) * (b / gcd));
	}

    	return 0;
}

