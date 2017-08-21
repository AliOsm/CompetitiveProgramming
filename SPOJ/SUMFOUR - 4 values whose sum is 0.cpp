#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 2501;
int n, a[N], b[N], c[N], d[N];
vector<int> all;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d %d %d %d", a + i, b + i, c + i, d + i);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			all.push_back(a[i] + b[j]);

	sort(all.begin(), all.end());

	pair<vector<int>::iterator, vector<int>::iterator> bounds;
	int res = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			int tmp = -(c[i] + d[j]);
			bounds = equal_range(all.begin(), all.end(), tmp);
			res += bounds.second - bounds.first;
		}

	printf("%d\n", res);

    return 0;
}

