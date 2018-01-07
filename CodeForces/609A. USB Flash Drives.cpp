#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, a[101], res = 0;
	scanf("%d\n%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	sort(a, a + n);
	reverse(a, a + n);
	for(int i = 0; i < n; ++i) {
		if(m <= 0)
			break;
		m -= a[i];
		++res;
	}
	
	printf("%d\n", res);

	return 0;
}

