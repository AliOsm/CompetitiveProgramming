#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N];
string b;

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> b;

	int l = -1e9;
	for(int i = 4; i < n; ++i)
		if(b[i] == '1' && b[i-1] == '0' && b[i-2] == '0' && b[i-3] == '0' && b[i-4] == '0')
			l = max(l, max(a[i], max(a[i-1], max(a[i-2], max(a[i-3], a[i-4])))));

	int r = 1e9;
	for(int i = 4; i < n; ++i)
		if(b[i] == '0' && b[i-1] == '1' && b[i-2] == '1' && b[i-3] == '1' && b[i-4] == '1')
			r = min(r, min(a[i], min(a[i-1], min(a[i-2], min(a[i-3], a[i-4])))));

	cout << l + 1 << ' ' << r - 1 << endl;

	return 0;
}

