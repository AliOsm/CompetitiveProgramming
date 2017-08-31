#include <stdio.h>
#include <algorithm>

using namespace std;

int const N = 2e5 + 1;
int n, k;

struct node {
	int b, a, d;

	bool operator<(const node &n) const {
		return d < n.d;
	}
};

node a[N];

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i].b);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i].a);
		a[i].d = a[i].b - a[i].a;
	}
	sort(a, a + n);

	int res = 0, i = 0;
	for(; i < k; ++i)
		res += a[i].b;
	for(; i < n && a[i].d <= 0; ++i)
		res += a[i].b;
	for(; i < n; ++i)
		res += a[i].a;

	printf("%d\n", res);

    return 0;
}
