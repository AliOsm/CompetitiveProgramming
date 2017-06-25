#include <stdio.h>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int n, m, arr[51];
vector<ll> lcm, lcms;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

ll findLcm() {
	ll res = lcm[0];
	res = (res * lcm[1]) / gcd(res, lcm[1]);
	res = (res * lcm[2]) / gcd(res, lcm[2]);
	res = (res * lcm[3]) / gcd(res, lcm[3]);
	return res;
}

void rec(int i, int j) {
	if(j == 4) { lcms.push_back(findLcm()); return; }
	if(i == n) return;

	lcm.push_back(arr[i]);
	rec(i + 1, j + 1);
	lcm.pop_back();

	rec(i + 1, j);
}

int main() {
	int tmp;
	while(scanf("%d%d", &n, &m) && n != 0 && m != 0) {
		for(int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);

		lcms.clear();
		rec(0, 0);

		for(int i = 0; i < m; ++i) {
			scanf("%d", &tmp);

			ll mn = -1, mx = 2e9 + 1;

			for(int j = 0; j < (int)lcms.size(); ++j) {
				mn = max(mn, lcms[j] * (tmp / lcms[j]));
				mx = min(mx, lcms[j] * (tmp / lcms[j] + 1));

				if(mn == tmp || mx == tmp) {
					mn = mx = tmp;
					break;
				}
			}

			printf("%lld %lld\n", mn, mx);
		}
	}

	return 0;
}

