#include <bits/stdc++.h>

using namespace std;

int l[1001], r[1001], res[1001];

int main() {
	int t;
	cin >> t;

	while(t-- != 0) {
		int n;
		cin >> n;

		for(int i = 0; i < n; ++i)
			cin >> l[i] >> r[i];

		int mnt = 1;
		for(int i = 0; i < n; ++i) {
			if(l[i] > mnt)
				mnt = l[i], res[i] = mnt++;
			else if(l[i] <= mnt && r[i] >= mnt)
				res[i] = mnt, ++mnt;
			else
				res[i] = 0;
		}

		for(int i = 0; i < n; ++i)
			cout << res[i] << ' ';
		cout << endl;
	}

	return 0;
}
