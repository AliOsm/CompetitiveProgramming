#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[101];
queue<int> q;
bool vis[101];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; ++i)
		scanf("%d %d", &a[i].first, &a[i].second);
	sort(a, a + n);

	if(a[0].first != 0) {
		puts("NO");
		return 0;
	}

	q.push(0);
	while(!q.empty()) {
		int fr = q.front();
		q.pop();

		vis[fr] = true;

		if(m >= a[fr].first && m <= a[fr].second) {
			puts("YES");
			return 0;
		}

		for(int i = 0; i < n; ++i)
			if(a[i].first >= a[fr].first && a[i].first <= a[fr].second && !vis[i])
				q.push(i);
	}

	puts("NO");

	return 0;
}
