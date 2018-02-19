#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int res = 0;
	for(int i = 1; i < n; ++i) {
		if((n - i) % i == 0)
			++res;
	}

	cout << res << endl;

	return 0;
}

