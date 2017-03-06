#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int q;
	cin >> q;

	for(int i = 0; i < q; i++) {
		int m;
		cin >> m;

		int res = upper_bound(arr.begin(), arr.end(), m) - arr.begin();
		cout << res << endl;
	}

	return 0;
}
