#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> a;

int main() {
	scanf("%d %d", &n, &k);
	a.resize(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a.begin(), a.end());

	int res = 0;
	for(int i = 0; i < n; ++i) {
		while(!(k >= a[i] / 2.0))
			k *= 2, ++res;
		k = max(k, a[i]);
	}

	printf("%d\n", res);

	return 0;
}

