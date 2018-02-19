#include <bits/stdc++.h>

using namespace std;

long long r, x1, y11, x2, y2;
long double u1, u2;

bool can(long double mid) {
	long double r1, r2;
	r1 = x2 + (mid * u1);
	r2 = y2 + (mid * u2);

	long double dist = (x1 - r1) * (x1 - r1) + (y11 - r2) * (y11 - r2);

	if(dist <= r*r)
		return true;
	return false;
}

int main() {
	cin >> r >> x1 >> y11 >> x2 >> y2;

	if(x1 == x2 && y11 == y2) {
		cout << fixed << setprecision(15) << x2 + r / 2.0 << ' ' << y2 << ' ' << r / 2.0 << endl;
		return 0;
	}

	if((x2 - x1) * (x2 - x1) + (y2 - y11) * (y2 - y11) > r*r) {
		cout << x1 << ' ' << y11 << ' ' << r << endl;
		return 0;
	}

	long long v1, v2;
	v1 = x1 - x2;
	v2 = y11 - y2;

	long double len = sqrt(v1*v1+v2*v2);

	u1 = v1 / len;
	u2 = v2 / len;

	long double l = 0, r = 1e10, mid, res;

	for(long long i = 0; i < 100; ++i) {
		mid = (l + r) / 2;
		if(can(mid)) {
			res = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	res /= 2;

	long double r1, r2;
	r1 = x2 + (res * u1);
	r2 = y2 + (res * u2);

	cout << fixed << setprecision(15) << r1 << ' ' << r2 << ' ' << res << endl;

	return 0;
}
