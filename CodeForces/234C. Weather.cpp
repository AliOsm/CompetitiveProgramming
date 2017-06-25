#include <stdio.h>
#include <algorithm>

typedef long long ll;

using namespace std;

int const N = 1e5 + 1;
int n, a[N], cm_les[N], cm_eq[N], cm_gre[N];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	cm_les[0] = (a[0] < 0);
	cm_eq[0] = (a[0] == 0);
	cm_gre[0] = (a[0] > 0);
	for(int i = 1; i < n; ++i) {
		cm_les[i] = cm_les[i-1] + (a[i] < 0);
		cm_eq[i] = cm_eq[i-1] + (a[i] == 0);
		cm_gre[i] = cm_gre[i-1] + (a[i] > 0);
	}

	int s1, s2, res = 1e9;
	for(int i = 0; i < n - 1; ++i) {
		s1 = cm_eq[i] + cm_gre[i];
		s2 = (cm_eq[n-1] - cm_eq[i]) + (cm_les[n-1] - cm_les[i]);

		res = min(res, s1 + s2);
	}

	printf("%d\n", res);

	return 0;
}

