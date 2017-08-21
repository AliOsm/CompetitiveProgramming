#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 25;
int n, k, a[N];
long long s, fact[19];
vector<long long> all[2][26];

void rec(int at, int end, long long sum, int exc, int idx) {
	if(at == end) {
		all[idx][exc].push_back(sum);
		return;
	}

	rec(at + 1, end, sum, exc, idx);
	if(sum + a[at] <= s)
		rec(at + 1, end, sum + a[at], exc, idx);
	if(a[at] <= 18 && sum + fact[a[at]] <= s && exc < k)
		rec(at + 1, end, sum + fact[a[at]], exc + 1, idx);
}

int main() {
	fact[0] = 1;
	for(int i = 1; i < 19; ++i)
		fact[i] = fact[i - 1] * i;

	scanf("%d %d %lld", &n, &k, &s);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	rec(0, n / 2, 0, 0, 0);
	rec(n / 2, n, 0, 0, 1);

	for(int i = 0; i < 26; ++i)
		sort(all[0][i].begin(), all[0][i].end());

	pair<vector<long long>::iterator, vector<long long>::iterator> bounds;
	long long res = 0;
	for(int i = 0; i < k + 1; ++i)
		for(int j = 0; j < (int)all[1][i].size(); ++j)
			for(int q = 0; q + i < k + 1; ++q) {
				bounds = equal_range(all[0][q].begin(), all[0][q].end(), s - all[1][i][j]);
				res += bounds.second - bounds.first;
			}

	printf("%lld\n", res);

    return 0;
}

