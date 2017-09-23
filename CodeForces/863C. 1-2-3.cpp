#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 4;
ll k, a, b, aa[N][N], bb[N][N], ra, rb, tmpa, tmpb, loops, c1, c2;
bool vis[N][N];
vector<int> all;

int main() {
	scanf("%lld %lld %lld", &k, &a, &b);
	for(int i = 1; i < N; ++i)
		for(int j = 1; j < N; ++j)
			scanf("%lld", &aa[i][j]);
	for(int i = 1; i < N; ++i)
		for(int j = 1; j < N; ++j)
			scanf("%lld", &bb[i][j]);

	while(k > 0 && !vis[a][b]) {
		if(a != b) {
			if((a == 3 && b == 2) || (a == 2 && b == 1) || (a == 1 && b == 3))
				++ra;
			else
				++rb;
		}

		vis[a][b] = true;

		tmpa = aa[a][b];
		tmpb = bb[a][b];

		a = tmpa;
		b = tmpb;

		--k;
	}

	if(k > 0) {
		memset(vis, false, sizeof vis);

		while(!vis[a][b]) {
			if(a == b)
				all.push_back(0);
			else if((a == 3 && b == 2) || (a == 2 && b == 1) || (a == 1 && b == 3))
				all.push_back(1);
			else
				all.push_back(2);

			vis[a][b] = true;

			tmpa = aa[a][b];
			tmpb = bb[a][b];

			a = tmpa;
			b = tmpb;
		}

		loops = k / all.size();
		k -= all.size() * loops;
		for(int i = 0; i < (int)all.size(); ++i)
			c1 += all[i] == 1,
			c2 += all[i] == 2;

		ra += (c1 * loops);
		rb += (c2 * loops);

		for(int i = 0; i < k; ++i)
			ra += all[i] == 1,
			rb += all[i] == 2;
	}

	printf("%lld %lld\n", ra, rb);

	return 0;
}

