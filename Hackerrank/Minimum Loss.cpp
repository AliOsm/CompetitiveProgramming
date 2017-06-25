#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, k;
pair<ll, int> a[200001];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);

	ll res = 1e18;
	for(int i = 1; i < n; ++i)
		if(a[i].second < a[i - 1].second)
			res = min(res, abs(a[i].first - a[i - 1].first));

	printf("%lld\n", res);
}

