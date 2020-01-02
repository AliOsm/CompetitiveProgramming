#include <bits/stdc++.h>

using namespace std;

int const N = 6;
long long x1[N], y[N], x2[N], y2[N];

long long intersect_area(int rect1, int rect2, int save) {
	long long max_x = min(x2[rect1], x2[rect2]);
	long long min_x = max(x1[rect1], x1[rect2]);
	long long x_diff = max_x - min_x;

	long long max_y = max(y[rect1], y[rect2]);
	long long min_y = min(y2[rect1], y2[rect2]);
	long long y_diff = min_y - max_y;

	if(x_diff < 0 || y_diff < 0)
		return 0;

	x2[save] = max_x;
	y2[save] = min_y;
	x1[save] = min_x;
	y[save] = max_y;

	return x_diff * y_diff;
}

long long rectangle_area() {
	return (x2[0] - x1[0]) * (y2[0] - y[0]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	for(int i = 0; i < 3; ++i)
		scanf("%lld %lld %lld %lld", x1 + i, y + i, x2 + i, y2 + i);

	long long _01 = intersect_area(0, 1, 3);
	long long _02 = intersect_area(0, 2, 4);
	long long _34 = intersect_area(3, 4, 5);

	if(_01 == rectangle_area() || _02 == rectangle_area())
		puts("NO");
	else if(_01 == 0 || _02 == 0)
		puts("YES");
	else if(_01 + _02 - _34 < rectangle_area())
		puts("YES");
	else
		puts("NO");

	return 0;
}