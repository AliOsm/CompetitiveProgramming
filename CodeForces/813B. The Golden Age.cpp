#include <stdio.h>
#include <cmath>
#include <set>

typedef long long ll;

using namespace std;

ll x, y, l, r;
set<ll> st;

ll p0w(ll n, int p) {
	ll res = 1;

	while(p--) {
		res *= n;
	}

	return res;
}

int main() {
	scanf("%lld%lld%lld%lld", &x, &y, &l, &r);

	int mx_x_pow = log(r) / log(x);
	int mx_y_pow = log(r) / log(y);

	for(int i = 0; i <= mx_x_pow; ++i) {
		ll r1 = p0w(x, i);

		for(int j = 0; j <= mx_y_pow; ++j) {
			ll r2 = p0w(y, j);

			if(r1 + r2 >= l && r1 + r2 <= r)
				st.insert(r1 + r2);
		}
	}

	if(st.empty()) {
		printf("%lld\n", r - l + 1);
	} else {
		ll lst = l - 1, res = 0;
		for(set<ll>::iterator it = st.begin(); it != st.end(); ++it) {
			res = max(res, *it - lst - 1);
			lst = *it;
		}
		res = max(res, r - lst);
		printf("%lld\n", res);
	}

	return 0;
}

