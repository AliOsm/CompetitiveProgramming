#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	if(a > b)
		swap(a, b);

	if(n == 2) {
		cout << "Final!" << endl;
		return 0;
	}

	vector<int> all;
	for(int i = 1; i <= n; ++i)
		all.push_back(i);

	int res = 1;
	while(!all.empty()) {
		if(all.size() == 2)
			break;

		for(int i = 0; i < all.size(); ++i) {
			if((all[i] == a && all[i + 1] == b) || (all[i] == b && all[i + 1] == a)) {
				cout << res << endl;
				return 0;
			}

			if(all[i] == a) {
				all.erase(all.begin() + i + 1);
			} else if(all[i + 1] == a) {
				all.erase(all.begin() + i);
			} else if(all[i] == b) {
				all.erase(all.begin() + i + 1);
			} else if(all[i + 1] == b) {
				all.erase(all.begin() + i);
			} else {
				all.erase(all.begin() + i);
			}
		}

		++res;
	}

	cout << "Final!" << endl;

	return 0;
}