#include <bits/stdc++.h>

using namespace std;

vector<bool> beds1, beds2;
int n, k;

bool check() {
	for(int i = 1; i <= n; ++i)
		if(!beds1[i])
			return true;

	return false;
}

int main() {
	int t;
	cin >> t;

	while(t-- != 0) {
		beds1.clear();
		beds1.resize(202, false);
		beds2.clear();
		beds2.resize(202, false);

		int res = 1;

		cin >> n >> k;

		for(int i = 0, tmp; i < k; ++i) {
			cin >> tmp;
			beds1[tmp] = beds2[tmp] = true;
		}

		while(check()) {
			++res;

			for(int i = 1; i <= n; ++i)
				if(beds1[i - 1] || beds1[i + 1])
					beds2[i] = true;

			for(int i = 1; i <= n; ++i)
				beds1[i] = beds2[i];
		}

		cout << res << endl;
	}

	return 0;
}
