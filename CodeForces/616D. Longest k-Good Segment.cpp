#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int const N = 5e5 + 1;
int a[N], freq[2 * N];
queue<int> q;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int un = 0, res = 0, r, l;

	for(int i = 0; i < n; i++) {
		if(freq[a[i]]++ == 0)
			un++;

		q.push(a[i]);

		while(!q.empty() && un > m) {
			if(--freq[q.front()] == 0)
				un--;

			q.pop();
		}

		if(res < (int)q.size()) {
			res = q.size();
			l = i - res + 1;
			r = i;
		}
	}

	printf("%d %d\n", l + 1, r + 1);

	return 0;
}
