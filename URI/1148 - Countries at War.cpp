#include <stdio.h>
#include <algorithm>

using namespace std;

int const N = 501, oo = 1e9 + 1;
int n, m, q, a, b, c, floyd[N][N];

int main() {
	while(scanf("%d %d", &n, &m) && (n != 0 || m != 0)) {
		for(int i = 0; i < N; ++i) {
			fill(floyd[i], floyd[i] + N, oo);
			floyd[i][i] = 0;
		}

		for(int i = 0; i < m; ++i) {
			scanf("%d %d %d", &a, &b, &c);
			--a, --b;
			floyd[a][b] = c;
			if(floyd[a][b] != oo && floyd[b][a] != oo)
				floyd[a][b] = floyd[b][a] = 0;
		}

		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

		scanf("%d", &q);
		while(q-- != 0) {
			scanf("%d %d", &a, &b);
			--a, --b;
			if(floyd[a][b] == oo)
				puts("Nao e possivel entregar a carta");
			else
				printf("%d\n", floyd[a][b]);
		}
		puts("");
	}

    return 0;
}

