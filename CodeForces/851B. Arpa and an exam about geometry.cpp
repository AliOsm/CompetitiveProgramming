#include <bits/stdc++.h>

using namespace std;

int ax, ay, bx, by, cx, cy;

long long dist(int x1, int y1, int x2, int y2) {
	return (1ll * (x1 - x2) * (x1 - x2)) + (1ll * (y1 - y2) * (y1 - y2));
}

int main() {
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);

	long long ab = dist(ax, ay, bx, by);
	long long ac = dist(ax, ay, cx, cy);
	long long bc = dist(bx, by, cx, cy);

	if((1ll * (1ll * ax * (by - cy)) + (1ll * bx * (cy - ay)) + (1ll * cx * (ay - by)) != 0) && (ab == ac || ab == bc)) {
		puts("YES");
	} else {
		puts("NO");
	}

    return 0;
}
