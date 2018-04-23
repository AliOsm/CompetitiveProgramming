#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	if(n <= 5)
		cout << -1 << endl;
	else {
		int cnt = 1, cur = 1;
		while(cnt <= n) {
			if(cnt + 1 <= n)
				cout << cur << ' ' << cnt + 1 << endl;
			++cnt;
			if(cnt + 1 <= n)
				cout << cur << ' ' << cnt + 1 << endl;
			++cnt;
			if(cnt + 1 <= n)
				cout << cur << ' ' << cnt + 1 << endl;
			++cnt;
			cur += 3;
		}
	}

	for(int i = 1; i < n; ++i) {
		cout << i << ' ' << i + 1 << endl;
	}

  return 0;
}
