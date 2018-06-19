/*
	Idea:
		- To make Alice wins we should check two conditions, the first one is
			array a is lexicographically larger than array b or n > m, otherwise
			Alice loses.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m, k, a[N], b[N];

int main() {
	scanf("%d %d %d", &n ,&m, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for(int i = 0; i < m; ++i)
		scanf("%d", b + i);

	sort(a, a + n);
	reverse(a, a + n);
	sort(b, b + m);
	reverse(b, b + m);

	for(int i = 0; i < min(n, m); ++i)
		if(a[i] > b[i]) {
			puts("YES");
			return 0;
		}

	if(n > m)
		puts("YES");
	else
		puts("NO");

	return 0;
}
