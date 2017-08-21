#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 101;
int n, a[N];
vector<int> all;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < n; ++k)
				all.push_back(a[i] * a[j] + a[k]);

	sort(all.begin(), all.end());

	int res = 0;
	for(int i = 0, s, f, tmp; i < n; ++i)
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < n; ++k)
				if(a[k] != 0) {
					tmp = (a[i] + a[j]) * a[k];
					s = lower_bound(all.begin(), all.end(), tmp) - all.begin();
					f = upper_bound(all.begin(), all.end(), tmp) - all.begin();
					res += f - s;
				}

	printf("%d\n", res);

    return 0;
}

