#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int const N = 2e5 + 1;
int n, m, a[N];
char s[N], p[N];
vector<pair<int, char> > tmp;

bool can(int mid) {
	tmp.clear();

	for(int i = mid; i < n; ++i)
		tmp.push_back(make_pair(a[i], s[a[i]]));
	sort(tmp.begin(), tmp.end());

	for(int i = 0, j = 0; i < m; ++i) {
		while(j < (int)tmp.size() && tmp[j].second != p[i])
			++j;

		if(j == (int)tmp.size())
			return false;

		++j;
	}

	return true;
}

int main() {
	scanf("%s %s", s, p);
	n = strlen(s);
	m = strlen(p);
	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		--a[i];
	}

	int l = 0, r = n, mid, res = 0;
	while(l <= r) {
		mid = (l + r) / 2;
		if(can(mid)) {
			l = mid + 1;
			res = mid;
		} else
			r = mid - 1;
	}

	printf("%d\n", res);

    return 0;
}
