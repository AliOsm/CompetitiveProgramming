#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int n, m, mn, mx, tmp;
map<int, int> mp1, mp2;

int main() {
	scanf("%d", &n);
	mn = 1e9, mx = -1e9;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		mn = min(mn, tmp);
		mx = max(mx, tmp);
		mp1[tmp]++;
	}

	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d", &tmp);
		mn = min(mn, tmp);
		mx = max(mx, tmp);
		mp2[tmp]++;
	}

	for(int i = mn; i <= mx; ++i)
		if(mp1.count(i) && mp2.count(i) && mp1[i] != mp2[i])
			printf("%d ", i);
	puts("");
}

