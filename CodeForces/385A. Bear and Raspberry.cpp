#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	bool b = true;

	int days, kilos;
	cin >> days >> kilos;

	vector<int> arr(days), res;
	
	for (int i = 0; i < days; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < days; i++) {
		if (i != arr.size() - 1 && arr[i] > arr[i + 1])
			b = false;
	}

	if (b) {
		if (arr[arr.size() - 2] < arr[arr.size() - 1]) {
			cout << 0 << endl;
			return 0;
		}
	}
	
	for (int i = 0; i < days; i++) {
		if (i != arr.size() - 1 && arr[i] >= (arr[i + 1] * 2) + kilos) {
			res.push_back(arr[i] - arr[i + 1] - kilos);
		}
	}

	if (arr[arr.size() - 2] >= (arr[arr.size() - 1] * 2) + kilos) {
		res.push_back(arr[arr.size() - 2] - arr[arr.size() - 1] - kilos);
	}

	if (res.size() > 0) {
		sort(res.begin(), res.end());
		cout << res[res.size() - 1] << endl;
		return 0;
	}

	res.clear();

	for (int i = 0; i < days; i++) {
		if (i != arr.size() - 1 && arr[i] >= (arr[i + 1]) + kilos) {
			res.push_back(arr[i] - arr[i + 1] - kilos);
		}
	}

	if (arr[arr.size() - 2] >= (arr[arr.size() - 1]) + kilos) {
		res.push_back(arr[arr.size() - 2] - arr[arr.size() - 1] - kilos);
	}

	if (res.size() > 0) {
		sort(res.begin(), res.end());
		cout << res[res.size() - 1] << endl;
	}
	else {
		cout << 0 << endl;
	}

	return 0;
}
