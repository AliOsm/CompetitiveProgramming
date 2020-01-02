#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;
int n, k;
map<int, bool> exist;
queue<int> q;
stack<int> res;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d %d", &n, &k);
	for(int i = 0, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		if(exist.count(tmp) > 0 && exist[tmp])
			continue;
		exist[tmp] = true;
		while(q.size() >= k)
			exist[q.front()] = false, q.pop();
		q.push(tmp);
	}
	while(!q.empty())
		res.push(q.front()), q.pop();
	printf("%d\n", int(res.size()));
	while(!res.empty())
		printf("%d ", res.top()), res.pop();
	puts("");

	return 0;
}