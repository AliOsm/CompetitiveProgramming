#include <iostream>

using namespace std;

const int N = 1e5 + 1;
long long n, k;
int a[N], b[N];

bool can(long long mid) {
	long long m = k;

	for(int i = 0; i < n; i++) {
		long long need = (long long) a[i] * mid - b[i];

		if(need < 0)
			continue;

		m -= need;

		if(m < 0)
			return false;
	}

	return true;
}

int main() {
	cin >> n >> k;

	for(int i = 0 ; i < n; i++)
		cin >> a[i];

	for(int i = 0 ; i < n; i++)
		cin >> b[i];

	long long l = 0, r = 2e9, res = 0;

	while(l <= r) {
		int mid = (l + r) / 2;
		if(can(mid)) {
			l = mid + 1;
			res = mid;
		} else
			r = mid - 1;
	}

	cout << res << endl;

	return 0;
}