#include <stdio.h>
#include <memory.h>
#include <queue>

using namespace std;

int from, to;
bool vis[1000001];
queue<int> qu;

int reverse(int x) {
	int tmp = 0;
	while(x != 0) {
		tmp *= 10;
		tmp += x % 10;
		x /= 10;
	}
	return tmp;
}

int BFS() {
	while(!qu.empty()) qu.pop();
	qu.push(from);

	int size, fr, cost = 0;
	while(!qu.empty()) {
		size = qu.size();

		while(size--) {
			fr = qu.front();
			qu.pop();

			if(fr == to)
				return cost;

			if(!vis[fr + 1])
				qu.push(fr + 1);
			vis[fr + 1] = true;

			fr = reverse(fr);
			if(!vis[fr])
				qu.push(fr);
			vis[fr] = true;
		}

		++cost;
	}

	return cost;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t-- != 0 ) {
		scanf("%d %d", &from, &to);
		memset(vis, false, sizeof vis);
		printf("%d\n", BFS());
	}

	return 0;
}

