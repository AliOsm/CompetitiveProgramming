#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	int x, n, m, a, b, tmp;
	bool g[50][50];
	while(t-- != 0) {
		scanf("%d", &x);
		scanf("%d %d", &n, &m);

		memset(g, false, sizeof g);
		tmp = 0;
		for(int i = 0; i < m; ++i) {
			scanf("%d %d", &a, &b);
			if(g[min(a, b)][max(a, b)] == false) {
				g[min(a, b)][max(a, b)] = true;
				++tmp;
			}
		}

		printf("%d\n", tmp * 2);
	}

	return 0;
}

