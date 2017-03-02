#include <stdio.h>
#include <algorithm>

using namespace std;

int const OO = 1e9;
int floyd[20][20];

int main() {
	int a, b, q;

	for(int c = 1; scanf("%d", &a) == 1; c++) {
		for(int i = 0; i < 20; i++) {
			fill(floyd[i], floyd[i] + 20, OO);
			floyd[i][i] = 0;
		}

		for(int i = 0; i < 19; i++) {
			for(int j = 0; j < a; j++) {
				scanf("%d", &b);
				b--;
				floyd[i][b] = 1;
				floyd[b][i] = 1;
			}
			scanf("%d", &a);
		}

		for(int k = 0; k < 20; k++)
			for(int i = 0; i < 20; i++)
				for(int j = 0; j < 20; j++)
					floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

		q = a;

		printf("Test Set #%d\n", c);

		while(q--) {
			scanf("%d%d", &a, &b);
			a--; b--;

			printf("%2d to %2d: %d\n", a+1, b+1, floyd[a][b]);
		}

		putchar('\n');
	}

	return 0;
}
