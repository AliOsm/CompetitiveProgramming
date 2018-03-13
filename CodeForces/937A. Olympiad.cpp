#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[102];
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	a[n] = 1000;

	int prv = a[0], subs = 0;
	for(int i = 0; i <= n; ++i) {
		if(a[i] != prv) {
			prv = a[i];
			++subs;
		}
	}

	if(a[0] == 0)
		--subs;
	cout << subs << endl;

	return 0;
}
