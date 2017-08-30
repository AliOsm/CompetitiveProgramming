#include <stdio.h>
#include <cmath>

using namespace std;

struct sausage {
	int x, y, r;
};

int const N = 1e5 + 1;
sausage sausages[N];

long double dist(int x1, int y1, int x2, int y2) {
	return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

int main() {
	int d, r;
	scanf("%d %d", &r, &d);

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%d %d %d", &sausages[i].x, &sausages[i].y, &sausages[i].r);

	int res = 0;
	for(int i = 0; i < n; ++i) {
		double tmp = dist(0, 0, sausages[i].x, sausages[i].y);
		if(tmp - sausages[i].r + 1e-9 >= r - d && tmp + sausages[i].r - 1e-9 <= r)
			++res;
	}

	printf("%d\n", res);

	return 0;
}
