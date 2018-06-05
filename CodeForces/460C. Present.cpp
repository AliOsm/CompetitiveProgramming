/*
  Idea:
    - Binary search on the minimum flower length.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m, w, mn, mx, a[N];
long long b[N], c[2 * N + 100];

bool can(long long mid) {
	memset(c, 0, sizeof c);
	long long have = m;
	for(int i = 0; i < n; ++i)
		b[i] = a[i];

	long long add = 0;
	for(int i = 0; i < n; ++i) {
		add += c[i];
		b[i] += add;
		if(b[i] < mid)
			add += mid - b[i], have -= mid - b[i], c[i + w] = -(mid - b[i]);
	}

	return have >= 0;
}

int main() {
  mn = 2e9;
  mx = 0;
  scanf("%d %d %d", &n, &m, &w);
  for(int i = 0; i < n; ++i)
  	scanf("%d", a + i), mn = min(mn, a[i]), mx = max(mx, a[i]);

  long long l = mn, r = mx + m, mid, res = -1;
  while(l <= r) {
  	mid = (l + r) / 2;
  	if(can(mid))
  		res = mid, l = mid + 1;
  	else
  		r = mid - 1;
  }

  printf("%lld\n", res);

  return 0;
}
