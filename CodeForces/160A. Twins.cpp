#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t, sum1 = 0, sum2 = 0, c = 0;
	cin >> t;

	vector<int> arr(t);

	for (int i = 0; i < t; i++) {
		cin >> arr[i];
		sum1 += arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = t - 1; i >= 0 && sum2 <= sum1; i--) {
		c++;
		sum2 += arr[i];
		sum1 -= arr[i];
	}

	cout << c << endl;
	return 0;
}
