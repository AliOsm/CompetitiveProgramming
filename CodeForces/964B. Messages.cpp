#include <bits/stdc++.h>

using namespace std;

int n, A, B, C, T, a[1001], fr[1001];

int main() {
	cin >> n >> A >> B >> C >> T;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		++fr[a[i]];
	}
	sort(a, a + n);

	long long r1 = A * n, r2 = 0;

	for(int i = 0; i < n; ++i) {
		int diff = T - a[i];
		r2 += A - (B * diff);
	}

	for(int i = 0, cnt = 0; i < T; ++i) {
		cnt += fr[i];
		r2 += (1ll * C * cnt);
	}

	cout << max(r1, r2) << endl;

  return 0;
}
