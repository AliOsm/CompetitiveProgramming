#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main() {
	scanf("%d %d %d", &n, &m, &k);

	if(k < m)
		printf("%d\n", k);
	else if(k > n)
		printf("%d\n", m - (k - n));
	else
		printf("%d\n", m);

    return 0;
}
