#include <stdio.h>

using namespace std;

int n, a[100001];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);

	int cnt = 1, t = a[0];
	for(int i = 1; i < n; ++i)
		if(a[i] >= t) { ++cnt; t += a[i]; }

	printf("%d\n", cnt);
}
