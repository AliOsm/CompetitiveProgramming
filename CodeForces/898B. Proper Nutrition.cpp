#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n, a, b;

int main() {
	scanf("%d %d %d", &n, &a, &b);

	for(int i = 0; i <= n; ++i)
		if(n - (1ll * a * i) >= 0 && (n - (1ll * a * i)) % b == 0) {
			printf("YES\n%d %d\n", i, (n - (1ll * a * i)) / b);
			return 0;
		}

	puts("NO");

	return 0;
}

