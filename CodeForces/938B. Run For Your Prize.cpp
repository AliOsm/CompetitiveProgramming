#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	long long res = 1e18;
	for(int i = 0; i < n - 1; ++i)
		res = min(res, 1ll * max(a[i] - 1, 1000000 - a[i + 1]));

	res = min(res, 1ll * a[n - 1] - 1);
	res = min(res, 1ll * 1000000 - a[0]);

	cout << res << endl;

	return 0;
}
