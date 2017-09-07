#include <bits/stdc++.h>

using namespace std;

int main() {
	int ax, ay, bx, by, cx, cy;
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);

	if((1ll * (by - ay) * (cx - bx)) == (1ll * (cy - by) * (bx - ax)))
		puts("TOWARDS");
	else {
		long long v = (1ll * (bx - ax) * (cy - ay)) - (1ll * (cx - ax) * (by - ay));
		if(v > 0)
			puts("LEFT");
		else
			puts("RIGHT");
	}

	return 0;
}
