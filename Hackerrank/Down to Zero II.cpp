#include <stdio.h>
#include <memory.h>
#include <queue>

using namespace std;

typedef long long ll;

bool vis[1000001];
queue<int> q;

int BFS(int src) {
	while(!q.empty()) q.pop();
	q.push(src);

	int size, cost = 0;
	while(!q.empty()) {
		size = q.size();

		while(size-- != 0) {
			int fr = q.front();
			q.pop();

			if(vis[fr]) continue;
			vis[fr] = true;

			if(fr == 0) return cost;

			q.push(fr - 1);

			for(int i = 2; i * i <= fr; ++i)
				if(fr % i == 0)
					q.push(max(i, fr / i));
		}

		++cost;
	}

	return cost;
}

int main() {
	int q, n;
	scanf("%d", &q);
	while(q-- != 0) {
		scanf("%d", &n);

		memset(vis, false, sizeof vis);
		printf("%d\n", BFS(n));
	}
}

