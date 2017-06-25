#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int const N = 100001;
int n, q, l, r, len, k, intervals[N], sparse[N][17];
pair<int, int> animals[N], queries[N];
map<int, int> mp;

void compress() {
	for(int i = 0; i < n; ++i)
		mp[animals[i].first] = 0, mp[animals[i].second] = 0;
	for(int i = 0; i < q; ++i)
		mp[queries[i].first] = 0, mp[queries[i].second] = 0;

	int index = 0;
	for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
		it->second = index++;

	for(int i = 0; i < n; ++i)
		animals[i].first = mp[animals[i].first], animals[i].second = mp[animals[i].second];
	for(int i = 0; i < q; ++i)
		queries[i].first = mp[queries[i].first], queries[i].second = mp[queries[i].second];
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d %d", &animals[i].first, &animals[i].second);

	scanf("%d", &q);
	for(int i = 0; i < q; ++i)
		scanf("%d %d", &queries[i].first, &queries[i].second);

	compress();

	for(int i = 0; i < n; ++i)
		++intervals[animals[i].first], --intervals[animals[i].second + 1];

	int cnt = 0;
	for(int i = 0; i < N; ++i)
		cnt += intervals[i], sparse[i][0] = cnt;

	for(int j = 1; (1 << j) <= N; ++j)
		for(int i = 0; i + (1 << j) - 1 < N; ++i)
			sparse[i][j] = max(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);

	for(int i = 0; i < q; ++i) {
		len = queries[i].second - queries[i].first + 1;
		k = 0;
		while((1 << k) <= len)
			++k;
		--k;
		printf("%d\n", max(sparse[queries[i].first][k],
						   sparse[queries[i].first + len - (1 << k)][k]));
	}
}

